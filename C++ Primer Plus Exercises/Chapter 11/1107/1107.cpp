//
//  1107.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 01/02/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "Complex1107.hpp"

void show1107()
{
    using e1107::Complex;
    
    Complex a(3.0, 4.0);            // initialise to (3, 4i)
    Complex c;
    std::cout << "Enter a complex number (q to quit):\n";
    while (std::cin >> c)
    {
        std::cout
            << "c is " << c << "\n"
            << "complex conjugate is " << ~c << "\n"
            << "a is " << a << "\n"
            << "a + c is " << a + c << "\n"
            << "a - c is " << a - c << "\n"
            << "a * c is " << a * c << "\n"
            << "2 * c is " << 2 * c << "\n";
        std::cout << "Enter a complex number (q to quit):\n";
    }
    std::cout << "\nDone.\n";
}
