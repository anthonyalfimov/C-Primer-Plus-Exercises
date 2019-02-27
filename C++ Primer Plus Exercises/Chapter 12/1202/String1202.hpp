//
//  String1202.hpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 27/02/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef String1202_hpp
#define String1202_hpp

#include <iostream>

namespace e1202
{
    class String
    {
    public:
//      Constructors and Destructor
        String();                       // default constructor
        String(const char*);            // constructor
        String(const String&);          // explicit copy constructor
        ~String();                      // destructor
        
//      Methods
        int length() const { return m_length; }
        String& upperCase();
        String& lowerCase();
        unsigned int count(char) const;
        
//      Assignment operator overloads
        String& operator=(const String&);   // has to be a member function
        String& operator=(const char*);     // speed up assigning string by avoiding tmp objects
        
//      Element access overloads
        char& operator[](int);              // has to be a member function
        const char& operator[](int) const;  // read-only version for const objects
        
//      Comparison operator overloads
        friend bool operator<(const String& st1, const String& st2);
        friend bool operator>(const String& st1, const String& st2);
        friend bool operator==(const String& st1, const String& st2);
        
//      Arithmetic operator overloads
        friend String operator+(const String& st1, const String& st2);
        String& operator+=(const String& st) { return *this = *this + st; }
        
//      I/O operator overloads
        friend std::ostream& operator<<(std::ostream& os, const String& st);
        friend std::istream& operator>>(std::istream& is, String& st);      // basic implementation
        
//      Static methods
        static int stringCount();
        
    private:
        char* m_str;                    // pointer to string
        int m_length;                   // length of string
        static int s_strCount;          // number of objects
        static const int CINLIM = 80;   // cin input limit
    };
}   // end namespace e1202

#endif /* String1202_hpp */
