//
//  701.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 10/10/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>

namespace e701
{
//  Function prototypes
    double harmonicMean(double x, double y);
}

using namespace e701;

void show701()
{
    double x, y;
    std::cout << "Enter two numbers: ";
    
    while (std::cin >> x >> y)              // while input is good
    {
        if (x == 0.0 || y == 0.0) break;
        
        std::cout << "Harmonic mean: " << harmonicMean(x, y) << "\n";
        std::cout << "Enter next two numbers: ";
    }
    if (std::cin)
        std::cout << "Terminated: 0 encountered\n";
    else
        std::cout << "Terminated: bad input\n";     // boldly assuming that bad input is the
                                                    // only thing that can go wrong with cin here
    std::cout << "Done.\n";
}

double e701::harmonicMean(double x, double y)
{
    return 2.0 * x * y / (x + y);
}
