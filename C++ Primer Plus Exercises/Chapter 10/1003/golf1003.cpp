//
//  golf1003.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 04/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
#include <cstring>
#include "golf1003.hpp"


Golf::Golf(const char *fullName, int handicap)
{
    std::strncpy(m_fullName, fullName, nameLength);
    m_fullName[nameLength - 1] = '\0';              // ensure null-termination
    
    m_handicap = handicap;
}


bool Golf::set()
{
    std::cout << "Full name: ";
    if (!std::cin.get(m_fullName, nameLength))      // if an empty string is read
    {
        std::cin.clear();                           // clear failbit
        std::cin.get();                             // read trailing '\n'
        return false;                               // report reading empty string
    }
    
    clearInputBuffer();                             // remove leftover input and '\n' from buffer
    
    std::cout << "Handicap: ";
    while (!(std::cin >> m_handicap) || m_handicap < 0)
    {
        std::cout << "Invalid input, try again: ";
        std::cin.clear();                           // in case failbit was set, clear it
        clearInputBuffer();                         // remove leftover input
    }
    
    clearInputBuffer();                             // remove leftover input
    return true;                                    // report successful input
}


const Golf& Golf::handicap(int newHandicap, bool isVerbose)
{
    if (isVerbose)
        std::cout
            << "Handicap for " << m_fullName << " changed from "
            << m_handicap << " to " << newHandicap << "\n";
    m_handicap = newHandicap;
    
    return *this;
}


void Golf::show() const
{ 
    std::cout << "> " << m_fullName << ", handicap: " << m_handicap << "\n";
}
