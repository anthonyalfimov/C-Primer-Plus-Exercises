//
//  Vector1102.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 31/01/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <cmath>
#include "Vector1102.hpp"

namespace e1102
{
    //  Calculate degrees in one radian (~57.3)
    const double radToDeg {45.0 / std::atan(1.0)};
    
    //  Private methods
    
    // Calculate and return polar coordinates from rect
    double Vector::getR() const
    {
        return std::sqrt(m_X * m_X + m_Y * m_Y);
    }
    
    double Vector::getAng() const
    {
        if (m_X == 0.0 && m_Y == 0.0)
            return 0.0;
        else
            return std::atan2(m_Y, m_X) * radToDeg;
    }
    
    //  Public methods
    
    // Default constructor
    Vector::Vector()
    {
        m_X = m_Y = 0.0;
        m_Mode = RECT;
    }
    
    // Construct vector from 2 parameters that are interpreted as rect (default)
    //     or polar coordinates depending on the specified mode
    Vector::Vector(double p1, double p2, Mode mode)       // note that enum is accesible here!
    {
        reset(p1, p2, mode);
    }
    
    // Destructor
    Vector::~Vector()
    {
        
    }
    
    void Vector::reset(double p1, double p2, Mode mode)
    {
        m_Mode = mode;
        if (mode == RECT)
        {
            // Set rect coords from parameter values
            m_X = p1;
            m_Y = p2;
        }
        else if (mode == POL)
        {
            // Calculate rect coords
            m_X = p1 * std::cos(p2 / radToDeg);
            m_Y = p1 * std::sin(p2 / radToDeg);
        }
        else
        {
            std::cout << "Incorrect 3rd argument to Vector2() -- "
            "vector set to 0\n";
            
            m_X = m_Y = 0.0;
            m_Mode = RECT;
        }
    }
    
    // Mode setters
    void Vector::polarMode()
    {
        m_Mode = POL;
    }
    
    void Vector::rectMode()
    {
        m_Mode = RECT;
    }
    
    // Operator overloading
    Vector Vector::operator+(const Vector& v) const
    {
        return Vector(m_X + v.m_X, m_Y + v.m_Y);
    }
    
    Vector Vector::operator-(const Vector& v) const
    {
        return Vector(m_X - v.m_X, m_Y - v.m_Y);
    }
    
    Vector Vector::operator-() const
    {
        return Vector(-m_X, -m_Y);
    }
    
    Vector Vector::operator*(double n) const
    {
        return Vector(n * m_X, n * m_Y);
    }
    
    //  Friend functions
    std::ostream& operator<<(std::ostream& os, const Vector& v)
    {
        if (v.m_Mode == Vector::RECT)  // note that enum is not accesible here without specifier!
            os << "(x,y) = (" << v.m_X << ", " << v.m_Y << ")";
        else if (v.m_Mode == Vector::POL)
            os << "(r,a) = (" << v.getR() << ", " << v.getAng() << ")";
        else
            // should never be reached, but better to futureproof
            os << "Vector object mode invalid";
        
        return os;
    }
}   // end namespace e1102
