//Andreas Koudounis 40089191
#include "Line.h"

Line::Line(Point* pt1, Point* pt2) : Shape()
{

    p1 = pt1;

    p2 = pt2;
}


Line::~Line()
{
    std::cout << "Line object deleted";
}


void Line::print() const
{
}

