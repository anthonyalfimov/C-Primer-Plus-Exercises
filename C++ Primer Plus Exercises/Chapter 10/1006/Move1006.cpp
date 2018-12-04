//
//  Move1006.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 04/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
#include "Move1006.hpp"

void Move::show() const
{
    std::cout
        << "x = " << m_X << "\n"
        << "y = " << m_Y << "\n";
}

Move Move::add(const Move &m) const
{
    Move result(m.m_X + this->m_X, m.m_Y + this->m_Y);
    return result;
}


const Move &Move::reset(double x, double y)
{
    m_X = x;
    m_Y = y;
    return *this;
}
