//Andreas Koudounis 40089191
#include "Shape.h"
#include <iomanip>

//Default Constructor
Shape::Shape()
{
    
}


//Default Constructor
Shape::~Shape()
{
    std::cout << "Shape object deleted";
}


void Shape::print() const
{
    
}

void Shape::outputLine(const char* const object, const char* const Field1, const char* const Field2, const char* const Field3, const char* const Field4, 
    const char* const Field5, const char* const Field6, const char* const Field7)
{
    cout << left << setw(10) << object << setw(5) << Field1
        << setw(5) << Field2 <<
        Field3 << setw(5) << 
        Field4 << setw(5) << 
        Field5 << setw(5) << 
        Field6 << setw(5) << 
        Field7 << endl;
}





