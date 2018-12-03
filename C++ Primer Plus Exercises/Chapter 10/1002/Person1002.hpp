//
//  Person1002.hpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 03/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#ifndef Person1002_hpp
#define Person1002_hpp

#include <string>

class Person
{
private:
    static const int nameLenght {25};
    std::string m_lastName;           // Person's last name
    char m_firstName[nameLenght];     // Person's first name
    
public:
//  Constructors
    Person() { m_lastName = ""; m_firstName[0] = '\0'; }    // #1 Default constructor
    Person(const std::string& lastName,
           const char* firstName = "Heyyou");               // #2
    
//  Methods
    /**
     Display full name in `firstname lastname` format
     */
    void show() const;
    
    /**
     Display full name in `lastname, firstname` format
     */
    void formalShow() const;
};

#endif /* Person1002_hpp */
