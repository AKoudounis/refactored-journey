#include <iostream>
#include “employee.h”

using namespace std;

Employee::Employee( ) {
        id = 0;
	  name = NULL;
	  address = NULL;
        phone = NULL;
        email = NULL;
        vacation = 0;
}

Employee::Employee( int id1, const char* name1 ) {
        id = id1;
	  name = new char[ strlen( name1 ) + 1 ];
	  strcpy( name, name1 );

	  address = NULL;
        phone = NULL;
        email = NULL;
        vacation = 0;
}

Employee::˜Employee() {
	delete [ ] name;  
      delete [ ] address;
	delete [ ] phone; 
      delete [ ] email;
}

void Employee::setId(int id1) {
	id = id1;
}

int Employee::getId() const {
	return id;
}

void Employee::setName(char* name1) {
	name = new char[ strlen( name1 ) + 1 ];
	strcpy( name, name1 );
}

const char* Employee::getName() const {
	return name;
}


void Employee::setAddress(char* address1) {
	address = new char[ strlen( address1 ) + 1 ];
	strcpy( address, address1 );
}

const char* Employee::getAddress() const {
	return address;
}

void Employee::setPhone(char* phone1) {
	phone = new char[ strlen( phone1 ) + 1 ];
	strcpy( phone, phone1 );
}

const char* Employee::getPhone() const {
	return phone;
}

void Employee::setEmail(char* email1) {
	email = new char[ strlen( email1 ) + 1 ];
	strcpy( email, email1 );
}

const char* Employee::getEmail() const {
	return email;
}

int Employee::setVacation(int v) {
	vacation = v;
}

int Employee::getVacation() const  {
	return vacation;
}

void Employee::print() const {
	cout << id << “ “ << name << endl;
}
