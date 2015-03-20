#pragma once
#include<iostream>
using namespace std;
#include"Island.h"

class Animal : public Island {
protected:
	float meal;
	int maxValue;
	float totalQuantity;
public:
	virtual size_t eat() = 0;
};