#include "Triangle.h"
#include "TriangleError.h"

Triangle::Triangle()
{
	first = { 4, 4 };
	second = { 8, 8 };
	third = { 4, 8 };
}

Triangle::Triangle(Point first, Point second, Point third)
{
	this->first = first;
	this->second = second;
	this->third = third;
	if (!validatePoints())
		throw TriangleError("It is a non rectangular triangle!!!\n\n");
}

bool Triangle::validatePoints() {
	bool q = false;
	if (third.x == first.x && third.y == second.y ||
		third.x == second.x && third.y == first.y)
		q = true;
	if (first.x == second.x || first.y == second.y)
		q = false;
	return q;
}

double Triangle::getPerimeter() {
	if (!validatePoints())
		throw TriangleError("It is a non rectangular triangle!!!\n\n");
	return cathetus1() + cathetus2() + hypotenuse();
}

double Triangle::getSquare(){
	if (!validatePoints())
		throw TriangleError("It is a non rectangular triangle!!!\n\n");
	return (cathetus1() * cathetus2()) / 2;
}

void Triangle::print()
{
	if (!validatePoints())
		throw TriangleError("It is a non rectangular triangle!!!\n\n");	
	else {
		Point top, under;
		if (first.y <= second.y) { 
			top = first; 
			under = second;
		}
		else{
			top = second;
			under = first;
		}
		for (size_t i = 0; i < top.y; i++) {
			std::cout << " " << "\n";
		}
		size_t rows = under.y - top.y + 1;
		size_t cols = (size_t)fabs((double)under.x - top.x) + 1;
		if (under.x > top.x ) {
			leftIncline(top, under, third, rows, cols);
		}
		else {
			rightIncline(top, under, third, rows, cols);
		}
	}
}

void Triangle::leftIncline(Point& top, Point& under, Point& third, int rows, int cols)
{
	for (int i = 0; i < rows; i++) {
		for (size_t j = 0; j < top.y; j++)
			std::cout << " ";
		if (third.x == under.x)
			lowerTriangle_Left(i, cols, rows);
		else 
			topTriangle_Left(i, cols, rows);		
	}
	std::cout << "\n\n";
}

void Triangle::lowerTriangle_Left(int i, int cols, int rows)
{
	using namespace std;
	for (int j = 0; j < cols; j++)	{
		if (j > i && i == 0) cout << "~";
		if (j < i && i < rows) cout << " ";
		if (j > i && i > 0) cout << " ";
		if (j == i)	cout << "\\";
	}
	cout << "|" << endl;
}

void Triangle::topTriangle_Left(int i, int cols, int rows)
{
	using namespace std;
	cout << "|";
	for (int j = 0; j < cols; j++)	{
		if (j < i && i < rows - 1) cout << " ";
		if (j < i && i == rows - 1) cout << "_";
		if (j == i) {
			cout << "\\";
			break;
		}
	}
	cout << endl;
}

void Triangle::rightIncline(Point& top, Point& under, Point& third, int rows, int cols)
{
	for (int i = 0; i < rows; i++) {
		for (size_t j = 0; j < top.y; j++)
			std::cout << " ";
		if (third.x == under.x)
			lowerTriangle_Right(i, cols, rows);
		else
			topTriangle_Right(i, cols, rows);
	}
	std::cout << "\n\n";
}

void Triangle::lowerTriangle_Right(int i, int cols, int rows)
{
	using namespace std;
	for (int j = 0; j < cols; j++)	{
		if (j < cols - i) cout << " ";
		if (j == cols - i - 1)	cout << "/";
		if (j > cols - i - 1 && i <rows - 1) cout << " ";
		if (j > cols - i - 1 && i == rows - 1) cout << "_";
	}
	cout << "|" << endl;
}
void Triangle::topTriangle_Right(int i, int cols, int rows)
{
	using namespace std;
	cout << "|";
	for (int j = 0; j < cols; j++)	{
		if (j < cols - i - 1 && i == 0) cout << "~";
		if (j < cols - i - 1 && i > 0) cout << " ";
		if (j == cols - i - 1)	cout << "/";
	}
	cout << endl;
}

double Triangle::cathetus1(){
	return distance(first, third);
}

double Triangle::cathetus2(){
	return distance(second, third);
}

double Triangle::hypotenuse(){
	return distance(first, second);
}