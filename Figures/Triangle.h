#pragma once
#include"HeaderFigure.h"

class Triangle : public Figure {			//	Rectangular triangle.
protected:
	Point first;
	Point second;
	Point third;
	bool validatePoints();
	double cathetus1();
	double cathetus2();
	double hypotenuse();
	void leftIncline(Point& top, Point& under, Point& third, int rows, int cols);
	void rightIncline(Point& top, Point& under, Point& third, int rows, int cols);
	void lowerTriangle_Left(int i, int cols, int rows);
	void topTriangle_Left(int i, int cols, int rows);
	void lowerTriangle_Right(int i, int cols, int rows);
	void topTriangle_Right(int i, int cols, int rows);

public:
	Triangle();
	Triangle(Point first, Point second, Point third);
	void print();
	double getPerimeter();
	double getSquare();
};