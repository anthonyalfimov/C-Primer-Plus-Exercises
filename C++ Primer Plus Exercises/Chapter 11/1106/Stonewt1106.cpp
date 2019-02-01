//
//  Stonewt1106.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 01/02/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "Stonewt1106.hpp"

namespace e1106
{
    // Construct Stonewt object from double value
    Stonewt::Stonewt(double pounds)
    {
        m_stone = int(pounds) / LbsPerStn;      // integer division
        m_poundsLeft = int(pounds) % LbsPerStn + pounds - int(pounds);  // why not use m_stone?
        m_pounds = pounds;
    }
    
    // Construct Stonewt object from stone and pounds values
    Stonewt::Stonewt(int stone, double pounds)
    {
        m_stone = stone;
        m_poundsLeft = pounds;
        m_pounds = stone * LbsPerStn + pounds;
    }
    
    // Default constructor with 0 weight
    Stonewt::Stonewt()
    {
        m_stone = m_pounds = m_poundsLeft = 0;
    }
    
    // Empty destructor
    Stonewt::~Stonewt()
    {
    }
    
    /**
     Show weight in stone and pounds
     */
    void Stonewt::showStone() const
    {
        if (m_poundsLeft == 0 && m_stone != 0)
            std::cout << m_stone << " stone\n";
        else if (m_stone == 0)
            std::cout << m_poundsLeft << " pounds\n";
        else
            std::cout << m_stone << " stone, " << m_poundsLeft << " pounds\n";
    }
    
    /**
     Show weight in pounds
     */
    void Stonewt::showPounds() const
    {
        std::cout << m_pounds << " pounds\n";
    }
}   // end namespace e1106
