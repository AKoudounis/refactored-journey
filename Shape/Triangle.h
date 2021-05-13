//Andreas Koudounis 40089191
#include "Shape.h"
#include "Point.h"

class Triangle :public Shape {

private:

	Point* p1, * p2, * p3;

public:


	Triangle(Point* pt1, Point* pt2, Point* pt3);
	~Triangle();

	void print() const;

};