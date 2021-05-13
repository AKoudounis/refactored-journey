#include<iostream>
#include “adminstaff.h”

using namespace std;

int main() {
	 AdminStaff  emp(45565, “A.B”, 500, 12.0);                  // input data

       emp.setAddress(“1455 Maisonneuve, Montreal”);
       emp.setPhone(“514-123-11111”);
       emp.setEmail(“emp@concordia.ca”);

       emp.print();
       cout << emp.getAddress() << endl;
       cout << emp.getPhone() << endl;
       cout << emp.getEmail() << endl;
       cout << emp.getVacation() << endl;

       emp.setHoursWorked(450);   // number of hours modified
       emp.setHourlyRate(15);         // hourly rate modified
       emp.print();    // print salary of admin staff employee

       return 0;   
}
