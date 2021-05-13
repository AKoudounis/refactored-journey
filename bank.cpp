#include <iostream>
#include <string>
using namespace std;

int main()
{
double totalAmount;
double withdrawAmount;
double deductions;
char choice;
bool repeat = true;

cout << "Enter the initial amount: $";
cin >> totalAmount;

while(totalAmount > 0 && repeat)
{
  cout << "\nEnter an amount to withdraw: $";
  cin >> withdrawAmount;
  
  if(withdrawAmount > 500)
  {
   cout << "You cannot withdraw amount of $500 per day." << endl;
  }
  else
  {
   double serviceCharge = 0;

   if(withdrawAmount > 300)
    serviceCharge = (withdrawAmount - 300) * 0.04;   

   deductions = withdrawAmount + serviceCharge;

   if(deductions > totalAmount)
   {
    cout << "Insufficient funds!" << endl;
    cout << "Allow with a service charge of $25? (Y/N): ";
    cin >> choice;

    if(choice == 'y' || choice == 'Y')
    {  
     totalAmount -= (deductions + 25);

     cout << "Service charges: $" << serviceCharge << endl;
     cout << "Additional charge: $25" << endl;
     cout << "Current balance: $" << totalAmount << endl;
    }
   }
   else
   {
    totalAmount -= deductions;

    cout << "Service charges: $" << serviceCharge << endl;
    cout << "Current balance: $" << totalAmount << endl;
   }
  }

  if(totalAmount > 0)
  {
   cout << "\nContinue to withdraw? (Y/ N): ";
   cin >> choice;

   if(choice != 'y' && choice != 'Y')
   {
    cout << "Current balance: $" << totalAmount << endl;
    repeat = false;
   }
  }
}

if(totalAmount <= 0)
  cout << "You should deposit an amount of money." << endl;

cout << endl;
system("pause");
return 0;
}