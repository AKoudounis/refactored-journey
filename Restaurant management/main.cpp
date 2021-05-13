//
//  main.cpp
//  Assignment4COEN244
//
//  Created by Mohammad Altahat on 2020-11-05.
//

#include "Food.h"
#include "VegetarianPizza.h"
#include "AllDressedPizza.h"
#include "SoftDrink.h"
#include "Salad.h"
#include "CustomerOrder.h"
#include "TableOrder.h"
#include "FoodManager.h"

int main()
{
    //create food manager object
    FoodManager foodmanager;
    
    while(true)
    {
        //Interafce List
        cout << "-------------------------------" << endl;
        cout << "COEN 244 Assignment 4 Main Menu" << endl;
        cout << "-------------------------------" << endl;
        cout << "What would you like to do?" << endl;
        cout << "[1] Get a Table" << endl;
        cout << "[2] Get Table Order" << endl;
        cout << "[3] Cancel Order" << endl;
        cout << "[4] Make Table Available" << endl;
        cout << "[5] Print Table Details" << endl;
        cout << "[6] Search Table Order Num" << endl;
        cout << "[7] Show Occupied Tables Numbers" << endl;
        cout << "[8] Exit" << endl;
        
        int choice;
        cin >> choice;
        
        switch (choice)
        {
            case 1:     //Get a Table - Reserve a table with a requested seats size
            {
                int seats;
                cout << "How many seats? (2, 4, 6)" << endl;
                cin >> seats;
                
                int tableNum = foodmanager.GetTable(seats);
                
                if (tableNum == 0)
                    cout << "Cannot Get a Table With This Size." << endl;
                else
                    cout << "Table Number " << tableNum << " is Now Reserved" << endl;
                
                break;
            }
            case 2:     //Get Table Order
            {
                int tableNum;
                cout << "Enter the Table Number:" << endl;
                cin >> tableNum;
                
                foodmanager.GetTableOrder(tableNum);
                
                break;
            }
            case 3: //Canceling an order
            {
                int tableNum;
                cout << "Enter the Table Number:" << endl;
                cin >> tableNum;
                
                if (foodmanager.CancelOrder(tableNum))
                    cout << "Order of Table " << tableNum << " Cancelled Successfully" << endl;
                else
                    cout << "Was Not Able to Cancel Order of Table " << tableNum << endl;
                
                break;
            }
            case 4: //Making a table available
            {
                int tableNum;
                cout << "Enter the Table Number:" << endl;
                cin >> tableNum;
                
                if (foodmanager.TableAvailable(tableNum))
                    cout << "Table " << tableNum << " is Now Available." << endl;
                else
                    cout << "Was Not Able to Make Table " << tableNum << " Available." << endl;
                
                break;
            }
            case 5: //Printing table info
            {
                int tableNum;
                cout << "Enter the Table Number:" << endl;
                cin >> tableNum;
                
                if (!foodmanager.Print(tableNum))
                    cout << "Cannot Print Details of Table " << tableNum << endl;
                
                break;
            }
            case 6: //Search Table Order Num
            {
                int tableNum;
                cout << "Enter the Table Number:" << endl;
                cin >> tableNum;
                
                int orderNum = foodmanager.Search(tableNum);
                
                if (orderNum == 0)
                    cout << "Cannot Get Order Number For Table " << tableNum << endl;
                else
                    cout << "Order Number of Table " << tableNum << ": " << orderNum << endl;
                
                break;
            }
            case 7: //Show Occupied Tables Numbers
            {
                foodmanager.PrintAllOccupiedTables();
                
                break;
            }
            case 8: //Exit the program
            {
                return 0;
            }

        } // end of switch
        
        
    }
    
	return 0;
}
