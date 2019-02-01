//
//  1105.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 01/02/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "Stonewt1105.hpp"

namespace
{
    void printAllModes(e1105::Stonewt&);
}

void show1105()
{
    using e1105::Stonewt;
    
    Stonewt alpha(124.7);           // use float pounds constructor
    Stonewt beta(50);               // use int pounds constructor
    Stonewt gamma(5, 12.5);         // use stone, pounds constructor
    
    // Display modes
    
    std::cout << "> Default display modes\n"
              << "Alpha:\t" << alpha << "\nBeta:\t" << beta
              << "\nGamma:\t" << gamma << "\n";
    
    std::cout << "\n> All modes\n";
    std::cout << "Alpha:\t";
    printAllModes(alpha);
    
    std::cout << "Beta:\t";
    printAllModes(beta);
    
    std::cout << "Gamma:\t";
    printAllModes(gamma);
    
    // Operators
    std::cout << "\n> Operators\n";
    Stonewt delta = alpha - beta;
    std::cout << "Alpha - Beta = " << delta << " or " << delta.stoneMode() << "\n";
    std::cout << "2 * Gamma - (Alpha - Beta) * 1.5 = " << (2 * gamma - delta * 1.5) << "\n";
    std::cout << "Alpha + Beta + Gamma = " << (alpha + beta + gamma).intPoundMode() << "\n";
}

namespace
{
    void printAllModes(e1105::Stonewt& s)
    {
        std::cout << s.stoneMode() << "   \t" << s.floatPoundMode() << "   \t"
                  << s.intPoundMode() << "\n";
    }
}
