//
//  TableOrder.cpp
//  Assignment4COEN244
//
//  Created by Mohammad Altahat on 2020-11-05.
//

#include "TableOrder.h"

int TableOrder::orderNo = 0;

//Default Constructor
TableOrder::TableOrder()
{
    this->customerOrders = nullptr;
}

//Constructor with the arguments
TableOrder::TableOrder(int tableNum, int seats)
{
    this->tableNum = tableNum;
    
    this->seats = seats;
    
    this->tableStatus = true;
    
    //Assign the array of pointers for CustomerOrder objects
    this->customerOrders = new CustomerOrder*[this->seats];
    
    //Initialize all pointers to nullptr
    for (int i = 0; i < this->seats; i++)
        this->customerOrders[i] = nullptr;
    
    this->myOrderNo = 0;
    
}

void TableOrder::InsertOrder(CustomerOrder  * ptrCustomerOrder)
{
    //search for the first nullptr pointer to assign to the passed pointer
    for (int i = 0;  i < this->seats; i++)
        if( this->customerOrders[i] == nullptr)
        {
            this->customerOrders[i] = ptrCustomerOrder;
            break;
        }
}

double TableOrder::GetTotalCost()
{
    this->totalCost = 0;
    
    //calculate the total cost of all customer orderes in the list
    for (int i = 0; i < seats; i++)
        if (this->customerOrders[i] != nullptr)
            totalCost += this->customerOrders[i]->GetOrderCost();
    
    return this->totalCost;
}

void TableOrder::Print()
{
    cout << "\n--------------------------------------\n";
    cout << "Table No.: " << this->tableNum << endl;
    cout << "Table Order Number: " << this->myOrderNo << endl;
    cout << "Seats: " << this->seats << endl;
    cout << "Orders: " << endl;
    
    for (int i = 0; i < this->seats; i++)
        if (this->customerOrders[i] != nullptr)
        {
            cout << "\tCustomer " << (i+1) << " Order:" << endl;
            this->customerOrders[i]->Print();
            cout << endl;
        }
    
    cout << "Total Table Cost: $" << this->GetTotalCost() << endl;
    cout << "--------------------------------------\n";
}

bool TableOrder::GetTableStatus()
{
    return this->tableStatus;
}

int TableOrder::GetSeats()
{
    return this->seats;
}

bool TableOrder::CancelCustomerOrders()
{
    //use delete to delete all objects that are pointed to
    //by hte pointers in the customerOrders array of pointers
    for (int i = 0; i < this->seats; i++)
        if (this->customerOrders[i] != nullptr)
        {
            delete customerOrders[i];
            customerOrders[i] = nullptr;
        }
    
    this->myOrderNo = 0;
    
    return true;
}

int TableOrder::GetTableOrderNum()
{
    return this->myOrderNo;
}

void TableOrder::SetTableStatus(bool status)
{
    this->tableStatus = status;
}

void TableOrder::SetTableOrderNum()
{
    this->myOrderNo = ++orderNo;
}

TableOrder::~TableOrder()
{
    for (int i = 0; i < this->seats; i++)
        if (customerOrders[i] != nullptr)
            delete customerOrders[i];
    
    if (customerOrders != nullptr)
        delete[] customerOrders;
}


