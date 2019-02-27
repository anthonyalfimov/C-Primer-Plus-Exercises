//
//  String1202.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 27/02/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <cstring>
#include <cctype>
#include "String1202.hpp"

namespace e1202
{
    // Initialise static class member
    int String::s_strCount = 0;
    
    //  Static methods
    int String::stringCount()
    {
        return s_strCount;
    }
    
    //  Cosntructors and destructor
    String::String()                                    // Default constructor
    {
        m_length = 0;
        m_str = new char[1];
        m_str[0] = '\0';                                // create empty string
        s_strCount++;
        
    #ifdef VERBOSE_STRING_
        std::cout << s_strCount << ": Empty object created\n";
    #endif
    }
    
    String::String(const char* s)                       // Construct from a C-string
    {
        m_length = static_cast<int>(std::strlen(s));    // set string size
        m_str = new char[m_length + 1];                 // allot storage
        std::strcpy(m_str, s);                          // initialise allocated storage
        s_strCount++;                                   // update object count
        
    #ifdef VERBOSE_STRING_
        std::cout << s_strCount << ": \"" << m_str << "\" object created\n";
    #endif
    }
    
    String::String(const String& s)                     // Explicit copy constructor
    {
        m_length = s.m_length;                          // same length
        m_str = new char[m_length + 1];                 // allot space
        std::strcpy(m_str, s.m_str);                    // copy string to new location
        s_strCount++;                                   // update object count
        
    #ifdef VERBOSE_STRING_
        std::cout << s_strCount << ": \"" << m_str << "\" object copied\n";
    #endif
    }
    
    String::~String()
    {
    #ifdef VERBOSE_STRING_
        std::cout << "\"" << m_str << "\" object being deleted, "
        << s_strCount - 1 << " strings left... ";
    #endif
        
        s_strCount--;
        delete [] m_str;
        
    #ifdef VERBOSE_STRING_
        std::cout << "Done.\n";
    #endif
    }
    
    //  Assignment operators
    String& String::operator=(const String& s)
    {
        if (this == &s)                                 // prevent self-copying
            return *this;
        
        delete [] m_str;                                // release memory of old string
        m_length = s.m_length;                          // same length
        m_str = new char[m_length + 1];                 // allocate memory for new string
        std::strcpy(m_str, s.m_str);                    // copy the string contents
        
        // NB! No new objects created, so don't increment strCount!
        
    #ifdef VERBOSE_STRING_
        std::cout << "Assigned \"" << m_str << "\" String object\n";
    #endif
        
        return *this;                                   // return reference to envoking object
    }
    
    String& String::operator=(const char* s)
    {
        delete [] m_str;
        m_length = static_cast<int>(std::strlen(s));
        m_str = new char[m_length + 1];
        std::strcpy(m_str, s);
        
    #ifdef VERBOSE_STRING_
        std::cout << "Assigned \"" << m_str << "\" C-string\n";
    #endif
        
        return *this;
    }
    
    //  Methods
    String& String::upperCase()
    {
        for (int i = 0; i < m_length; i++)
            m_str[i] = std::toupper(m_str[i]);
        
        return *this;
    }
    
    String& String::lowerCase()
    {
        for (int i = 0; i < m_length; i++)
            m_str[i] = std::tolower(m_str[i]);
        
        return *this;
    }
    
    unsigned int String::count(char ch) const
    {
        int result = 0;
        
        for (int i = 0; i < m_length; i++)
            if (m_str[i] == ch)
                result++;
        
        return result;
    }
    
    //  Element access operators
    char& String::operator[](int i)                     // read/write version, no bounds checking
    {
        return m_str[i];
    }
    
    const char& String::operator[](int i) const         // read-only version, no bounds checking
    {
        return m_str[i];
    }
    
    //  Comparison operators
    bool operator<(const String& st1, const String& st2)
    {
        return (std::strcmp(st1.m_str, st2.m_str) < 0);
    }
    
    bool operator>(const String& st1, const String& st2)
    {
        return (std::strcmp(st1.m_str, st2.m_str) > 0);
    }
    
    bool operator==(const String& st1, const String& st2)
    {
        return (std::strcmp(st1.m_str, st2.m_str) == 0);
    }
    
    //  Arithmetic operator overloads
    String operator+(const String& st1, const String& st2)
    {
        String result;                                          // create empty object for output
        delete [] result.m_str;                                 // deallocate empty string
        result.m_length = st1.m_length + st2.m_length;          // calculate output string length
        result.m_str = new char[result.m_length + 1];
        std::strcpy(result.m_str, st1.m_str);                   // copy 1st string (incl. '\0')
        std::strcpy(result.m_str + st1.m_length, st2.m_str);    // copy 2nd string (first character
                                                                //     writes over the '\0' from
                                                                //     the 1st string)
        return result;
    }
    
    //  I/O operators
    std::ostream& operator<<(std::ostream& os, const String& s)     // Simple string output
    {
        os << s.m_str;
        return os;
    }
    
    std::istream& operator>>(std::istream& is, String& s)           // Quick and dirty String input
    {
        char temp[String::CINLIM];      // temporary buffer
        is.get(temp, String::CINLIM);
        
        if(is)                          // if not failstate
        {
            s = temp;                   // place result into string
            while(is.get() != '\n')     // clear trailing characters
                continue;
        }
        
        return is;
    }
}   // end namespace e1202
