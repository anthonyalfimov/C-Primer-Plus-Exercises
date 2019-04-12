//
//  cd1302.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 12/04/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include <cstring>
#include "cd1302.hpp"

namespace e1302
{
    CD::CD(const char* performers, const char* label, int selections, double playtime)
    {
        m_performers = new char[std::strlen(performers) + 1];
        std::strcpy(m_performers, performers);
        
        m_label = new char[std::strlen(label) + 1];
        std::strcpy(m_label, label);
        
        m_selections = selections >= 0 ? selections : 0;
        m_playtime = playtime >= 0.0 ? playtime : 0.0;
        
    #ifdef VERBOSE_CD
        std::cout << "|> CD constructor for \""  << m_label << "\"\n";
    #endif
    }
    
    CD::CD() : CD("none", "none", 0, 0.0) {}        // delegating constructor

    CD::CD(const CD& disk) : m_selections(disk.m_selections), m_playtime(disk.m_playtime)
    {
        m_performers = new char[std::strlen(disk.m_performers) + 1];
        std::strcpy(m_performers, disk.m_performers);
        
        m_label = new char[std::strlen(disk.m_label) + 1];
        std::strcpy(m_label, disk.m_label);
    #ifdef VERBOSE_CD
        std::cout << "|> CD copy constructor for \""  << m_label << "\"\n";
    #endif
    }
    
    CD::~CD()
    {
    #ifdef VERBOSE_CD
        std::cout << "|> CD destructor for \""  << m_label << "\"... ";
    #endif
        
        delete [] m_label;
        delete [] m_performers;
    
    #ifdef VERBOSE_CD
        std::cout << "done\n";
    #endif
    }
    
    CD& CD::operator=(const CD& disk)
    {
        if (this == &disk)                  // prevent self-copying
            return *this;
        
        delete [] m_label;                  // deallocate previous data
        delete [] m_performers;
        
        m_performers = new char[std::strlen(disk.m_performers) + 1];
        std::strcpy(m_performers, disk.m_performers);
        
        m_label = new char[std::strlen(disk.m_label) + 1];
        std::strcpy(m_label, disk.m_label);
        
        m_selections = disk.m_selections;
        m_playtime = disk.m_playtime;
        
    #ifdef VERBOSE_CD
        std::cout << "|> CD assignment for \""  << m_label << "\"\n";
    #endif
        
        return *this;
    }
    
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
