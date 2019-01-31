//
//  Vector1103.hpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 31/01/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef Vector1103_hpp
#define Vector1103_hpp

#include <iostream>

namespace e1103
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
        
        // Polar representation
        double m_R;     // radial coordinate
        double m_Ang;   // angular coordinate
        
        // State member
        Mode m_Mode;    // RECT or POL
        
        // Private methods to set the values
        void setX();
        void setY();
        void setR();
        void setAng();
        
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
        double getR()   const { return m_R; }
        double getAng() const { return m_Ang; }
        
        // Mode setters
        void polarMode() { m_Mode = POL; }   // set polar mode
        void rectMode()  { m_Mode = RECT; }  // set rect mode
        
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
         Inverse sign of Vector2
         */
        Vector operator-() const;
        
        /**
         Multiply Vector2 by a scalar
         */
        Vector operator*(double n) const;
        
        // Operator overloading - Friends
        friend Vector operator*(double n, const Vector& v) { return v * n; }  // inline definition
        
        /**
         Display rect coordinates if mode is RECT or polar coordinates if mode is POL
         
         @param os std::ostream output stream
         @param v Vector2 object to display
         @return reference to std::ostream output stream
         */
        friend std::ostream& operator<<(std::ostream& os, const Vector& v);
    };
}   // end namespace e1103

#endif /* Vector1103_hpp */
