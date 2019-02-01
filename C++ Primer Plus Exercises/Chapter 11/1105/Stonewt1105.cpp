//
//  Stonewt1105.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 01/02/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "Stonewt1105.hpp"

namespace e1105
{
    // Construct Stonewt object from double value
    Stonewt::Stonewt(double pounds)
    {
        m_stone = int(pounds) / LbsPerStn;      // integer division
        m_poundsLeft = pounds - m_stone * LbsPerStn;
        m_pounds = pounds;
        m_mode = FLOAT_POUND;
    }
    
    // Construct Stonewt object from int value
    Stonewt::Stonewt(int pounds)
    {
        m_stone = pounds / LbsPerStn;           // integer division
        m_poundsLeft = pounds % LbsPerStn;
        m_pounds = pounds;
        m_mode = INT_POUND;
    }
    
    // Construct Stonewt object from stone and pounds values
    Stonewt::Stonewt(int stone, double pounds)
    {
        m_stone = stone;
        m_poundsLeft = pounds;
        m_pounds = stone * LbsPerStn + pounds;
        m_mode = STONE;
    }
    
    // Default constructor with 0 weight
    Stonewt::Stonewt()
    {
        m_stone = m_pounds = m_poundsLeft = 0;
        m_mode = FLOAT_POUND;
    }
    
    // Empty destructor
    Stonewt::~Stonewt()
    {

    }
    
//  Operator overloads
    Stonewt Stonewt::operator+(const Stonewt& s) const
    {
        return Stonewt(m_pounds + s.m_pounds);
    }

    Stonewt Stonewt::operator-(const Stonewt& s) const
    {
        return Stonewt(m_pounds - s.m_pounds);
    }
    
    Stonewt Stonewt::operator*(double n) const
    {
        return Stonewt(n * m_pounds);
    }
    
    std::ostream& operator<<(std::ostream& os, const Stonewt& s)
    {
        switch (s.m_mode)
        {
            case Stonewt::INT_POUND:
                // return the rounded int value instead of truncated
                os << int(s.m_pounds + 0.5) << " pounds";
                break;
            
            case Stonewt::FLOAT_POUND:
                os << s.m_pounds << " pounds";
                break;
                
            case Stonewt::STONE:
                os << s.m_stone << " stone, " << s.m_poundsLeft << " pounds";
                break;
                
            default:
                os << "Ivalid weigth object mode";      // should never be reached
        }
        
        return os;
    }
}
