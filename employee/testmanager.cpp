#include<iostream>
#include “manager.h”

using namespace std;

int main() {
	 Manager  emp(45565, “A.B”, 60000);                  // input data
       
       emp.setAddress(“1455 Maisonneuve, Montreal”);
       emp.setPhone(“514-123-11111”);
       emp.setEmail(“emp@concordia.ca”);
       emp.setNumSupervisedEmp(10);

       emp.print();
       cout << emp.getAddress() << endl;
       cout << emp.getPhone() << endl;
       cout << emp.getEmail() << endl;
       cout << emp.getVacation() << endl;
       cout << emp. getNumSupervisedEmp() << endl;

       emp.setSalary(120000);   // salary is modified
       emp.print();                      // print new salary with manager info

       return 0;   
}