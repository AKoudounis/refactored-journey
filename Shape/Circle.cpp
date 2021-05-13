//Andreas Koudounis 40089191
#include "Circle.h"

Circle::Circle() : Shape()
{
    p = new Point(0, 0);

    radius = 0;

}

Circle::Circle(Point* pt, double rad) : Shape()

{
    p = pt;

    radius = rad;

}


Circle::~Circle()
{
    std::cout << "Circle object deleted";
}

double Circle::GetXValue() const
{
    return 0.0;
}

double Circle::GetYValue() const
{
    return 0.0;
}

double Circle::SetXValue() const
{
    return 0.0;
}

double Circle::SetYValue() const
{
    return 0.0;
}

void Circle::Print() const
{
}

