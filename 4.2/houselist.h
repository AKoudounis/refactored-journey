#ifndef HOUSELIST_H
#define HOUSELIST_H

#include <iostream>
#include <string>

using namespace std;

class House
{
    int age;
    string type;
    int numberofrooms;
    double currentCost;

public:
    
    House()
    {
        age = 0;
        type = "";
        numberofrooms = 0;
        currentCost = 0.0;
    }

    House(int a, string b, int c, double d)
    {
        age = a;
        type = b;
        numberofrooms = c;
        currentCost = d;
    }

    void setAge(int a)
    {
        age = a;
    }

    void setType(string b)
    {
        type = b;
    }

    void setUnit(int c)
    {
        numberofrooms = c;
    }

    void setCurrentCost(double d)
    {
        currentCost = d;
    }

    int getAge()
    {
        return age;
    }

    string getType()
    {
        return type;
    }

    int getUnit()
    {
        return numberofrooms;
    }

    double getCurrentCost()
    {
        return currentCost;
    }

    void showhouse()
    {
        cout << "\n ************ House Information ************";
        cout << "\n Age of House: " << age << "\n Type of House: " << type
            << "\n Number of Units: " << numberofrooms << "\n Cost: " << currentCost << endl;
    }


};

class HouseList
{
private:

    static const size_t LIST_SIZE = 150; 
    House* items; 
    size_t numItems; 

public:
    
    HouseList();
    
    void addHouse();
    void printHouses();
    void printCost();
    House* returnRange(double, double, int&);
    void printRange(House*, int);

    ~HouseList();
};

#endif