//
//  Salad.hpp
//  Assignment4COEN244
//
//  Created by Mohammad Altahat on 2020-11-05.
//

#pragma once

#include "Food.h"
#include "iostream"
//#include "string.h"
using namespace std;

class Salad : public Food
{
    public:

        //default constructor
        Salad();

        //regular constructor
        Salad(string);

        //Destructor
        ~Salad();

        double GetCost() const;

        void Print();

};

