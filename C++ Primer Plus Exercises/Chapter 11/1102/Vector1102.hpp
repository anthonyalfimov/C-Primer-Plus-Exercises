//
//  Vector1102.hpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 31/01/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef Vector1102_hpp
#define Vector1102_hpp

#include <iostream>

namespace e1102
{
    class Vector
    {
    public:
        // RECT for rectangular, POL for polar modes
        enum Mode {RECT, POL};
        
    private:
        // Rectangular representation
        double m_X;
        double m_Y;
        
        // State member
        Mode m_Mode;    // RECT or POL
        
    public:
        Vector();
        Vector(double p1, double p2, Mode mode = RECT);
        ~Vector();
        
        /**
         Reset vector from 2 parameters that are interpreted as rect (default)
         or polar coordinates depending on the specified mode
         
         @param p1 X or R
         @param p2 Y or Angle
         @param mode RECT or POL
         */
        void reset(double p1 = 0.0, double p2 = 0.0, Mode mode = RECT);
        
        // Getters
        double getX()   const { return m_X; }
        double getY()   const { return m_Y; }
        double getR()   const;
        double getAng() const;
        
        // Mode setters
        void polarMode();   // set polar mode
        void rectMode();    // set rect mode
        
    // Operator overloading
        
        /**
         Add Vector2s
         */
        Vector operator+(const Vector& v) const;
        
        /**
         Subtract Vector2s
         */
        Vector operator-(const Vector& v) const;
        
        /**
         Inverse sign of Vector
         */
        Vector operator-() const;
        
        /**
         Multiply Vector by a scalar
         */
        Vector operator*(double n) const;
        
        // Operator overloading - Friends
        friend Vector operator*(double n, const Vector& v) { return v * n; }  // inline definition
        
        /**
         Display rect coordinates if mode is RECT or polar coordinates if mode is POL
         
         @param os std::ostream output stream
         @param v Vector object to display
         @return reference to std::ostream output stream
         */
        friend std::ostream& operator<<(std::ostream& os, const Vector& v);
    };
}   // end namespace e1102

#endif /* Vector1102_hpp */
