#include<iostream>
#include “employee.h”

using namespace std;

int main() {
	 Employee  emp(45565, “A.B”);                  // input data

       emp.setAddress(“1455 Maisonneuve, Montreal”);
       emp.setPhone(“514-345-4564”);
       emp.setEmail(“ab@concordia.ca”);
       emp.setVacation(45);

       cout << emp.print() << endl;
       cout << emp.getAddress() << endl;
       cout << emp.getPhone() << endl;
       cout << emp.getEmail() << endl;
       cout << emp.getVacation() << endl;

       return 0;
        
}
