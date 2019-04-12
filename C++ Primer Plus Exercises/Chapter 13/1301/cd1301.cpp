//
//  cd1301.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 12/04/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <cstring>
#include <iostream>
#include "cd1301.hpp"

namespace e1301
{
    CD::CD(const char* performers, const char* label, int selections, double playtime)
    {
        std::strncpy(m_performers, performers, c_perfLength);
        m_performers[c_perfLength - 1] = '\0';
        
        std::strncpy(m_label, label, c_labelLength);
        m_label[c_labelLength - 1] = '\0';
        
        m_selections = selections >= 0 ? selections : 0;
        m_playtime = playtime >= 0.0 ? playtime : 0.0;
    }
    
    CD::CD() : CD("none", "none", 0, 0.0) {}        // delegating constructor
    
    void CD::report() const
    {
        std::cout
            << "=========[ CD ]=========\n"
            << "Label: " << m_label << "\n"
            << "Performers: " << m_performers << "\n"
            << "Selections: " << m_selections << "\n"
            << "Playtime: " << m_playtime << " minutes\n";
    }
}
