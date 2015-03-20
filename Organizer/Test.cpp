//	Написать программу, реализующую электронный органайзер.
//	Реализовать возможности добавления, удаления, редактирования и хранения данных.
//	Предусмотреть обработку всех возможных ошибок.

#include"Organizer.h"

namespace myspace
{
	Organizer myOrganizer;
}

int main(){

	try{
		myspace::myOrganizer.menu();
	}

	catch (...) {
		std::cout << "Unknown error\n";
	}

	system("pause");
	return 0;
}

