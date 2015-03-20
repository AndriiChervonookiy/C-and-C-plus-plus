#include"Rectangle.h"

class Square : public Rectangle {
protected:
	bool validatePoints();
public:
	double getSquare();
	double getPerimeter();
	Square();
	Square(Point upperLeft, Point lowerRight);
};