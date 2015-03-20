//	Напишите программу, сравнивающую время сортировки элементов контейнера
//	посредством метода list::sort() и алгоритма std::sort().
//	Сделайте соответствующие выводы.

/////////////////////////////////////////////////////////////////////////////////
//
//		Result of experiment :  
//			sort by  method std::sort() (#include <algorithm>) is more fast than
//			sort by method list::sort() (#include<list>)
//
/////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<time.h>
#include<list>   
#include<vector>
#include <chrono>
#include <algorithm>

void creatingContainer(std::vector<int>& container, size_t elementQuantity);
double sortList(std::list<int>& container);
double sortAlg(std::vector<int>& container);

bool myfunction(int i, int j) { return (i<j); }

int main(){
	for (int i = 0; i < 10; ++i){
		size_t n = 7777;
		std::vector<int> contVector;
		creatingContainer(contVector, n);
		std::list<int> contList;
		for (int j = 0; j < contVector.size(); ++j)
			contList.push_front(contVector[contVector.size() - 1 - j]);	

		//for (std::list<int>::iterator it = contList.begin(); it != contList.end(); ++it)
		//	std::cout << *it << " ";
		//std::cout << std::endl;

		double timeAlg = sortAlg(contVector);
		double timeList = sortList(contList);
		double x = timeList - timeAlg;
		std::cout << "(sortList) " << timeList << " - (sortAlg) " << timeAlg << " = " << x << " seconds" << std::endl;
	}

	system("pause");
	return 0;
}

void creatingContainer(std::vector<int>& container, size_t elementQuantity){
	srand(time(NULL));
	for (size_t i = 0; i < elementQuantity; ++i){
		int x = rand() % 100;
		container.push_back(x);
//		std::cout << x << " ";
	}
	std::cout << std::endl << std::endl;
}

double sortList(std::list<int>& container) {
	using namespace std::chrono;

	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	container.list::sort();
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

	//std::cout << "list" << std::endl;
	//for (std::list<int>::iterator it = container.begin(); it != container.end(); ++it)
	//	std::cout << *it << " ";
	//std::cout << std::endl;

	return time_span.count();
}

double sortAlg(std::vector<int>& container) {
	using namespace std::chrono;

	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	std::sort(container.begin(), container.end());
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
	
	//std::cout << "vector"<< std::endl;
	//for (std::vector<int>::iterator it = container.begin(); it != container.end(); ++it)
	//std::cout << *it << " ";
	//std::cout << std::endl;

	return time_span.count();
}