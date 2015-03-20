//		���������� ������� ��������� ����� �������� :
//
//			1. ��������� ��� ����������� ���������(���������� ��� ��������� ����� � �����).
//			2. ��������� ��� ����������� ���������(������������ ��� ��������� ����� � �����).
//			3. ��������� ��� �������� ���������(��������� ��� ��������� ����� � �����).
//
//		� ��� ������, ���� � ���������� �����(��������) ���������� ������� Read - Only, ���������� ������� ��������� ���� : 		
//			1. ������� ?	2. ���������� ?		3.������� ��� ���� ?	 4. ������ ?
//
//		��� ������� ����������� � ����������� ��������� �� �� �������� : 
//			1. ������������ ?	2. ���������� ?		3. �������������� ��� ���� ?	4. ������ ?
//
//		��������� ��������� ���������� ����� ��������� ������.��������,
//		� copy.exe c : \A d : \B
//		� move.exe c : \A d : \B
//		� delete.exe c : \A

#include<iostream>
#include <direct.h>
#include <io.h>       
#include <windows.h>
#include <stdio.h>
using namespace std;

const size_t n = 50;
void FilesTreatment(char* Out, char* In, const size_t n);
void File_Treat(char* tempPathOut, char* tempPathIn, char* Out, _finddata_t * fileinfo, int& flag);

int main(int argc, char* argv[])
{
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
	if(flag != -1) 
		_rmdir(Out);
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
				cout << " 1-Perform a movement of this file.\n 2-Cancel a movement of this file.\n 3-Perform movements of all files in the folder.\n 4-Cancel movements of all files in the folder.\n";
				cin >> ch;
			} while (ch != '1' && ch != '2' && ch != '3' && ch != '4');
		}
		switch (ch)	{
		case'1':
			rename(tempPathOut, tempPathIn);
			break;
		case'2':
			return;
		case'3':
			rename(tempPathOut, tempPathIn);
			flag = 1;
			break;
		case'4':
			flag = -1;
			break;
		}
		return;
	}
	if (flag == 1){
		rename(tempPathOut, tempPathIn);
		return;
	}
	else return;
}

