// default constructor                                     
Manager::Manager() : Employee()  { 
      salary = 0.0;
      vacation = 30;   // protected member, can be used here directly.
      numSupervisedEmp = 0;
}

 // regular constructor
Manager::Manager(int id1, const char* name1, double sal) : Employee(id1, name1)  {
     salary = sal;
     vacation = 30;
     numSupervisedEmp = 0;
}

// modifies salary   
void Manager::setSalary(double sal)  {
    salary = sal;
}

// modifies number of supervised employees   
void Manager::setNumSupervisedEmp(int se)  {
    numSupervisedEmp = se;
}

// returns the number of supervised employees
int Manager::getNumSupervisedEmp() const  {
    return numSupervisedEmp;
}

// returns pay 
double Manager::getPay() const  {
	return salary;
}

// prints manager information – overrides print of Employee
void Manager::print() const  {
	Employee::print();
       cout << salary << endl;
}

// destructor
void Manager::~Manager() {
	// does nothing
}
