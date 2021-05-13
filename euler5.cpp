#include <iostream>
using namespace std;

unsigned int gcd(unsigned int , unsigned int);
unsigned int lcm(unsigned int , unsigned int);

int main(){

unsigned smallestnumber = 1;

for (unsigned int i = 2; i <= 20; i++)
{
    smallestnumber = lcm(smallestnumber, i);
}


cout << "The smallest positive number that is evenly divisible by numbers 1 - 20 is: " << smallestnumber; 
return 0;
}

unsigned int gcd(unsigned int a, unsigned int b)
{
   while (a !=0)
    {
        unsigned int c = a;
        a = b % a;
        b = c;
    }
    return b;
}

unsigned int lcm(unsigned int a, unsigned int b)
{
return a * (b / gcd(a,b));
}