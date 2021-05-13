// adminstaff.h: Specification of class AdminStaff

class AdminStaff : public Employee
{
	public:
          AdminStaff();     // default constructor                                     
          AdminStaff(int, const char*, int, double);  // regular constructor: id, name, 
                                                                           // hours worked, hourly rate
          ~AdminStaff();
   
          void setHoursWorked(int);      // modifies hours worked
          int getHoursWorked() const;   // returns hours worked
          void setHourlyRate(double);   // modifies hourly rate
          doublegetHourlyRate () const;      // returns hourly rate
          double getPay() const;            // returns pay
  	    void print() const;   // prints manager information - – overrides print of Employee
	
      private:
	    int hoursWorked;       // number of hours worked during the year
          double hourlyRate;    // hourly rate           

};

// default constructor                                     
AdminStaff::AdminStaff() : Employee() {
   hoursWorked = 0;
   hourlyRate = 0.0; 
   vacation = 20;
} 

// regular constructor
AdminStaff::AdminStaff (int id1, const char* name1, int hw, double hr) : Employee(id1, name1) {
   hoursWorked = hw;
   hourlyRate = hr;
   vacation = 20;
}
   
// destructor
AdminStaff::~AdminStaff() {
    // No need to do anything here
}

// modifies hours worked
void AdminStaff::setHoursWorked(int hw) {
    hoursWorked = hw;
}

// returns hours worked
int AdminStaff::getHoursWorked() const {
   return hoursWorked;
}

// modifies hourly rate
void AdminStaff::setHourlyRate(double hr) {
	hourlyRate = hr;
}

// returns hourly rate
double AdminStaff::getHourlyRate () const {
	return hourlyRate;
}

// returns pay
double AdminStaff::getPay() const {
	return hourlyRate * hoursWorked;
}

// prints manager information - – overrides print of Employee
void AdminStaff::print() const  {
	Employee::print();
	cout << getPay() << endl;
}
