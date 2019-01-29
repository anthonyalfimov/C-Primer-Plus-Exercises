//
//  1101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 29/01/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>              // Standard ANSI C lib for: rand(), srand(), exit()
                                //     rand() returns a pseudorandom integer
                                //     (by applying a deterministic algorithm to a seed value)
                                //     from 0 to some implementation-determined value

#include <ctime>                // time(nullptr) - returns the current calendar time, usually in
                                //     number of seconds since some set date
                                // Generally, time() function takes an address of a type
                                //     `tyme_t` variable, puts the time into this variable
                                //     and also returns it. Using `nullptr` as the address obviates
                                //     the need for the unnecessary in our case variable
#include "Vector1101.hpp"

namespace
{
    const std::string filePrefix {"RandomWalk_"};
    const std::string fileExtension {".txt"};
    
    std::string fileName(int);
}

void show1101()
{
    using e1101::Vector;
    
    // Override the default seed value for the pseudorandom number generator
    //     so that each run of the program generates different sequence of random numbers
    std::srand(static_cast<unsigned int>(time(nullptr)));
    
    // Output file
    std::ofstream outFile;
    
    int runCount = 0;                   // number of times the random walk was performed
    
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
        
        runCount++;
        outFile.open(fileName(runCount));
        if (!outFile.is_open())         // failed to create the file
        {
            std::cout << "Could not create the file " << fileName(runCount) << "\n"
                      << "Program terminating.\n";
            std::exit(EXIT_FAILURE);    // <cstdlib> function that communicated failure to the OS
        }
        
        outFile << "Target distance: " << target            // Report initial conditions
                << ", Step size: " << dstep << "\n";
        outFile << stepCount << ":\t" << result << "\n";    // Report initial position
        
        while (result.getR() < target)
        {
            // Get a random angle value in [0, 359]
            direction = std::rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            
            // This operation resets the mode to RECT due to the use of the constructor for the
            //     addition operator overload
            result = result + step;
            
            stepCount++;
            
            result.rectMode();              // ensure output in RECT mode
            // Start counting steps from 1:
            outFile << stepCount << ":\t" << result << "\n";
        }
        
        // Report the results
        result.rectMode();
        outFile
            << "After " << stepCount << " steps, the subject "
            << "has the following location:\n"
            << result << "\n";
        result.polarMode();
        outFile
            << "or\n" << result << "\n"
            << "Average outward displacement per step is "
            << result.getR() / stepCount << "\n";
        
        std::cout << "Results saved to \"" << fileName(runCount) << "\"\n";
        
        // Reset the values for another calculation
        stepCount = 0;
        result.reset();
        outFile.close();
        
        std::cout << "\nEnter target distance (q to quit): ";
    }
    std::cout << "\nDone.\n";
    
    std::cin.clear();
    while (std::cin.get() != '\n')
        continue;
}

namespace
{
    std::string fileName(int n)
    {
        return filePrefix + std::to_string(n) + fileExtension;
    }
}
