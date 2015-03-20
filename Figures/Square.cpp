#include"Square.h"


Square::Square(){
	upperLeft = { 2, 4 };
	lowerRight = { 4, 6 };
}

Square::Square(Point upperLeft, Point lowerRight): Rectangle(upperLeft, lowerRight) {}