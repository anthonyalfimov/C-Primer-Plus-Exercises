//
//  classic1302.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 12/04/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include <cstring>
#include "classic1302.hpp"

namespace e1302
{
    Classic::Classic(const char* primary, const char* performers,
                     const char* label, int selections, double playtime)
        : CD(performers, label, selections, playtime)
    {
        m_primary = new char[std::strlen(primary) + 1];
        std::strcpy(m_primary, primary);
        
    #ifdef VERBOSE_CD
        std::cout << "|> Classic constructor for \""  << getLabel() << "\"\n";
    #endif
    }
    
    Classic::Classic(const char* primary, const CD& cd_disk) : CD(cd_disk)
    {
        m_primary = new char[std::strlen(primary) + 1];
        std::strcpy(m_primary, primary);
        
    #ifdef VERBOSE_CD
        std::cout << "|> Classic constructor for \""  << getLabel() << "\"\n";
    #endif
    }
    
    Classic::Classic() : CD()
    {
        m_primary = new char[std::strlen("none") + 1];
        std::strcpy(m_primary, "none");
        
    #ifdef VERBOSE_CD
        std::cout << "|> Classic constructor for \""  << getLabel() << "\"\n";
    #endif
    }
    
    Classic::Classic(const Classic& cl_disk) : CD(cl_disk)
    {
        m_primary = new char[std::strlen(cl_disk.m_primary) + 1];
        std::strcpy(m_primary, cl_disk.m_primary);
        
    #ifdef VERBOSE_CD
        std::cout << "|> Classic copy constructor for \""  << getLabel() << "\"\n";
    #endif
    }

    Classic::~Classic()
    {
    #ifdef VERBOSE_CD
        std::cout << "|> Classic destructor for \""  << getLabel() << "\"... ";
    #endif
        
        delete [] m_primary;
        
    #ifdef VERBOSE_CD
        std::cout << "done\n";
    #endif
    }
    
    Classic& Classic::operator=(const Classic& cl_disk)
    {
        if (this == &cl_disk)                   // prevent self-copying
            return *this;
        
        CD::operator=(cl_disk);                 // call base-class assignment
        delete [] m_primary;                    // deallocate previous data
        
        m_primary = new char[std::strlen(cl_disk.m_primary) + 1];
        std::strcpy(m_primary, cl_disk.m_primary);
        
    #ifdef VERBOSE_CD
        std::cout << "|> Classic assignment for \""  << getLabel() << "\"\n";
    #endif
        
        return *this;
    }
    
    void Classic::report() const
    {
        CD::report();
        std::cout
            << "Genre: Classical\n"
            << "Primary work: " << m_primary << "\n";
    }
}
