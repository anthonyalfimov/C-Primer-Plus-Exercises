//
//  Complex1107.hpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 01/02/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef Complex1107_hpp
#define Complex1107_hpp

#include <iostream>

namespace e1107
{
    class Complex
    {
    private:
        double m_real;
        double m_img;
        
    public:
        Complex(double r = 0, double i = 0);
        
//      Operator overloads
        Complex operator~() const;
        Complex operator-() const;
        
        friend Complex operator+(const Complex& c1, const Complex& c2);
        friend Complex operator-(const Complex& c1, const Complex& c2);
        friend Complex operator*(const Complex& c1, const Complex& c2);
        
        Complex operator*(double n) const;
        friend Complex operator*(double n, const Complex& c) { return c * n; }
        
        friend std::ostream& operator<<(std::ostream& os, const Complex& c);
        friend std::istream& operator>>(std::istream& is, Complex& c);
    };
}

#endif /* Complex1107_hpp */
