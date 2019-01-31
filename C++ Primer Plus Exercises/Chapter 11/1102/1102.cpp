//
//  1102.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 31/01/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include <cstdlib>              // Standard ANSI C lib for: rand(), srand()
                                //     rand() returns a pseudorandom integer
                                //     (by applying a deterministic algorithm to a seed value)
                                //     from 0 to some implementation-determined value

#include <ctime>                // time(nullptr) - returns the current calendar time, usually in
                                //     number of seconds since some set date
                                // Generally, time() function takes an address of a type
                                //     `tyme_t` variable, puts the time into this variable
                                //     and also returns it. Using `nullptr` as the address obviates
                                //     the need for the unnecessary in our case variable
#include "Vector1102.hpp"

void show1102()
{
    using e1102::Vector;
    
    // Override the default seed value for the pseudorandom number generator
    //     so that each run of the program generates different sequence of random numbers
    std::srand(static_cast<unsigned int>(time(nullptr)));
    
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long stepCount {0};
    double target;
    double dstep;
    
    std::cout << "Enter target distance (q to quit): ";
    while (std::cin >> target)
    {
        std::cout << "Enter step length: ";
        if (!(std::cin >> dstep))
            break;
        
        result.polarMode();
        std::cout << stepCount << ":\t" << result << "\n";
        
        while (result.getR() < target)
        {
            // Get a random angle value in [0, 359]
            direction = std::rand() % 360;
            
            step.reset(dstep, direction, Vector::POL);
            
            // This sets result to RECT mode as a result of operator+() using the
            //     default constructor
            result = result + step;
            stepCount++;
            
            result.polarMode();
            std::cout << stepCount << ":\t" << result << "\n";
        }
        
        // Report the results
        result.rectMode();
        std::cout
            << "\nAfter " << stepCount << " steps, the subject "
            << "has the following location:\n"
            << result << "\n";
        result.polarMode();
        std::cout
            << "or\n" << result << "\n"
            << "Average outward displacement per step is "
            << result.getR() / stepCount << "\n";
        
        // Reset the values for another calculation
        stepCount = 0;
        result.reset();
        
        std::cout << "\nEnter target distance (q to quit): ";
    }
    std::cout << "\nDone.\n";
    
    std::cin.clear();
    while (std::cin.get() != '\n')
        continue;
}
