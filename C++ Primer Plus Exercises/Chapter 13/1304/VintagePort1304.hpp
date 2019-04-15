//
//  VintagePort1304.hpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 15/04/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef VintagePort1304_hpp
#define VintagePort1304_hpp

#include "Port1304.hpp"

namespace e1304
{
    class VintagePort : public Port
    {
    public:
        VintagePort(const char* brand, int bottles, const char* nickname, int year);
        VintagePort();
        VintagePort(const VintagePort&);                    // explicit copy ctor due to usage of new in ctor
        
        virtual ~VintagePort() { delete [] m_nickname; }    // explicit dtor due to usage of new in ctor
        
        VintagePort& operator=(const VintagePort&);         // explicit assignment op due to usage of new in ctor
        
        // not redefining operator+=(), operator-=() and bottleCount() since
        //     they only deal with the private member of base class - m_bottles;
        
        virtual void show() const override;                 // overriden to display added data members
        
        friend std::ostream& operator<<(std::ostream& os, const VintagePort& vp);
                                                            // defined to display added data members
    private:
        char* m_nickname;
        int   m_year;
    };
}

#endif /* VintagePort1304_hpp */
