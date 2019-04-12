//
//  classic1302.hpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 12/04/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef classic1302_hpp
#define classic1302_hpp

#include "cd1302.hpp"

namespace e1302
{
    class Classic : public CD                   // represents a classical music CD disk
    {
    public:
        Classic(const char* primary, const char* performers,
                const char* label, int selections, double playtime);
        Classic(const char* primary, const CD& disk);
        Classic();
        Classic(const Classic&);
        virtual ~Classic() override;
        
        Classic& operator=(const Classic&);
        virtual void report() const override;
        
    private:
        char* m_primary;        // primary work on the disk
    };
}   // end namespace e1301

#endif /* classic1302_hpp */
