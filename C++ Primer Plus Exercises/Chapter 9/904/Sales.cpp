//
//  Sales.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 19/11/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include "Sales.hpp"
#include <iostream>

namespace SALES
{
    void clearInputBuffer()                             // clear trailing input and '\n' from buffer
    {
        while (std::cin.get() != '\n')
            continue;
    }
    
    void setSales(Sales& s, const double data[], int size)
    {
        int count {size < QUARTERS ? size : QUARTERS};  // number of sales entries to copy
        
        if (size == 0)
        {
            std::cout << "setSales() error: empty array passed\n";
            s.average = s.max = s.min = 0;
        }
        else
        {
            // Initialize calculated values:
            s.average = 0;
            s.max = data[0];
            s.min = data[0];
            
            for (int i = 0; i < count; i++)
            {
                s.sales[i] = data[i];                       // copy data over from passed array
                s.average += data[i];                       // add data to average calculation
                if (data[i] > s.max)                        // update max
                    s.max = data[i];
                else if (data[i] < s.min)                   // update min
                    s.min = data[i];
            }
            s.average /= count;                             // calculate average
        }
        
        for (int i = count; i < QUARTERS; i++)              // set remaining elements (if any) to 0
            s.sales[i] = 0;
    }
    
    void setSales(Sales& s)
    {
        std::cout << "Enter quarterly sales (q to quit):\n";
        int count;
        for (count = 0; count < QUARTERS; count++)
        {
            std::cout << "Q" << count + 1 << ": ";
            if (!(std::cin >> s.sales[count]) || s.sales[count] < 0)
            {
                std::cin.clear();
                clearInputBuffer();
                break;
            }
            clearInputBuffer();
        }
        
        // Performs unnecessary operations, but DRY and cute
        setSales(s, s.sales, count);
    }
    
    void showSales(const Sales& s)
    {
        std::cout << "Quarterly sales:\n";
        for (int i = 0; i < QUARTERS; i++)
            std::cout << "Q" << i + 1 << ": $" << s.sales[i] << "\n";
        std::cout
            << "Average: $" << s.average << "\n"
            << "Max:     $" << s.max     << "\n"
            << "Min:     $" << s.min     << "\n";
    }
}
