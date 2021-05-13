//
//  Softdrink.h
//  Assignment4COEN244
//
//  Created by Mohammad Altahat on 2020-11-05.
//

#pragma once

#include "Food.h"
#include "iostream"
//#include "string.h"
using namespace std;

class SoftDrink : public Food
{
    public:

        //default constructor
        SoftDrink();

        //regular constructor
        SoftDrink(string);

        //Destructor
        ~SoftDrink();

        double GetCost() const;

        void Print();

};
