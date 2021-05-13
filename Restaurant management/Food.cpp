
#include "Food.h"

//Default Constructor
Food::Food()
{
    size = "Small";
    basecost = 0;
}

//Constructor with basecost as argument
Food::Food(double basecost)
{
    this->size = "Small";
    this->basecost = basecost;
}

//Constructor with size and basecost passed as arguments
Food::Food(string size, double basecost)
{
    this->size = size;
    this->basecost = basecost;
}

//Destructor / Do nothing
Food::~Food()
{

}

string Food::GetSize() const
{
    return this->size;
}

double Food::GetBaseCost() const
{
    return this->basecost;
}

void Food::Print()
{
    //cout << "Size: " << this->size << ", basecost: " << this->basecost << endl;
}



