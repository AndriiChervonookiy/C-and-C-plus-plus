#define _CRT_SECURE_NO_WARNINGS
#include"Organizer.h"

Organizer::Organizer(){};

Organizer::~Organizer(){};

void Organizer::menu(){
	using namespace std;
	char ch;
	do{
		do{
			system("cls");
			time_t rawtime;
			time(&rawtime);
			cout << ctime(&rawtime) << " => " << "Wellcome! \n" << "\n";
			cout << "Please, set: \n";
			cout << "1-to add a reminder; \n";
			cout << "2-to delete a reminder; \n";
			cout << "3-to redact a reminder; \n";
			cout << "4-to show all reminders; \n";
			cout << "5-to save to file; \n";
			cout << "6-to read from file; \n";
			cout << "7-to exit. \n";
			cin >> ch;
		} while (ch != '0' && ch != '1' && ch != '2' && ch != '3' && ch != '4' && ch != '5' && ch != '6' && ch != '7');
		option(ch);
		system("pause");
	} while (ch != '7');
}

void Organizer::option(char ch){
	switch (ch){
	case '1':
		addException();
		break;
	case '2':
		ereaseException();
		break;
	case '3':
		redactException();
		break;
	case '4':
		show();
		break;
	case '5':
		saveException();
		break;
	case '6':
		parseException();
		break;
	case '7': return;
	default:
		std::cout << "error\n";
		break;
	}
}

void Organizer::addException(){
	char contin = '0';
	do{
		try{
			add();
		}
		catch (Exception e){
			do{
				std::cout << e.getMessage() << "\n";
				std::cout << "Would you like to add date again? 1-yes, 0-no.";
				std::cin >> contin;
			} while (contin != '1' && contin != '0');
			if (contin == '0') break;
		}
	} while (contin == '1');
}

void Organizer::add(){
	using namespace std;
	time_t temp;
	time(&temp);
	struct tm* timeinfo;
	timeinfo = localtime(&temp);

	inputTime(*timeinfo);
	temp = mktime(timeinfo);
	if (temp == -1) throw Exception("Date is not wrong.");

	fflush(stdin);
	string message = "";
	cout << "Input text for reminder:\n>";
	getline(cin, message);

	multimap<time_t, string> ::iterator it = dataBase.begin();
	dataBase.insert(pair<time_t, string>(temp, message));
}

void Organizer::inputTime(struct tm& timeinfo){
	using namespace std;
	size_t y, m, d, h, minutes;

	cout << "Input year (1970-3000) : ";
	cin >> y;
	timeinfo.tm_year = y - 1900;

	cout << "Input month (1-12): ";
	cin >> m;
	if (m < 1 || m > 12) throw Exception("Month is wrong.");
	timeinfo.tm_mon = m - 1;

	cout << "Input day (1-31): ";
	cin >> d;
	if (d < 1 || d > 31) throw Exception("Day is wrong.");
	timeinfo.tm_mday = d;

	cout << "Input hour (0-24): ";
	cin >> h;
	if (h > 24) throw Exception("Hour is wrong.");
	timeinfo.tm_hour = h;

	cout << "Input min (0-60): ";
	cin >> minutes;
	if (minutes > 60) throw Exception("Minutes are wrong.");
	timeinfo.tm_min = minutes;

	timeinfo.tm_sec = 0;
}

void Organizer::show(){
	std::multimap<time_t, std::string> ::iterator it = dataBase.begin();
	if (dataBase.size() == 0){
		std::cout << "Organizer is empty. \n";
	}
	else{
		for (it = dataBase.begin(); it != dataBase.end(); ++it)
			std::cout << ctime(&it->first) << " => " << it->second << "\n";
		std::cout << "\n\n";
	}
}

void Organizer::ereaseException(){
	char contin = '0';
	do{
		try{
			erease();
		}
		catch (Exception e){
			do{
				std::cout << e.getMessage() << "\n";
				std::cout << "Would you like to erease date again? 1-yes, 0-no.";
				std::cin >> contin;
			} while (contin != '1' && contin != '0');
			if (contin == '0') break;
		}
	} while (contin == '1');
}

