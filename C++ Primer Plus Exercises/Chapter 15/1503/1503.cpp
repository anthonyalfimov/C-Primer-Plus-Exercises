//
//  1503.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 03/08/2020.
//  Copyright © 2020 Anthony. All rights reserved.
//

#include <iostream>
#include <cmath>
#include "MeanExcept1503.hpp"

namespace e1503
{
    double getHarmonicMean (double, double);
    double getGeometricMean (double, double);
}

void show1503()
{
    using namespace e1503;
    
    double x, y;
    double result;
    
    std::cout << "Enter two numbers: ";
    
    while (std::cin >> x >> y)
    {
        while (std::cin.get() != '\n')
            continue;                   // clear excessive input
        
        try
        {
            result = getHarmonicMean(x, y);
            std::cout << "Harmonic mean of " << x << " and " << y << " is " << result << "\n";
            
            result = getGeometricMean(x, y);
            std::cout << "Geometric mean of " << x << " and " << y << " is " << result << "\n";
            
            std::cout << "\nEnter next set of numbers <q to quit>: ";
        }
        catch (BadMean& meanException)
        {
            meanException.report();
            std::cout << "Terminating execution...\n";
            break;
        }
    }
    
    std::cout << "\nDone.\n";
}

namespace e1503
{
    double getHarmonicMean (double a, double b)
    {
        if (a == -b)
            throw BadHarmonicMean (a, b, "getHarmonicMean()");
        
        return 2.0 * a * b / (a + b);
    }

    double getGeometricMean (double a, double b)
    {
        if (a < 0 || b < 0)
            throw BadGeometricMean(a, b, "getGeometricMean()");
        
        return std::sqrt(a * b);
    }
}
