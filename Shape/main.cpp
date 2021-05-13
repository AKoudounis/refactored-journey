//Andreas Koudounis 40089191

#include "Shape.h"
#include "Point.h"
#include "Circle.h"
#include "Triangle.h"
#include "Line.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {

	//values are assumed; missing in doc for base p

	Point p(3.5, 5.2);

	Point p1(3.5, 2.1);

	Point p2(4.8, 7.9);

	Point p3(3.5, 6.1);

	Circle circle(&p, 4.5);

	Line line(&p1, &p2);

	Triangle triangle(&p1, &p2, &p3);

	
	try
		{
			ofstream DATAFILE;
			DATAFILE.open("File.info", ios::out);
			DATAFILE << "Object \t Field 1 \t Field 2 \t Field 3 \t Field 4 \t  Field 5 \t Field 6 \t Field 7 "; 
			DATAFILE << "\nP1 \t Point "; 
			DATAFILE << "\nL1 \t Line " ; 
			DATAFILE << "\nP2 \t Point ";
			DATAFILE << "\nT1 \t Triangle ";
			DATAFILE << "\nP3 \t Point " ;
			DATAFILE << "\nC1 \t Circle ";
			


			DATAFILE.close();
			cout << "\n\tSuccess! Data was loaded.";

		}
	catch (exception X)
	{
		cout << "\n\tFile Error! Unable to load data.";
		
	}




	/*Cannot get it to work with pure virtual fnc & unable to complete the eof write and read to a file and output to the console what has been written to the file , 
	what am I missing to make the code work thank you */


}