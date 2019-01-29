//
//  Vector1101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 29/01/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <cmath>
#include "Vector1101.hpp"

namespace e1101
{
    //  Calculate degrees in one radian (~57.3)
    const double radToDeg {45.0 / std::atan(1.0)};
    
    //  Private methods
    
    // Calculate polar coordinates from rect
    void Vector::setR()
    {
        m_R = std::sqrt(m_X * m_X + m_Y * m_Y);
    }
    
    void Vector::setAng()
    {
        if (m_X == 0.0 && m_Y == 0.0)
            m_Ang = 0.0;
        else
            m_Ang = std::atan2(m_Y, m_X);
    }
    
    // Calculate rect coordinates from polar
    void Vector::setX()
    {
        m_X = m_R * std::cos(m_Ang);
    }
    
    void Vector::setY()
    {
        m_Y = m_R * std::sin(m_Ang);
    }
    
//  Public methods
    
    // Default constructor
    Vector::Vector()
    {
        m_X = m_Y = m_R = m_Ang = 0.0;
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
            // Calculate polar coords
            setR();
            setAng();
        }
        else if (mode == POL)
        {
            // Set polar coords from parameter values
            m_R = p1;
            m_Ang = p2 / radToDeg;
            // Calculate rect coords
            setX();
            setY();
        }
        else
        {
            std::cout << "Incorrect 3rd argument to Vector2() -- "
            "vector set to 0\n";
            
            m_X = m_Y = m_R = m_Ang = 0.0;
            m_Mode = RECT;
        }
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
            os << "(r,a) = (" << v.m_R << ", " << v.m_Ang * radToDeg << ")";
        else
            // should never be reached, but better to futureproof
            os << "Vector object mode invalid";
        
        return os;
    }
}   // end namespace e1101
