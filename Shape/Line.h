//Andreas Koudounis 40089191
#include "Shape.h"
#include "Point.h"

class Line :public Shape {

private:

	Point* p1, * p2;

public:

	Line(Point* pt1, Point* pt2);
	~Line();
	void print() const;

};