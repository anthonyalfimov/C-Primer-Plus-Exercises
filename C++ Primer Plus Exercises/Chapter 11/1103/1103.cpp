//
//  1103.cpp
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
#include "Vector1103.hpp"

namespace
{
    /**
     The function performs a random walk with specified step until it reaches designated distance
     from origin and reports the number of steps it took
     
     @param target Target distance from origin
     @param dstep Random walk step
     @return Number of steps to reach the target
     */
    unsigned long performRandowWalk(double target, double dstep);
}

void show1103()
{
    // Override the default seed value for the pseudorandom number generator
    //     so that each run of the program generates different sequence of random numbers
    std::srand(static_cast<unsigned int>(time(nullptr)));
    
    unsigned long currentSteps;
    
    // Simulation parameters
    double target;
    double dstep;
    int trials;
    
    // Reported results
    unsigned long maxSteps;
    unsigned long minSteps;
    double        averageSteps;
    
    std::cout << "Enter target distance (q to quit): ";
    while (std::cin >> target)
    {
        std::cout << "Enter step length: ";
        if (!(std::cin >> dstep))
            break;
        
        std::cout << "Enter number of trials: ";
        if (!(std::cin >> trials))
            break;
        if (trials < 1)
        {
            std::cout << "Invalid number of trials! Perfroming a single trial instead!\n";
            trials = 1;
        }
        
        // Initialize reported results by running the first trial
        averageSteps = maxSteps = minSteps = performRandowWalk(target, dstep);
        
        for (int i = 1; i < trials; i++)
        {
            currentSteps = performRandowWalk(target, dstep);
            
            if (currentSteps > maxSteps)                // update min and max
                maxSteps = currentSteps;
            else if (currentSteps < minSteps)
                minSteps = currentSteps;
            
            averageSteps += currentSteps;               // accumulate steps for average calculation
        }
        
        // Report the results
        averageSteps /= trials;
        std::cout
            << "\nMinimum number of steps: " << minSteps
            << "\nMaximum number of steps: " << maxSteps
            << "\nAverage number of steps: " << averageSteps << "\n";
        
        std::cout << "\nEnter target distance (q to quit): ";
    }
    std::cout << "\nDone.\n";
    
    std::cin.clear();
    while (std::cin.get() != '\n')
        continue;
}

namespace
{
    unsigned long performRandowWalk(double target, double dstep)
    {
        using e1103::Vector;
        
        double direction;
        Vector step;
        Vector result(0.0, 0.0);
        unsigned long stepCount = 0;
        
        while (result.getR() < target)
        {
            // Get a random angle value in [0, 359]
            direction = std::rand() % 360;
            
            step.reset(dstep, direction, Vector::POL);
            
            result = result + step;
            stepCount++;
        }
        
        return stepCount;
    }
}

