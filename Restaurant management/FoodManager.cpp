//
//  FoodManager.cpp
//  Assignment4COEN244
//
//  Created by Mohammad Altahat on 2020-11-05.
//

#include "FoodManager.h"
#include "VegetarianPizza.h"
#include "AllDressedPizza.h"
#include "SoftDrink.h"
#include "Salad.h"

//Default Constructor
FoodManager::FoodManager()
{
    this->tableOrders = new TableOrder*[41];
    
    //create 10 tables with 2 seats
    for (int i = 1; i < 11; i++)
        tableOrders[i] = new TableOrder(i, 2);
    
    //create 20 tables with 4 seats
    for (int i = 11; i < 31; i++)
        tableOrders[i] = new TableOrder(i, 4);
    
    //create 10 tables with 6 seats
    for (int i = 31; i < 41; i++)
        tableOrders[i] = new TableOrder(i, 6);
}

//Functin to reserve a table with requested seats number and return the table number
int FoodManager::GetTable(int seats)
{
    int tableNum = 0;
    
    //search for the first available (non reserved) table with the requested seats number
    if (seats == 2)
    {
        for (int i = 1; i < 11; i++)
            if (tableOrders[i]->GetTableStatus())
            {
                tableNum = i;
                break;
            }
    }
    else if (seats == 4)
    {
        for (int i = 11; i < 31; i++)
            if (tableOrders[i]->GetTableStatus())
            {
                tableNum = i;
                break;
            }
    }
    else if (seats == 6)
    {
        for (int i = 31; i < 41; i++)
            if (tableOrders[i]->GetTableStatus())
            {
                tableNum = i;
                break;
            }
    }
    
    //reserve the found table
    if (tableNum != 0)
        tableOrders[tableNum]->SetTableStatus(false);
        
    return tableNum;
}

//Take order for the requeted table
void FoodManager::GetTableOrder(int tableNum)
{
    if (tableNum > 0 && tableNum < 41)
    {
        //table must be already reserved
        if (!tableOrders[tableNum]->GetTableStatus())
        {
            int seats = tableOrders[tableNum]->GetSeats();
            
            cout << "Getting Table number " << tableNum << " with " << seats << " seats." << endl;
            
            delete tableOrders[tableNum];      //delete the old object
            
            tableOrders[tableNum] = new TableOrder(tableNum, seats);   //create a new object
            
            tableOrders[tableNum]->SetTableStatus(false);
            
            //Take orders for all customers on this table
            for (int i = 0; i < seats; i++)
            {
                CustomerOrder* ptrCustomerOrder = new CustomerOrder();
                
                cout << "Entering Customer " << (i+1) << " orders:" << endl;
                
                int numOfOrders;
                cout << "How many orders? (0 - 3) ";
                cin >> numOfOrders;
                
                if (numOfOrders > 3)
                {
                    cout << "Maximum number of orders allowed is 3. Try Again." << endl;
                    i--;
                    continue;
                }
                
                Food * ptrOrders = nullptr;
                
                for (int j = 0; j < numOfOrders; j++)
                {
                    int orderType;
                    cout << "Entering Order " << (j+1) << ":" << endl;
                    cout << "What would you like to order?" << endl;
                    cout << "[1] Vegetarian Pizza" << endl;
                    cout << "[2] All Dressed Pizza" << endl;
                    cout << "[3] Salad" << endl;
                    cout << "[4] Soft Drink" << endl;
                    cin >> orderType;
                    
                    string orderSize;

                    bool canAddFood = true;
                    
                    switch (orderType)
                    {
                        case 1: //Vegeterian Pizza
                            cout << "What size?" << endl;
                            cout << "Small: $" << 5 << endl;
                            cout << "Medium: $" << (5*1.5) << endl;
                            cout << "Large: $" << (5*2) << endl;
                            cin >> orderSize;       //Entered size must be string (Small, Medium, Large)
                            
                            ptrOrders = new VegetarianPizza(orderSize);
                            
                            break;
                            
                        case 2:     //All Dressed Pizza
                            cout << "What size?" << endl;
                            cout << "Small: $" << 8 << endl;
                            cout << "Medium: $" << (8*1.5) << endl;
                            cout << "Large: $" << (8*2) << endl;
                            cin >> orderSize;       //Entered size must be string (Small, Medium, Large)
                            
                            ptrOrders = new AllDressedPizza(orderSize);
                            
                            break;
                            
                        case 3:     //Salad
                            cout << "What size?" << endl;
                            cout << "Small: $" << 4 << endl;
                            cout << "Medium: $" << (4*1.5) << endl;
                            cout << "Large: $" << (4*2) << endl;
                            cin >> orderSize;       //Entered size must be string (Small, Medium, Large)
                            
                            ptrOrders = new Salad(orderSize);
                            
                            break;
                            
                        case 4:     //Soft Drink
                            cout << "What size?" << endl;
                            cout << "Small: $" << 2 << endl;
                            cout << "Medium: $" << (2*1.5) << endl;
                            cout << "Large: $" << (2*2) << endl;
                            cin >> orderSize;       //Entered size must be string (Small, Medium, Large)
                            
                            ptrOrders = new SoftDrink(orderSize);
                            
                            break;
                            
                        default:
                            cout << "Wrong Order Type, Entering order again." << endl;
                            canAddFood = false;
                            j--;
                    }
                    
                    //Add this food item to customer order
                    if (canAddFood)
                        ptrCustomerOrder->AddFoodItem(ptrOrders);
            
                }
                
                //Insert the customer order to the orders of this table
                tableOrders[tableNum]->InsertOrder(ptrCustomerOrder);
                
            }
            
            tableOrders[tableNum]->SetTableOrderNum();
            
            cout << "Orders for Table " << tableNum << " Were Taken Successfully." << endl;
        }
        else
           cout << "This table is not reserved for customers." << endl;
    }
    else
        cout << "No table with this number." << endl;
}

