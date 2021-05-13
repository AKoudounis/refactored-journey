//
//  VegetarianPizza.cpp
//  Assignment4COEN244
//
//  Created by Mohammad Altahat on 2020-11-05.
//

#include "VegetarianPizza.h"

//Default constructor - Pass basecost 5 to parent class Food
VegetarianPizza::VegetarianPizza() : Food(5)
{
    
}

//constructor - takes size as argument - Pass size and basecost 5 to parent class Food
VegetarianPizza::VegetarianPizza(string size) : Food(size, 5)
{
    
}

void VegetarianPizza::Print()
{
    cout << GetSize() << " Vegeterian Pizza: $" << this->GetCost();
}

double VegetarianPizza::GetCost() const
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

VegetarianPizza::~VegetarianPizza()
{

}
