// salesrep.h: Specification of class SalesRep

class SalesRep : public Employee
{
	public:
          SalesRep ();     // default constructor                                     
          SalesRep (int, const char*, int, double, double);  // regular constructor
          ~SalesRep ();
   
          void setHoursWorked (int);      // modifies hours worked
          int getHoursWorked () const;   // returns hours worked
          void setHourlyRate (double);   // modifies hourly rate
          double getHourlyRate () const;       // returns hourly rate
          void setCommission (double); // modifies commission
          double getCommission () const;     // returns commission

          double getPay () const;      // returns pay
  	    void print() const;   // prints manager information - – overrides print of Employee
	
      private:
	    int hoursWorked;       // number of hours worked during the year
          double hourlyRate;     // hourly rate          
          double commission;   // yearly commission  
};

// default constructor                                     
SalesRep::SalesRep() : Employee() {
   hoursWorked = 0;
   hourlyRate = 0.0;
   commission = 0.0; 
   vacation = 20;
} 

// regular constructor
SalesRep::SalesRep (int id1, const char* name1, int hw, double hr, double c) : Employee(id1, name1) {
   hoursWorked = hw;
   hourlyRate = hr;
   commission = c;
   vacation = 20;
}
   
// destructor
SalesRep::~SalesRep() {
    // No need to do anything here
}

// modifies hours worked
void SalesRep::setHoursWorked(int hw) {
    hoursWorked = hw;
}

// returns hours worked
int SalesRep::getHoursWorked() const {
   return hoursWorked;
}

// modifies hourly rate
void SalesRep::setHourlyRate(double hr) {
	hourlyRate = hr;
}

// returns hourly rate
double SalesRep::getHourlyRate () const {
	return hourlyRate;
}

// modifies commission
void SalesRep::setCommission(double c) {
	commission = c;
}

// returns hourly rate
double SalesRep::getCommission () const {
	return commission;
}

// returns pay
double SalesRep::getPay() const {
	return hourlyRate * hoursWorked + commission;
}

// prints manager information - – overrides print of Employee
void SalesRep::print() const  {
	Employee::print();
	cout << getPay() << endl;
}
