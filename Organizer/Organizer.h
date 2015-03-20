#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include <time.h>

#include"Exception.h"

class Organizer{
	std::multimap<time_t, std::string> dataBase;

	void option(char ch);
	void addException();
	void add();
	void ereaseException();
	void erease();
	void redactException();
	void redact();
	void show();
	void saveException();
	void save();
	void parseException();
	void parse();
	void inputTime(struct tm& timeinfo);

public:
	Organizer();
	~Organizer();
	void menu();
};

