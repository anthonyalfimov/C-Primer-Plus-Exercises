//
//  Sales.hpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 19/11/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#ifndef Sales_hpp
#define Sales_hpp

namespace SALES
{
    constexpr int QUARTERS {4};
    
    struct Sales
    {
        double sales[QUARTERS];
        double average;
        double max;
        double min;
    };
    
    /**
     Copies the lesser of 4 or n items from the array ar
     to the `sales` member of passed struct and computes
     and stores the average, maximum, and minimum values of entered items;
     remaining elements of sales, if any, set to 0

     @param data Sales array
     @param size Sales array size
     */
    void setSales(Sales&, const double data[], int size);
    
    /**
     Gathers sales for 4 quarters interactively, stores them
     in the sales member of passed struct and computes and stores the
     average, maximum, and minimum values
     */
    void setSales(Sales&);
    
    /**
     Display all information in passed Sales stuct
     */
    void showSales(const Sales&);
}

#endif /* Sales_hpp */
