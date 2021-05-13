//Andreas Koudounis 40089191
#pragma once
#include "iostream"
using namespace std;

class Shape {

public:

    Shape* array[20] = { NULL };

    Shape();
    virtual ~Shape();
    virtual void print() const = 0;
    void outputLine(const char* const object, const char* const Field1, const char* const Field2, const char* const Field3, const char* const Field4, const char* const Field5,
        const char* const Field6, const char* const Field7);
};


