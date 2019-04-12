//
//  classic1301.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 12/04/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <cstring>
#include <iostream>
#include "classic1301.hpp"

namespace e1301
{
    Classic::Classic(const char* primary, const char* performers,
                     const char* label, int selections, double playtime)
        : CD(performers, label, selections, playtime)
    {
        std::strncpy(m_primary, primary, c_primaryLength);
        m_primary[c_primaryLength - 1] = '\0';
    }
    
    Classic::Classic(const char* primary, const CD& disk) : CD(disk)
    {
        std::strncpy(m_primary, primary, c_primaryLength);
        m_primary[c_primaryLength - 1] = '\0';
    }
    
    Classic::Classic() : CD()
    {
        std::strncpy(m_primary, "none", c_primaryLength);
        m_primary[c_primaryLength - 1] = '\0';
    }
    
    void Classic::report() const
    {
        CD::report();
        std::cout
            << "Genre: Classical\n"
            << "Primary work: " << m_primary << "\n";
    }
}
