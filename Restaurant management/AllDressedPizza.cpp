//
//  AllDressedPizza.cpp
//  Assignment4COEN244
//
//  Created by Mohammad Altahat on 2020-11-05.
//

#include "AllDressedPizza.h"
using namespace std;

//Default constructor - Pass basecost 8 to parent class Food
AllDressedPizza::AllDressedPizza() : Food(8)
{
    
}

//constructor - takes size as argument - Pass size and basecost 8 to parent class Food
AllDressedPizza::AllDressedPizza(string size) : Food(size, 8)
{
    
}

void AllDressedPizza::Print()
{
    cout << GetSize() << " All Dressed Pizza: $" << this->GetCost();

}

double AllDressedPizza::GetCost() const
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

AllDressedPizza::~AllDressedPizza()
{

}
