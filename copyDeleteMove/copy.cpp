//		Необходимо создать следующий набор программ :
//
//			1. Программа для копирования каталогов(копируются все вложенные папки и файлы).
//			2. Программа для перемещения каталогов(перемещаются все вложенные папки и файлы).
//			3. Программа для удаления каталогов(удаляются все вложенные папки и файлы).
//
//		В том случае, если у удаляемого файла(каталога) установлен атрибут Read - Only, необходимо вывести следующее меню : 		
//			1. Удалять ?	2. Пропустить ?		3.Удалять для всех ?	 4. Отмена ?
//
//		Для функций копирования и перемещения выполнить те же действия : 
//			1. Перезаписать ?	2. Пропустить ?		3. Перезаписывать для всех ?	4. Отмена ?
//
//		Параметры программы передаются через командную строку.Например,
//		• copy.exe c : \A d : \B
//		• move.exe c : \A d : \B
//		• delete.exe c : \A

#include<iostream>
#include <direct.h>
#include <io.h>       
#include <windows.h>
#include <stdio.h>
using namespace std;

const size_t n = 100;
void FilesTreatment(char* Out, char* In, const size_t n);
void File_Treat(char* tempPathOut, char* tempPathIn, char* Out, _finddata_t * fileinfo, int& flag);
bool СopyFile(char* pathOUT, char* pathIN, _finddata_t* fileinfo);

int main(int argc, char* argv[])
{
	system("cls");
	if (argc == 3)
		FilesTreatment(argv[1], argv[2], n);
	else cout << "argc != 3.\n";
	system("pause");
	return 0;
}

void FilesTreatment(char* Out, char* In, const size_t n)
{
	int mDir = _mkdir(In);
	char* pathOut = new char[n + 1];
	strcpy_s(pathOut, n + 1, Out);
	strcat_s(pathOut, n + 1, "\\");
	char* pathIn = new char[n + 1];
	strcpy_s(pathIn, n + 1, In);
	strcat_s(pathIn, n + 1, "\\");
	char* mask = new char[n + 5];
	strcpy_s(mask, n + 5, Out);
	strcat_s(mask, n + 5, "\\*");
	_finddata_t* fileinfo = new _finddata_t;
	long done = _findfirst(mask, fileinfo);
	int MayWeWork = done;
	size_t count = 0;
	int flag = 0;
	while (MayWeWork != -1)
	{
		count++;
		AnsiToOem(fileinfo->name, fileinfo->name);
		char* tempPathOut = new char[n + 1];
		strcpy_s(tempPathOut, n + 1, pathOut);
		strcat_s(tempPathOut, n + 1, fileinfo->name);
		char* tempPathIn = new char[n + 1];
		strcpy_s(tempPathIn, n + 1, pathIn);
		strcat_s(tempPathIn, n + 1, fileinfo->name);

		if ((fileinfo->attrib&_A_SUBDIR) && strcmp(fileinfo->name, ".") && strcmp(fileinfo->name, "..")){
				cout << tempPathOut << "\t" << tempPathIn << "\n";
				if (mDir != -1)
					FilesTreatment(tempPathOut, tempPathIn, n);
		}
		if (!(fileinfo->attrib&_A_SUBDIR))
			File_Treat(tempPathOut, tempPathIn, Out, fileinfo, flag);
		
		delete[]tempPathOut;
		delete[]tempPathIn;
		cout << count << " " << fileinfo->name << "\n\n";
		MayWeWork = _findnext(done, fileinfo);
	}
	_findclose(done);
	delete fileinfo;
	delete[]pathOut;
	delete[]pathIn;
	delete[]mask;
}

void File_Treat(char* tempPathOut, char* tempPathIn, char* Out, _finddata_t* fileinfo, int& flag)
{
	if (flag == 0){
		char ch = '1';
		if ((fileinfo->attrib & _A_RDONLY) != 0) {
			do{
				cout << "The file \"" << fileinfo->name << "\" is only for reading. \n";
				cout << " 1-Perform a copying of this file.\n 2-Cancel a copying of this file.\n 3-Perform copying of all files in the folder.\n 4-Cancel copying of all files in the folder.\n";
				cin >> ch;
			} while (ch != '1' && ch != '2' && ch != '3' && ch != '4');
		}
		switch (ch)	{
		case'1':
			СopyFile(tempPathOut, tempPathIn, fileinfo);
			break;
		case'2':
			return;
		case'3':
			СopyFile(tempPathOut, tempPathIn, fileinfo);
			flag = 1;
			break;
		case'4':
			flag = -1;
			break;
		}
		return;
	}
	if (flag == 1){
		СopyFile(tempPathOut, tempPathIn, fileinfo);
		return;
	}
	else return;
}

bool СopyFile(char* pathOUT, char* pathIN, _finddata_t* fileinfo)
{
	const size_t size = 65536;
	FILE* ptr1;
	if (!(ptr1 = fopen(pathOUT, "rb"))){
		cout << pathOUT << "\n" << "File can not be opened.\n";
		return false;
	}
	int handle = _fileno(ptr1);
	char* data = new char[size];
	if (!data)
		return false;
	FILE* ptr2;
	if (!(ptr2 = fopen(pathIN, "wb"))){
		delete[]data;
		return false;
	}
	int realsize;
	while (!feof(ptr1)){
		realsize = fread(data, sizeof(char), size, ptr1);
		fwrite(data, sizeof(char), realsize, ptr2);
	}
	fclose(ptr1);
	fclose(ptr2);
	return true;
}