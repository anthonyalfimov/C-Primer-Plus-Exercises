//
//  Time1104.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 31/01/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include "Time1104.hpp"

namespace e1104
{
    Time::Time()
    {
        hours = minutes = 0;
    }
    
    Time::Time(int h, int m)
    {
        hours = h;
        minutes = m;
    }
    
    void Time::addMin(int m)
    {
        minutes += m;
        hours += minutes / 60;
        minutes %= 60;
    }
    
    void Time::addHr(int h)
    {
        hours += h;
    }
    
    void Time::reset(int h, int m)
    {
        hours = h;
        minutes = m;
    }
    
    Time operator+(const Time& t1, const Time& t2)
    {
        Time sum;
        sum.minutes = t1.minutes + t2.minutes;
        sum.hours = t1.hours + t2.hours + sum.minutes / 60;
        sum.minutes %= 60;
        return sum;
    }
    
    Time operator-(const Time& t1, const Time& t2)
    {
        Time diff;
        int t1_total = t1.minutes + 60 * t1.hours;
        int t2_total = t2.minutes + 60 * t2.hours;
        
        diff.minutes = (t1_total - t2_total) % 60;
        diff.hours   = (t1_total - t2_total) / 60;
        
        return diff;
    }
    
    Time operator*(const Time& t, double n)
    {
        Time result;
        long total = n * (t.minutes + 60 * t.hours);
        result.minutes = total % 60;        // implicit conversion can't lead to loss of precision
        result.hours   = static_cast<int>(total / 60);
        
        return result;
    }
    
    std::ostream& operator<<(std::ostream& os, const Time& t)
    {
        int sgn = 1;
        if (t.hours < 0 || t.minutes < 0)
        {
            os << "- ";
            sgn = -1;
        }
        
        if (t.hours != 0)
        {
            os << sgn * t.hours << " hours";
            if (t.minutes != 0)
                os << ", " << sgn * t.minutes << " minutes";
        }
        else
            os << sgn * t.minutes << " minutes";
        return os;
    }
}

