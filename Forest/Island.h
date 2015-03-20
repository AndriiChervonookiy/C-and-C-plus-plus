#pragma once
#include<iostream>

class Island {
protected:
	size_t day;
	size_t space;

	size_t getSpace(){
		return space;
	}
public:
	Island(){
		day = 0;					
		space = 800000;				// square meters
	}

	size_t getTime(){
		return day;
	}

	void putTime(size_t day){
		this->day = day;
	}
};