void Organizer::erease(){
	if (dataBase.size() == 0){
		std::cout << "Organizer is empty. \n";
		return;
	}
	std::cout << "Input time to erease a reminder\n";

	time_t temp;
	time(&temp);
	struct tm* timeinfo;
	timeinfo = localtime(&temp);

	inputTime(*timeinfo);
	temp = mktime(timeinfo);

	std::multimap<time_t, std::string>::iterator it = dataBase.find(temp);
	if (it == dataBase.end()) throw Exception("This element is not found.");

	dataBase.erase(it);
	std::cout << temp << "\n";
}

void Organizer::redactException(){
	char contin = '0';
	do{
		try{
			redact();
		}
		catch (Exception e){
			do{
				std::cout << e.getMessage() << "\n";
				std::cout << "Would you like to redact date again? 1-yes, 0-no.";
				std::cin >> contin;
			} while (contin != '1' && contin != '0');
			if (contin == '0') break;
		}
	} while (contin == '1');
}

void Organizer::redact(){
	if (dataBase.size() == 0){
		std::cout << "Organizer is empty. \n";
		return;
	}
	std::cout << "Input time to redact a reminder\n";

	time_t temp;
	time(&temp);
	struct tm* timeinfo;
	timeinfo = localtime(&temp);

	inputTime(*timeinfo);
	temp = mktime(timeinfo);

	std::multimap<time_t, std::string>::iterator it = dataBase.find(temp);
	if (it == dataBase.end()) throw Exception("This element is not found.");

	fflush(stdin);
	std::string message = "";
	std::cout << "Input new text for reminder:\n>";
	getline(std::cin, message);

	it->second = message;
}

void Organizer::saveException(){
	char contin = '0';
	do{
		try{
			save();
		}
		catch (Exception e){
			do{
				std::cout << e.getMessage() << "\n";
				std::cout << "Would you like to save date again? 1-yes, 0-no.";
				std::cin >> contin;
			} while (contin != '1' && contin != '0');
			if (contin == '0') break;
		}
	} while (contin == '1');
}

void Organizer::save(){
	std::ofstream fout("file.txt", std::ios_base::out | std::ios_base::trunc);
	if (!fout.is_open()) throw Exception("File can not be open.");
	std::string str = "{\n";
	size_t i = 0, sizeOrganizer = dataBase.size();
	std::multimap<time_t, std::string> ::iterator it = dataBase.begin();
	for (it = dataBase.begin(); it != dataBase.end(); ++it){
		str = str + "\t" + ctime(&it->first) + "\t\"" + std::to_string(it->first) + "\":\"" + it->second + "\"";
		if (i < sizeOrganizer - 1) str = str + ", ";
		str = str + "\n\n";
		i++;
	}
	str = str + "}";
	fout << str;
	fout.close();
}

void Organizer::parseException(){
	char contin = '0';
	do{
		try{
			parse();
		}
		catch (Exception e){
			do{
				std::cout << e.getMessage() << "\n";
				std::cout << "Would you like to read and parse date again? 1-yes, 0-no.";
				std::cin >> contin;
			} while (contin != '1' && contin != '0');
			if (contin == '0') break;
		}
	} while (contin == '1');
}

void Organizer::parse(){
	std::cout << "\n";
	std::ifstream fin("file.txt");
	if (!fin.is_open()) throw Exception("File can not be open.");
	else{
		std::string buff1, buff2;
		char c;
		size_t k;
		do{
			k = 0;
			buff1 = buff2 = "";
			do{
				c = fin.get();
				if (c == '"') k++;
				if (k == 1) buff1 = buff1 + c;
				if (k == 3) buff2 = buff2 + c;
				if (c == '}') break;
			} while (k < 4);
			if (c == '}') break;
			buff1.erase(0, 1);
			buff2.erase(0, 1);
			unsigned long long x = std::stoull(buff1);
			std::multimap<time_t, std::string> ::iterator it = dataBase.begin();
			dataBase.insert(std::pair<time_t, std::string>(x, buff2));
		} while (fin.good());
		fin.close();
	}
}