//
//  Sales1004.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 04/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include "Sales1004.hpp"

namespace SALES
{
    void Sales::update(int entries)
    {
        int count {entries < quaters ? entries : quaters};      // number of entries to consider
        
        if (entries < 1)                        // if no entries are to be considered for the update
        {
            m_average = 0;                      // set all stats to zero
            m_max = 0;
            m_min = 0;
        }
        else
        {
            m_average = 0;
            m_min = m_sales[0];
            m_max = m_sales[0];
            
            for (int i = 0; i < count; i++)
            {
                m_average += m_sales[i];        // add to average calculation
                if (m_sales[i] > m_max)
                    m_max = m_sales[i];         // update max
                else if (m_sales[i] < m_min)
                    m_min = m_sales[i];         // update min
            }
            m_average /= count;
        }
        
        for (int i = count; i < quaters; i++)   // set the unused entries (if any) to -1
            m_sales[i] = -1;                    //     to mark them as invalid
    }
    
    Sales::Sales(const double data[], int size)
    {
        int count {size < quaters ? size : quaters};    // number of elements to copy over
        for (int i = 0; i < count; i++)
            m_sales[i] = data[i];
 
        update(count);                                  // update stats based on the copied data
    }

    void Sales::set()
    {
        // The task requires to use the constructor here, although
        // I would prefer to read data into `m_sales` and then run `update(count)`
        
        std::cout << "Enter quarterly sales (q to quit):\n";
        int count;
        double data[quaters];
        
        for (count = 0; count < quaters; count++)
        {
            std::cout << "Q" << count + 1 << ": ";
            if (!(std::cin >> data[count]) || data[count] < 0)
            {
                std::cin.clear();
                clearInputBuffer();
                break;
            }
            clearInputBuffer();
        }
        
        *this = Sales(data, count);
    }

    void Sales::show() const
    {
        std::cout << "Quarterly sales:\n";
        for (int i = 0; i < quaters; i++)
            if (m_sales[i] >= 0)                    // show only valid sales data
                std::cout << "Q" << i + 1 << ": $" << m_sales[i] << "\n";
        std::cout
            << "Average: $" << m_average << "\n"
            << "Max:     $" << m_max     << "\n"
            << "Min:     $" << m_min     << "\n";
    }
}
