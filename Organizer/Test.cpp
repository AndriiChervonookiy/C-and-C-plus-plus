//	�������� ���������, ����������� ����������� ����������.
//	����������� ����������� ����������, ��������, �������������� � �������� ������.
//	������������� ��������� ���� ��������� ������.

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

