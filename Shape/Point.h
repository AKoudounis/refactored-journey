//Andreas Koudounis 40089191
#include "Shape.h"

class Point :public Shape {

private:

	double x_coor, y_coor;

public:

	Point();
	void Print() const;
	Point(double x, double y);
	double SetXCo() const;
	double GetXCo() const;
	double SetYCo() const;
	double GetYCo() const;
	~Point();
};