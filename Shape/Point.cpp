//Andreas Koudounis 40089191
#include "Point.h"

  Point::Point(double x, double y) : Shape()
  {

        x_coor = x;

        y_coor = y;

   }


Point::Point() : Shape()

{
    x_coor = 0;

    y_coor = 0;

}


Point::~Point()
{
    std::cout << "Point object deleted";
}

double Point::GetXCo() const
{
    return x_coor;
}

double Point::GetYCo() const
{
    return y_coor;
}

double Point::SetXCo() const
{
    return  x_coor;
}

double Point::SetYCo() const
{
    return y_coor;
}

void Point::Print() const
{
}

