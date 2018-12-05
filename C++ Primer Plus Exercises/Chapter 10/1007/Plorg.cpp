//
//  Plorg.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 05/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
#include <cstring>
#include "Plorg.hpp"

Plorg::Plorg(const char *name)
{
    std::strncpy(m_name, name, nameLength);
    m_name[nameLength - 1] = '\0';          // Ensure null-termination
    m_cIndex = 50;
}

void Plorg::cUpdate(int cIndex, bool isVerbose)
{
    if (isVerbose)
    {
        if (cIndex == m_cIndex)
            std::cout
                << m_name << "'s contentment index remains unchanged.\n";
        else if (cIndex > m_cIndex)
            std::cout
                << m_name << "'s contentment index rose from " << m_cIndex
                << " to " << cIndex << ".\nGood for " << m_name << "!\n";
        else
            std::cout
            << m_name << "'s contentment index dropped from " << m_cIndex
            << " down to " << cIndex << ".\nA pity, really.\n";
    }
    m_cIndex = cIndex;
}

void Plorg::report() const
{
    std::cout << m_name << "'s contentment index is at " << m_cIndex << "\n";
}
