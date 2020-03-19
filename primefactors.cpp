#include <iostream>
#include <cmath>

using namespace std;

void primes(long long n) {

   for (int i = 3; i <= sqrt(n); i = i + 2){
      while ( n % i == 0){
         n =  n/i;
      }
   }
   if (n > 2)
   cout << n << "\t";
}

int main() {
   long long n = 600851475143;
   cout << "The largest prime factor of " << n << " is: ";
   primes(n);
   return 0;
}