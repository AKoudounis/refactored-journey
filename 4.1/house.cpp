#include "house.h"
#include <iostream>
#include <string>
#include <cmath>

House::House() {        //default
    age = 0;
    type = "";
    numberofrooms = 0;
    cost = 0;
}

void House::setAge(int a) {
    age = a;
}
int House::getAge() const {
    return age;
}

void House::setType(string b) {
    type = b;

}
string House::getType() const {
    return type;
}

void House::setNumberofrooms(int c) {
    numberofrooms = c;
}
int House::getNumberofrooms() const {
    return numberofrooms;
}

void House::setCost(double d) {
    cost = d;
}
double House::getCost() const {
    return cost;
}



double House::estimatePrice() {

    double price{ 0 };

    if (type == "Attached"){
        float rate = 0.01;
        float rate2 = 0.02; //yrs 6++
        price = price + 100'000;
        
        if (age < 5)
        price = price * pow(1.0 + rate,age);
        else {
        price = price * pow(1.0 + rate,5);
        price = price * pow(1.0 + rate2,age-5);
        }
    }
    else if (type == "Detached") {
        float rate = 0.02;
        price = price + 200'000;
        price = price * pow(1.0 + rate, age);

    }
    else if (type == "Semi-Detached") {
        float rate = 0.02;
        float rate2 = 0.03;
        price = price + 150'000;
        price = price * pow(1.0 + rate, age);
        price = price * pow(1.0 + rate2, age - 5);

    }

    return price;

}

House::~House(){
    cout << "House is deconstructing..." << endl;
}


