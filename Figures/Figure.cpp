#include "Figure.h"

Figure::Figure(){}

double Figure::distance(Point A, Point B){
	return pow((pow(fabs((double)B.x - A.x), 2.0) + pow(fabs((double)B.y - A.y), 2.0)), 0.5);
}