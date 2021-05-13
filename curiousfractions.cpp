//Project Euler Problem #33
#include <iostream>

using namespace std;

int gcd(int,int);

int main() {
/*
16/64 
26/65
19/95
49/98
*/
int denomproduct = 1;
int numerproduct = 1;
 
for (int i = 1; i < 10; i++) {
    for (int denom = 1; denom < i; denom++) {
        for (int numer = 1; numer < denom; numer++) {
            if ((numer * 10 + i) * denom == numer * (i * 10 + denom)) {
                denomproduct *= denom; //16*26*19*49
                numerproduct *= numer; //64*65*95*98
            }
        }
    }
}


int a = denomproduct / gcd(numerproduct, denomproduct);
cout << "The value of the denominator is : " << a;
return 0;
}

int gcd(int a, int b) { 
   if (b == 0) 
      return a; 
   return gcd(b, a % b);  
}