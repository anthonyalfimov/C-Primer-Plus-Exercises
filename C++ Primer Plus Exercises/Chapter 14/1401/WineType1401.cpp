//
//  WineType1401.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 26/06/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "WineType1401.hpp"

namespace e1401
{
    Wine::Wine (const char* label, int yearCount, const int years[], const int bottles[])
        : mLabel (label), mYearCount (yearCount),
          mYearsAndBottles (ArrayInt (years, yearCount), ArrayInt (bottles, yearCount))
    {}
    
    Wine::Wine (const char* label, int yearCount)
        : mLabel (label), mYearCount (yearCount),
          mYearsAndBottles (ArrayInt (yearCount), ArrayInt (yearCount))
    {}
    
    
    void Wine::inputYearsAndBottles()
    {
        std::cout << "Please, enter data for " << mYearCount << " year(s):\n";
        int inputYear, inputBottles;
        
        for (int i = 0; i < mYearCount; ++i)
        {
            std::cout << "Enter year: ";
            
            while (! (std::cin >> inputYear))
            {
                std::cin.clear();
                while (std::cin.get() != '\n')
                    continue;
                std::cout << "Invalid! Enter year: ";
            }
            
            mYearsAndBottles.first()[i] = inputYear;
            
            while (std::cin.get() != '\n')
                continue;
            
            std::cout << "Enter number of " << inputYear << " bottles: ";
            
            while (! (std::cin >> inputBottles))
            {
                std::cin.clear();
                while (std::cin.get() != '\n')
                    continue;
                std::cout << "Invalid! Enter number of bottles: ";
            }
            
            mYearsAndBottles.second()[i] = inputBottles;
            
            while (std::cin.get() != '\n')
                continue;
        }
    }
    
    void Wine::display() const
    {
        std::cout << "Wine: " << mLabel << "\n"
                  << "\tYear\tBottles\n";
        
        for (int i = 0; i < mYearCount; ++i)
            std::cout << "\t" << mYearsAndBottles.first()[i]
                      << "\t" << mYearsAndBottles.second()[i] << "\n";
    }
}
