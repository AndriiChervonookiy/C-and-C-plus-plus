#include"Headers.h"

class Figure {
protected:
	Figure();
	double distance(Point A, Point B);
public:
	void print();
	double getPerimeter();
	double getSquare();

};