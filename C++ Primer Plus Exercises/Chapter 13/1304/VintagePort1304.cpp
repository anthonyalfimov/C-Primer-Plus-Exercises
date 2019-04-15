//
//  VintagePort1304.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 15/04/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <cstring>
#include "VintagePort1304.hpp"

namespace e1304
{
    VintagePort::VintagePort(const char* brand, int bottles, const char* nickname, int year)
        : Port(brand, "vintage", bottles), m_year(year)
    {
        m_nickname = new char[std::strlen(nickname) + 1];
        std::strcpy(m_nickname, nickname);
    }
    
    VintagePort::VintagePort() : VintagePort("none", 0, "dummy", 1990) {} // delegating ctor
    
    VintagePort::VintagePort(const VintagePort& vp) : Port(vp), m_year(vp.m_year)
    {
        m_nickname = new char[std::strlen(vp.m_nickname) + 1];
        std::strcpy(m_nickname, vp.m_nickname);
    }
    
    VintagePort& VintagePort::operator=(const VintagePort& vp)
    {
        if (this == &vp)                        // prevent self-copy
            return *this;
        
        delete [] m_nickname;                   // delete old data
        m_nickname = new char[std::strlen(vp.m_nickname) + 1];
        std::strcpy(m_nickname, vp.m_nickname);
        
        m_year = vp.m_year;
        
        return *this;
    }

    void VintagePort::show() const
    {
        Port::show();
        std::cout
            << "Nickname: " << m_nickname << "\n"
            << "Year: " << m_year << "\n";
    
    }
    
    std::ostream& operator<<(std::ostream& os, const VintagePort& vp)
    {
        os << (const Port&) vp;                 // cast to base-class type to use its friend
        os << ", " << vp.m_nickname << ", " << vp.m_year;
        return os;
    }
}
