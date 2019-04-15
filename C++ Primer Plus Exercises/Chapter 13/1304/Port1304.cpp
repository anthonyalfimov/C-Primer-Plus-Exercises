//
//  Port1304.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 15/04/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <cstring>
#include "Port1304.hpp"

namespace e1304
{
    Port::Port(const char* brand, const char* style, int bottles)
    {
        m_brand = new char[std::strlen(brand) + 1];
        std::strcpy(m_brand, brand);
    
        std::strncpy(m_style, style, c_styleLength);
        m_style[c_styleLength - 1] = '\0';
        
        m_bottles = bottles < 0 ? 0 : bottles;
    }
    
    Port::Port(const Port& p) : m_bottles(p.m_bottles)
    {
        m_brand = new char[std::strlen(p.m_brand) + 1];
        std::strcpy(m_brand, p.m_brand);
        
        std::strcpy(m_style, p.m_style);
    }
    
    Port& Port::operator=(const Port& p)
    {
        if (this == &p)                             // prevent self-copy
            return *this;
        
        delete [] m_brand;                          // delete old data
        m_brand = new char[std::strlen(p.m_brand) + 1];
        std::strcpy(m_brand, p.m_brand);
        
        std::strcpy(m_style, p.m_style);
        m_bottles = p.m_bottles;
        
        return *this;
    }
    
    Port& Port::operator+=(int bottles)
    {
        m_bottles += bottles;
        return *this;
    }
    
    Port& Port::operator-=(int bottles)
    {
        if (m_bottles < bottles)
        {
            std::cout << "Warning! " << bottles - m_bottles << " bottles out of requested "
                      << bottles << " cannot be supplied!\n";
            m_bottles = 0;
        }
        else
            m_bottles -= bottles;
        
        return *this;
    }

    void Port::show() const
    {
        std::cout
            << "Brand: " << m_brand << "\n"
            << "Style: " << m_style << "\n"
            << "Bottles: " << m_bottles << "\n";
    }
    
    std::ostream& operator<<(std::ostream& os, const Port& p)
    {
        os << p.m_brand << ", " << p.m_style << ", " << p.m_bottles;
        return os;
    }
    
}
