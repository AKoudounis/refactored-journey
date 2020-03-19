//project euler problem 2
#include <iostream>
#include <cmath>

using namespace std; 


int fib(int n) 
{ 
    //[1, 2, 3, 5, 8, 13, 21, 34, 55, 89 ]
    long long int f1 = 1, f2 = 2; 

    long long int sum = 0; 
    int temp = 0;
  
    while (f1 <= n) 
    {  
        temp = f1; 
        f1 = f2; 
        f2 += temp;
        if (temp % 2 == 0)
        {
            sum += temp;
        }
    }

     if (n==0 || n==1)
     {
        sum = 0; return sum;
     }

    return sum; 
}


int main() {

int n = 4000000; 
cout << "The sum of even valued terms of fib(" << n << ") is  " << fib(n) << "\n"; 

system("pause");
return 0; 


}

