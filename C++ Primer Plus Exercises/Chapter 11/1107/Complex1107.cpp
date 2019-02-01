//
//  Complex1107.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 01/02/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include "Complex1107.hpp"

namespace e1107
{
    Complex::Complex(double r, double i)
    {
        m_real = r;
        m_img = i;
    }
    
//  Operator overloads
    Complex Complex::operator~() const
    {
        return Complex(m_real, -m_img);
    }
    
    Complex Complex::operator-() const
    {
        return Complex(-m_real, -m_img);
    }
    
    Complex operator+(const Complex& c1, const Complex& c2)
    {
        return Complex(c1.m_real + c2.m_real, c1.m_img + c2.m_img);
    }
    
    Complex operator-(const Complex& c1, const Complex& c2)
    {
        return Complex(c1.m_real - c2.m_real, c1.m_img - c2.m_img);
    }
    
    Complex operator*(const Complex& c1, const Complex& c2)
    {
        return Complex(c1.m_real * c2.m_real - c1.m_img * c2.m_img,
                       c1.m_real * c2.m_img + c2.m_real * c1.m_img);
    }
    
    Complex Complex::operator*(double n) const
    {
        return Complex(n * m_real, n * m_img);
    }
    
    std::ostream& operator<<(std::ostream& os, const Complex& c)
    {
        os << "(" << c.m_real << ", " << c.m_img << "i)";
        return os;
    }
    
    std::istream& operator>>(std::istream& is, Complex& c)
    {
        std::cout << "real: ";
        if (!(std::cin >> c.m_real))
            return is;
        
        std::cout << "imaginary: ";
        std::cin >> c.m_img;

        return is;
    }
}
