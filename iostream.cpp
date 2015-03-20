//	1 задача - Работа с числовыми файлами
//	Создать файл данных соответствующих условию.
//	решить задачу с использыванием данных создание файла.
//	предусмотреть процедуру просмотр на экране дисплея.
//
//	УСЛОВИЕ:
//	Дан файл f, компоненты которого являются целыми числами.
//	Получить в файле g все нечетные числа, входящие в файл f.
//	Числа в файле g должны следовать в порядке возростания!

#include<iostream>
#include<fstream>
#include<time.h>
#include<string>
#include<queue>
#include<vector>        

void createFile(char* name, size_t elementQuantity);
std::string readFile(std::string& name, std::string& buff);
std::vector<int> parse(std::string& buff, std::vector<int>& data);
std::vector<int> selection(std::vector<int>& old);
std::vector<int> sort(std::vector<int>& data);
void writeToFile(std::string& name, std::vector<int>& data);

int main(){
	size_t n = 21;
	createFile("f.txt", n);									// creating file

	std::string buff;
	std::string nameFileOut("f.txt");
	readFile(nameFileOut, buff);							// reading file
	std::cout << buff << std::endl;	
	
	std::vector<int> vecIntData;
	parse(buff, vecIntData);								// parsing string

	vecIntData = selection(vecIntData);						// selecting data

	vecIntData = sort(vecIntData);							// sortting data

	std::string nameFileIn("g.txt");
	writeToFile(nameFileIn, vecIntData);					// writing to file

	system("pause");
	return 0;
}

void createFile(char* name, size_t elementQuantity){
	std::ofstream fout(name, std::ios_base::out | std::ios_base::trunc);
	if (!fout.is_open()) 
		std::cout << "Файл не может быть открыт!\n";

	srand(time(NULL));
	std::string str(4, ' ');
	for (size_t i = 0; i < elementQuantity; ++i){
		int x = rand() % 100;
		str = std::to_string(x) + ",";
		fout << str;
	}
	fout.close();
}

std::string readFile(std::string& name, std::string& buff){
	std::ifstream fin("f.txt", std::ios_base::in);
	if (!fin.is_open()) 
		std::cout << "The file \"f.txt\" can not be open!\n";
	else{
		fin >> buff;
		fin.close();
	}
	return buff;
}

std::vector<int> parse(std::string& buff, std::vector<int>& data){
	size_t size = buff.length();
	std::string temp(3, ' ');
	size_t s = 0;
	for (size_t j = 0;; ++j){
		size_t i = 0;
		for (i = 0;; ++i){
			if (buff[s] == '\0'){
				temp[i] = '\0';
				s++;
				break;
			}
			if (buff[s] == ','){
				temp[i] = '\0';
				s++;
				break;
			}
			temp[i] = buff[s];
			s++;
		}
		if (s > size) break;
		data.push_back(stoi(temp));
	}
	return data;
}

std::vector<int> selection(std::vector<int>& old){
	size_t sizeData = old.size();
	std::vector<int> temp(sizeData);
	size_t j = 0;
	for (size_t i = 0; i < sizeData; ++i)
		if (old[i] % 2 != 0){
			temp[j] = old[i];
			j++;
		}
	sizeData = j;
	temp.resize(sizeData);
	std::cout << std::endl;
	for (size_t i = 0; i < temp.size(); ++i)
		std::cout << temp.at(i) << ",";
	std::cout << std::endl;
	return temp;
}

std::vector<int> sort(std::vector<int>& data){

	std::priority_queue<int> queIntSort;
	for (size_t i = 0; i < data.size();++i)
		queIntSort.push(data[i]);

	std::vector<int> temp(queIntSort.size());

	size_t i = queIntSort.size() - 1;
	while (!queIntSort.empty())
	{
		temp.at(i) = queIntSort.top();
		queIntSort.pop();
		--i;
	}
	return temp;
}

void writeToFile(std::string& name, std::vector<int>& data){
	std::ofstream fout(name, std::ios_base::out | std::ios_base::trunc);
	std::cout << std::endl;
	std::string str;
	for (size_t i = 0; i < data.size(); ++i){
		str = std::to_string(data[i]) + ",";
		fout << str;
		std::cout << str;
	}
	fout.close();
	std::cout << std::endl;
}