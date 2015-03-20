#pragma once
struct Point
{
	size_t x;
	size_t y;

	Point(){
		x = 0;
		y = 0;
	}

	Point(int K, int G){
		x = K;
		y = G;
	}

	Point& operator = (const Point& ob){
		x = ob.x;
		y = ob.y;
		return *this;
	}

};