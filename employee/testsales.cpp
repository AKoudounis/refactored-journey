#include<iostream>
#include “salesrep.h”
using namespace std;

int main() {
       SalesRep  emp(45565, “A.B”, 500, 12, 15000);         // input data
       emp.print();   // What happens here?

       emp.setAddress(“1455 Maisonneuve, Montreal”);
       emp.setPhone(“514-123-11111”);
       emp.setEmail(“a@concordia.ca”);
      
       emp.print();
       cout << emp.getAddress() << endl;
       cout << emp.getPhone() << endl;
       cout << emp.getEmail() << endl;
       cout << emp.getVacation() << endl;

       emp.setHoursWorked(450);   // number of hours modified
       emp.setHourlyRate(15);         // hourly rate modified
       emp.setCommission(34000); // commission modified
       emp.print();    // print salary

       return 0;   
}
