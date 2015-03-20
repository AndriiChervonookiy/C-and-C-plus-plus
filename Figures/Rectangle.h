#pragma once
#include"HeaderFigure.h"

class Rectangle : public Figure {
protected:
	Point upperLeft;
	Point lowerRight;
	bool validatePoints();
public:
	Rectangle();
	Rectangle(Point upperLeft, Point lowerRight);
	void print();
	double getPerimeter();
	double getSquare();

};