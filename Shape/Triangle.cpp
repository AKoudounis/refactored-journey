//Andreas Koudounis 40089191
#include "Triangle.h"

Triangle::Triangle(Point* pt1, Point* pt2, Point* pt3) {

	p1 = pt1;

	p2 = pt2;

	p3 = pt3;

}

Triangle::~Triangle()
{
	std::cout << "Triangle object deleted";
}


void Triangle::print() const
{
}