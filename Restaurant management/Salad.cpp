//
//  Salad.cpp
//  Assignment4COEN244
//
//  Created by Mohammad Altahat on 2020-11-05.
//

#include "Salad.h"

//Default constructor - Pass basecost 4 to parent class Food
Salad::Salad() : Food(4)
{
    
}

//constructor - takes size as argument - Pass size and basecost 4 to parent class Food
Salad::Salad(string size) : Food(size, 4)
{
    
}

void Salad::Print()
{
    cout << GetSize() << " Salad: $" << this->GetCost();
}

double Salad::GetCost() const
{
    if (GetSize() == "Small")
        return GetBaseCost();
    else if (GetSize() == "Medium")
        return GetBaseCost() * 1.5;
    else if (GetSize() == "Large")
        return GetBaseCost() * 2;
    else
        return 0;
}

Salad::~Salad()
{

}



