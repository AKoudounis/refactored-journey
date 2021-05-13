
// employee.h: Specification of the base class Employee

class Employee
{

	protected:
	   int id;                   // employee id
         char* name;        // name of the employee
         char* address;    // address of the employee
         char* phone;       // telephone number, e.g., 514-234-5454
         char* email;        // email address
         int vacation;        // days of vacation

	public:
          Employee();                             // default constructor
	    Employee (int, const char* );   // regular constructor, used to set id and name
	    ˜Employee();                            // destructor
         
          void setName(char*);               // modifies the name
          const char* getName() const;            // returns the name
         
          void setId(int);                         // modifies the id
          int getId() const;                      // returns the id

          void setAddress(char*);           // modifies the address
         const  char* getAddress() const;        // returns the address


          void setPhone(char*);             // modifies the phone number
          const char* getPhone() const;          // returns the phone number

          void setEmail(char*);              // modifies the email
         const char* getEmail() const;           // returns the email

          void setVacation(int);              // modifies the number of vacation days
          int getVacation() const;           // returns the number of vacation days

 	     void print() const;                     // prints info about an employee

};