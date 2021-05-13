//
//  FoodManager.hpp
//  Assignment4COEN244
//
//  Created by Mohammad Altahat on 2020-11-05.
//

#pragma once

#include "TableOrder.h"

class FoodManager
{
    private:
        
        TableOrder** tableOrders;
        
    public:
        
        FoodManager();
    
        ~FoodManager();
    
        int GetTable(int);
        
        void GetTableOrder(int);
        
        bool CancelOrder(int);
        
        bool TableAvailable(int);
        
        bool Print(int);
        
        int Search(int);
    
        void PrintAllOccupiedTables();
};


