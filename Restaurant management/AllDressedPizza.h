//
//  AllDressedPizza.h
//  Assignment4COEN244
//
//  Created by Mohammad Altahat on 2020-11-05.
//

#pragma once

#include <iostream>
#include "string.h"
#include "Food.h"
using namespace std;

class AllDressedPizza : public Food
{
    public:

        //default constructor
        AllDressedPizza();

        //regular constructor
        AllDressedPizza(string);

        //Destructor
        ~AllDressedPizza();

        double GetCost() const;

        void Print();

};
