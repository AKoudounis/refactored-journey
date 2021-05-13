//
//  CustomerOrder.hpp
//  Assignment4COEN244
//
//  Created by Mohammad Altahat on 2020-11-05.
//

#pragma once

#include "Food.h"

class CustomerOrder
{
    private:
    
        Food* OrderedItems[3];
        double cost;
    
    public:
    
        CustomerOrder();
        
        ~CustomerOrder();
        
        void AddFoodItem(Food*);
    
        void RemoveFoodItem(Food*);
    
        double GetOrderCost();
        
        void Print();
};
