#include"Rectangle.h"

Rectangle::Rectangle() {
	lowerRight = { 10, 8 };
	upperLeft = { 2, 5 };
}

Rectangle::Rectangle(Point x, Point y) {
	lowerRight = x;
	upperLeft = y;
	if (!validatePoints())
		std::cout << "It is not a Rectangle!!!\n\n";
}

void Rectangle::print() {
	using namespace std;
	if (validatePoints()) {
		for (size_t i = 0; i < upperLeft.y; i++)
		{
			cout << endl;
		}
		size_t rows = lowerRight.y - upperLeft.y + 1;
		size_t cols = lowerRight.x - upperLeft.x + 1;
		for (size_t j = 0; j < rows; j++) {
			for (size_t i = 1; i < lowerRight.x; i++)
			{
				cout << " ";
			}
			for (size_t i = 0; i < cols + 1; i++)
			{
				if ((i == 0 || i == lowerRight .x - 1)) {
					if (j == 0 || j == rows - 1) {
						cout << "+";
					}
					else {
						cout << "|";
					}

				}
				else {
					if (j == 0 || j == rows - 1) {
						cout << "-";
					}
					else {
						cout << " ";
					}
				}
				if (i == cols){
					cout << '\n';
				}
			}
		}
	}
}

bool Rectangle::validatePoints() {
	if (upperLeft.x >= lowerRight.x || upperLeft.y >= lowerRight.y)
		return false;
	return true;//TODO implement me
}

double Rectangle::getSquare(){	
	if (validatePoints()){		
		return (lowerRight.x - upperLeft.x) * (lowerRight.y - upperLeft.y);
	}
	return 1.0; //TODO implement me
}

double Rectangle::getPerimeter() {
	if (validatePoints()){
		return ((lowerRight.x - upperLeft.x) + (lowerRight.y - upperLeft.y)) * 2;
	}
	return 2.0;//TODO implement me
}