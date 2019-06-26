//
//  WineType1402.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 26/06/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "WineType1402.hpp"

namespace e1402
{
    Wine::Wine (const char* label, int yearCount, const int years[], const int bottles[])
        : std::string (label), mYearCount (yearCount),
          PairArrayInt (ArrayInt (years, yearCount), ArrayInt (bottles, yearCount))
    {}
    
    Wine::Wine (const char* label, int yearCount)
        : std::string (label), mYearCount (yearCount),
          PairArrayInt (ArrayInt (yearCount), ArrayInt (yearCount))
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
            
            PairArrayInt::first()[i] = inputYear;
            
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
            
            PairArrayInt::second()[i] = inputBottles;
            
            while (std::cin.get() != '\n')
                continue;
        }
    }
    
    void Wine::display() const
    {
        std::cout << "Wine: " << (const std::string&) *this << "\n"
                  << "\tYear\tBottles\n";
        
        for (int i = 0; i < mYearCount; ++i)
            std::cout << "\t" << PairArrayInt::first()[i]
                      << "\t" << PairArrayInt::second()[i] << "\n";
    }
}   // end namespace e1402

