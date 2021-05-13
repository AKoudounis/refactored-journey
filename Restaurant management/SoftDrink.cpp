//
//  Softdrink.cpp
//  Assignment4COEN244
//
//  Created by Mohammad Altahat on 2020-11-05.
//

#include "SoftDrink.h"

//Default constructor - Pass basecost 2 to parent class Food
SoftDrink::SoftDrink() : Food(2)
{
    
}

//constructor - takes size as argument - Pass size and basecost 2 to parent class Food
SoftDrink::SoftDrink(string size) : Food(size, 2)
{
    
}

void SoftDrink::Print()
{
    cout << GetSize() << " Soft drink: $" << this->GetCost();
}

double SoftDrink::GetCost() const
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

SoftDrink::~SoftDrink()
{

}

