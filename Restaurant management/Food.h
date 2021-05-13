#pragma once

#include "iostream"
//#include "string.h"
using namespace std;

class Food
{
    private:
        string size;
        double basecost;

    public:

        //default constructor
        Food();
        
        //regular constructor
        Food(double);
    
        //regular constructor
        Food(string, double);

        //Destructor
        virtual ~Food();

        virtual double GetCost() const = 0;
    
        string GetSize() const;
    
        double GetBaseCost() const;

        virtual void Print();

};
