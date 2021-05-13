#include <iostream>
using namespace std;

void sumsquares(int n);

int main() {
	int n = 100;

	sumsquares(n);
	
	return 0;
}

void sumsquares(int n)
{
	int value = (((n*n) * ( (n + 1) * (n + 1) ) ) / 4) - (n * (n + 1) * (2 * n + 1) / 6); 
	cout << "The difference between the sum of the squares of the first one hundred natural numbers and the square of the sum is: " << value << endl;
}