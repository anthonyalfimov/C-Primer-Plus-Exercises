//
//  Person1002.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 03/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include "Person1002.hpp"
#include <iostream>
#include <string>
#include <cstring>


Person::Person(const std::string &lastName, const char *firstName)
{
    m_lastName = lastName;
    std::strncpy(m_firstName, firstName, nameLenght);
    m_firstName[nameLenght - 1] = '\0';     // ensure null-termination
}


void Person::show() const
{
    std::cout << m_firstName << " " << m_lastName;
}


void Person::formalShow() const
{ 
    std::cout << m_lastName << ", " << m_firstName;
}