//Cancel the order on a table but keep the table reserved
bool FoodManager::CancelOrder(int tableNum)
{
    if (tableNum > 0 && tableNum < 41)
    {
        // check if table is occupied
        if (!tableOrders[tableNum]->GetTableStatus())
            return tableOrders[tableNum]->CancelCustomerOrders();
    }
    
    return false;
}

//Cancel the reservation of the requested table
bool FoodManager::TableAvailable(int tableNum)
{
    if (tableNum > 0 && tableNum < 41)
    {
        // check if table is occupied
        if (!tableOrders[tableNum]->GetTableStatus())
        {
            //Delete all cutomer orders
            this->CancelOrder(tableNum);
            
            int seats = tableOrders[tableNum]->GetSeats();
            
            delete tableOrders[tableNum];   //delete the old object
            
            tableOrders[tableNum] = new TableOrder(seats, tableNum);  //create a new object
            
            return true;
        }
    }
    
    return false;
}

bool FoodManager::Print(int tableNum)
{
    if (tableNum > 0 && tableNum < 41)
        // check if table is occupied
        if (!tableOrders[tableNum]->GetTableStatus())
        {
            tableOrders[tableNum]->Print();
            return true;
        }
    
    return false;
}

//return the order number of the requested table
int FoodManager::Search(int tableNum)
{
    if (tableNum > 0 && tableNum < 41)
        // check if table is occupied
        if (!tableOrders[tableNum]->GetTableStatus())
            return tableOrders[tableNum]->GetTableOrderNum();
    
    return 0;
}

//Extra function just that prints the number of all reserved tables with all seats sizes
void FoodManager::PrintAllOccupiedTables()
{
    cout << "Occupied Tables: " << endl;

    bool foundAny = false;
    
    for (int i = 1; i < 41; i++)
        if (!tableOrders[i]->GetTableStatus())
        {
            cout << "\t" << i;
            foundAny = true;
        }
    
    if (!foundAny)
        cout << "\tNo Occupied Tables";
    cout << endl;
}

FoodManager::~FoodManager()
{    
    for (int i = 0; i < 41; i++)
        if (this->tableOrders[i] != nullptr)
            delete this->tableOrders[i];
    
    if (this->tableOrders != nullptr)
        delete[] this->tableOrders;
}
