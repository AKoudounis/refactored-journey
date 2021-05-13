#include<iostream>
using namespace std;

int triplet(){
	int a,b;
    int n = 500;
	for (int i = 1 ; i < n; i++){
			for (int j = i + 1; j < n ; j++){
				if (2000 * ( i+ j) - 2*i*j == 1000000){
					a = i; b = j;
					return a*b*(1000-a-b);
				}
					
			}
	}
}

int main(){
	int result;
	result = triplet();
	cout << "The product abc of the Pythagorean triplet a + b + c = 1000 is: "
    << result << endl;

	return 0;
}
