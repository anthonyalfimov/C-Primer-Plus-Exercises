//
//  Port1304.hpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 15/04/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef Port1304_hpp
#define Port1304_hpp

#include <iostream>

namespace e1304
{
    class Port
    {
    public:
        Port(const char* brand = "none", const char* style = "none", int bottles = 0);
        Port(const Port&);                              // copy constructor
        
        virtual ~Port() { delete [] m_brand; }
        
        Port& operator=(const Port&);
            // should be defined for each class with corresponding argument type => not virtual
        Port& operator+=(int bottles);                  // adds to m_bottles
        Port& operator-=(int bottles);                  // subtracts from m_bottles if possible
        
        int bottleCount() const { return m_bottles; }
        virtual void show() const;
        
        friend std::ostream& operator<<(std::ostream& os, const Port& p);
                                                        // not a member => not virtual
        
    private:
        static const int c_styleLength = 20;
        
        char* m_brand;
        char  m_style[c_styleLength];
        int   m_bottles;
    };
}

#endif /* Port1304_hpp */
