//
//  Stonewt1106.hpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 01/02/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef Stonewt1106_hpp
#define Stonewt1106_hpp

#include <iostream>

namespace e1106
{
    class Stonewt
    {
    private:
        static const int LbsPerStn = 14;        // pounds per stone
        
        int    m_stone;                         // whole stones
        double m_poundsLeft;                    // fractional pounds
        double m_pounds;                        // entire weight in pounds
        
    public:
        Stonewt(double pounds);        // constructor for fractional pounds
        Stonewt(int stone, double pounds);      // constructor for stone and pounds
        Stonewt();                              // default constructor
        ~Stonewt();                             // destructor
        
//      Display functions
        void showPounds() const;                // show weight in pounds format
        void showStone() const;                 // show weight in stone and pounds format
        
//      Relational operator overloads
        friend bool operator==(const Stonewt& s1, const Stonewt& s2) { return s1.m_pounds == s2.m_pounds; }
        friend bool operator!=(const Stonewt& s1, const Stonewt& s2) { return s1.m_pounds != s2.m_pounds; }
        friend bool operator< (const Stonewt& s1, const Stonewt& s2) { return s1.m_pounds <  s2.m_pounds; }
        friend bool operator<=(const Stonewt& s1, const Stonewt& s2) { return s1.m_pounds <= s2.m_pounds; }
        friend bool operator> (const Stonewt& s1, const Stonewt& s2) { return s1.m_pounds >  s2.m_pounds; }
        friend bool operator>=(const Stonewt& s1, const Stonewt& s2) { return s1.m_pounds >= s2.m_pounds; }
    };
}   // end namespace e1106

#endif /* Stonewt1106_hpp */
