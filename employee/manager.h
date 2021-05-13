// manager.h: Specification of class Manager

class Manager : public Employee
{
	public:
          Manager();     // default constructor                                     
          Manager(int, const char*, double);  // regular constructor: id, name, salary
          ~Manager();
   

          void setSalary(double);                     // modifies salary
          void setNumSupervisedEmp(int);     // modifies number of supervised employees
          int getNumSupervisedEmp() const;  // returns number of supervised employees

 	    double getPay() const;      // returns pay
	    void print() const;              // prints manager information - – overrides print of 
                                                    // Employee
	private:
	    double salary; 
          int numSupervisedEmp; 
};
