//Andreas Koudounis 40089191
#pragma once
#include <iostream>
#include "Circle.h"
#include "Shape.h"
#include "Point.h"

using namespace std;

class Circle : public Shape
{
private:

	Point* p;
	double radius;

public:

	//default constructor
	Circle();
	Circle(Point* pt, double rad);

	//Destructor
	~Circle();

	double GetXValue() const;
	double GetYValue() const;
	double SetXValue() const;
	double SetYValue() const;

	virtual void Print() const;

};
