//
//  Time1104.hpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 31/01/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef Time1104_hpp
#define Time1104_hpp

#include <iostream>

namespace e1104
{
    class Time
    {
    private:
        int hours;
        int minutes;
        
    public:
//      Constructors
        Time();
        Time(int h, int m = 0);
        
//      Methods
        void addMin(int m);
        void addHr(int h);
        void reset(int h = 0, int m = 0);
        
//      Operator overloads
        friend Time operator+(const Time& t1, const Time& t2);
        friend Time operator-(const Time& t1, const Time& t2);
   
        friend Time operator*(const Time& t, double n);
        friend Time operator*(double n, const Time& t) { return t * n; }
        
        friend std::ostream& operator<<(std::ostream& os, const Time& t);
    };
}   // end namespace e1104

#endif /* Time1104_hpp */
