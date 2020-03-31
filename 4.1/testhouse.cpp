#include <iostream>
#include <string>
#include "house.h"

int main()
{

int age1;
string type1;
int numberofrooms1;
double cost1;


int age2;
string type2;
int numberofrooms2;
double cost2;


House h1;
House h2;


age1 = 10;
type1 = "Detached";
numberofrooms1 = 5;
cost1 = 200'000;

h1.setAge(age1);
h1.setType(type1);
h1.setNumberofrooms(numberofrooms1);
h1.setCost(cost1);



age2 = 20;
type2 = "Attached";
numberofrooms2 = 4;
cost2 = 100'000;


h2.setAge(age2);
h2.setType(type2);
h2.setNumberofrooms(numberofrooms2);
h2.setCost(cost2);




std::cout << "The age of house1 is : " << h1.getAge() << std::endl;

std::cout << "The age of house2 is : " << h2.getAge() << std::endl;


std::cout << "The number of rooms in house1 is : " << h1.getNumberofrooms() << std::endl;

std::cout << "The number of rooms in house2 is : " << h2.getNumberofrooms() << std::endl;


std::cout << "House1 type: " << h1.getType() << std::endl;

std::cout << "House2 type: " << h2.getType() << std::endl;


std::cout << "House1 estimate: " << h1.estimatePrice() << std::endl; // 200k + 2%/yr 10 yrs

std::cout << "House2 estimate: " << h2.estimatePrice() << std::endl; // 100k + 1%/yr 5yr + 2% yr++ total 20yrs 15yrs ar 2%

return 0;

}