//
//  CustomerOrder.cpp
//  Assignment4COEN244
//
//  Created by Mohammad Altahat on 2020-11-05.
//

#include "CustomerOrder.h"

//Default constructor - assign all orderedItems pointers to nullptr
CustomerOrder::CustomerOrder()
{
    for (int i = 0; i < 3; i++)
        this->OrderedItems[i] = nullptr;
    
    cost = 0;
}

void CustomerOrder::AddFoodItem(Food* item)
{
    bool itemAdded = false;
    
    //search for the first nullptr pointer in the array of pointers OrderedItems
    for (int i = 0; i < 3; i++)
        if (this->OrderedItems[i] == nullptr)
        {
            //assign this pointer to the pointer passed as argument
            OrderedItems[i] = item;
            itemAdded = true;
            break;
        }
    
    //Printing a message that the item is added successfully if it is added
    //Or that it is not added if all pointers in the array are assigned.
    cout << "\n---------------------------------------------\n";
    
    if (itemAdded)
    {
        //this->cost += item->GetCost();
        
        cout << "\'";
        item->Print();
        cout << "\' Added Successfully." << endl;
    }
    else
    {
        cout << "Max number of items reached: \'";//. Item: ";
        item->Print();
        cout << "\' Was Not Added Successfully." << endl;
    }
    
    cout << "---------------------------------------------\n";
}

void CustomerOrder::RemoveFoodItem(Food* item)
{
    bool itemRemoved = false;
    
    //search for the item in the array of OrderedItems
    for (int i = 0; i < 3; i++)
        if (this->OrderedItems[i] != nullptr)
            if (this->OrderedItems[i]->GetCost() == item->GetCost()
                && this->OrderedItems[i]->GetSize() == item->GetSize())
            {
                itemRemoved = true;
                delete this->OrderedItems[i];
                this->OrderedItems[i] = nullptr;
                break;
            }
    
    
    //Printing a message that the item is removed successfully if it is removed
    //Or that it is not removed if it is not found in the array of Ordereditems.
    cout << "\n---------------------------------------------\n";
    
    if (itemRemoved)
    {
        cout << "\'";
        item->Print();
        cout << "\' Removed Successfully." << endl;
    }
    else
    {
        cout << "\'";//. Item: ";
        item->Print();
        cout << "\' Was Not Removed... No Such Item in the Customer\'s order." << endl;
    }
    
    cout << "---------------------------------------------\n";
}

double CustomerOrder::GetOrderCost()
{
    this->cost = 0;
    
    //calculate the total cost of all objects pointed to
    //by the pointers in the OrderedItems array
    for (int i = 0; i < 3; i++)
        if (this->OrderedItems[i] != nullptr)
            this->cost += OrderedItems[i]->GetCost();
    
    return this->cost;
}

void CustomerOrder::Print()
{
    //cout << "Ordered Items:" << endl;
    for (int i = 0; i < 3; i++)
        if (this->OrderedItems[i] != nullptr)
        {
            cout << "\t\t";
            OrderedItems[i]->Print();
            cout << endl;
        }
    
    cout << "\t\tTotal Order Cost: $" << this->GetOrderCost();// << endl;
        
}

CustomerOrder::~CustomerOrder()
{
    for (int i = 0; i < 3; i++)
        if (OrderedItems[i] != nullptr)
            delete OrderedItems[i];
}
