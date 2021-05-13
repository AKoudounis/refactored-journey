//
//  VegeterianPizza.h
//  Assignment4COEN244
//
//  Created by Mohammad Altahat on 2020-11-05.
//

#pragma once

#include "Food.h"
#include "iostream"
//#include "string.h"
using namespace std;

class VegetarianPizza : public Food
{
    public:

        //default constructor
        VegetarianPizza();

        //regular constructor
        VegetarianPizza(string);

        //Destructor
        ~VegetarianPizza();

        double GetCost() const;

        void Print();

};
