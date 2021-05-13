//
//  TableOrder.hpp
//  Assignment4COEN244
//
//  Created by Mohammad Altahat on 2020-11-05.
//

#pragma once

#include "CustomerOrder.h"

class TableOrder
{
    private:
        int tableNum;
        bool tableStatus;   //False: occupied, True: available
        int seats;
        static int orderNo;
        int myOrderNo;
        CustomerOrder** customerOrders;
        double totalCost;
        
    public:
        
        TableOrder();
        TableOrder(int, int);
        ~TableOrder();
        double GetTotalCost();
        void Print();
        void InsertOrder(CustomerOrder*);
        bool GetTableStatus();
        int GetSeats();
        bool CancelCustomerOrders();
        int GetTableOrderNum();
        void SetTableStatus(bool);
        void SetTableOrderNum();
    
};
