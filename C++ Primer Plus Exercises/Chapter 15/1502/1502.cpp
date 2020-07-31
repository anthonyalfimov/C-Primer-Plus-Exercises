//
//  1502.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 31/07/2020.
//  Copyright © 2020 Anthony. All rights reserved.
//

#include <iostream>
#include <cmath>
#include "MeanExcept1502.hpp"

namespace e1502
{
    double getHarmonicMean (double, double);
    double getGeometricMean (double, double);
}

void show1502()
{
    using namespace e1502;
    
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
        catch (BadHarmonicMean& harmonicMeanException)
        {
            std::cout << harmonicMeanException.what() << "\nTry again <q to quit>: ";
            continue;
        }
        catch (BadGeometricMean& geometricMeanException)
        {
            std::cout << geometricMeanException.what() << "\nSorry, you don't get to play anymore.\n";
            break;
        }
    }
    
    std::cout << "\nDone.\n";
}

namespace e1502
{
    double getHarmonicMean (double a, double b)
    {
        if (a == -b)
            throw BadHarmonicMean ("getHarmonicMean()");
        
        return 2.0 * a * b / (a + b);
    }

    double getGeometricMean (double a, double b)
    {
        if (a < 0 || b < 0)
            throw BadGeometricMean("getGeometricMean()");
        
        return std::sqrt(a * b);
    }
}
