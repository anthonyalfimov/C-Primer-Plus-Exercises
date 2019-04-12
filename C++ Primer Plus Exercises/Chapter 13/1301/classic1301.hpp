//
//  classic1301.hpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 12/04/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef classic1301_hpp
#define classic1301_hpp

#include "cd1301.hpp"

namespace e1301
{
    class Classic : public CD                   // represents a classical music CD disk
    {
    public:
        Classic(const char* primary, const char* performers,
                const char* label, int selections, double playtime);
        Classic(const char* primary, const CD& disk);
        Classic();
        
        virtual void report() const override;
        
    private:
        static const int c_primaryLength = 50;
        
        char m_primary[c_primaryLength];        // primary work on the disk
    };
}   // end namespace e1301

#endif /* classic1301_hpp */
