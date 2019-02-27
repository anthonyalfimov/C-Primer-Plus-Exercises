//
//  Cow1201.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 27/02/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include <cstring>
#include "Cow1201.hpp"

namespace e1201
{
    Cow::Cow()
    {
        m_name[0] = '\0';
        m_hobby = new char[1];
        m_hobby[0] = '\0';
        m_weight = 0;
    }
    
    Cow::Cow(const char* name, const char* hobby, double weight)
    {
        // Copy name string to the member array and ensure null-termination
        std::strncpy(m_name, name, s_size);
        m_name[s_size - 1] = '\0';
        
        // Allocate and populate storage for hobby string
        int len = static_cast<int>(std::strlen(hobby));
        m_hobby = new char[len + 1];
        strcpy(m_hobby, hobby);
        
        m_weight = weight;
    }
    
    Cow::Cow(const Cow& otherCow)
    {
        // Copy the name
        std::strcpy(m_name, otherCow.m_name);
        
        // Copy the hobby
        int len = static_cast<int>(std::strlen(otherCow.m_hobby));
        m_hobby = new char[len + 1];
        std::strcpy(m_hobby, otherCow.m_hobby);
        
        // Copy the weight
        m_weight = otherCow.m_weight;
    }
    
    Cow::~Cow()
    {
        delete [] m_hobby;                              // deallocate hobby string
    }
    
    Cow& Cow::operator=(const Cow& otherCow)
    {
        if (this == &otherCow)                          // prevent self-copying
            return *this;
        
        // Copy the name
        std::strcpy(m_name, otherCow.m_name);
        
        // Copy the hobby
        delete [] m_hobby;                              // deallocate existing hobby string
        int len = static_cast<int>(std::strlen(otherCow.m_hobby));
        m_hobby = new char[len + 1];
        std::strcpy(m_hobby, otherCow.m_hobby);
        
        // Copy the weight
        m_weight = otherCow.m_weight;
        
        return *this;
    }
    
    void Cow::show() const
    {
        std::cout
            << "Cow:    " << m_name << "\n"
            << "Hobby:  " << m_hobby << "\n"
            << "Weight: " << m_weight << " kg\n";
    }
}   // end namespace e1201
