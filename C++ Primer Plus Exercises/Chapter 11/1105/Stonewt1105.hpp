//
//  Stonewt1105.hpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 01/02/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef Stonewt1105_hpp
#define Stonewt1105_hpp

#include <iostream>

namespace e1105
{
    class Stonewt
    {
    public:
        enum Mode {INT_POUND, FLOAT_POUND, STONE};
        
    private:
        static const int LbsPerStn = 14;        // pounds per stone
        
        Mode   m_mode;                          // state member
        
        int    m_stone;                         // whole stones
        double m_poundsLeft;                    // fractional pounds
        double m_pounds;                        // entire weight in pounds
        
    public:
        explicit Stonewt(double pounds);        // constructor for fractional pounds
        explicit Stonewt(int    pounds);        // constructor for integer pounds
        Stonewt(int stone, double pounds);      // constructor for stone and pounds
        Stonewt();                              // default constructor
        ~Stonewt();                             // destructor
        
//      Mode setters
        const Stonewt& intPoundMode()   { m_mode = INT_POUND;   return *this; }
        const Stonewt& floatPoundMode() { m_mode = FLOAT_POUND; return *this; }
        const Stonewt& stoneMode()      { m_mode = STONE;       return *this; }
        
//      Operator overloads
        Stonewt operator+(const Stonewt&) const;
        Stonewt operator-(const Stonewt&) const;
        Stonewt operator*(double) const;
        
        friend Stonewt operator*(double n, const Stonewt& s) { return s * n; }
        
        friend std::ostream& operator<<(std::ostream&, const Stonewt&);

    };
}   // end namespace e1105

#endif /* Stonewt1105_hpp */
