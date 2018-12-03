//
//  704.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 10/10/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>

namespace
{
    /**
     @param numbers total number of available choices
     @param picks number of picks
     @return probability of picking `picks` numbers correctly
     from `numbers` choices
     */
    long double probability(unsigned numbers, unsigned picks);
    void badInputCleanup();
}

//   =============================
//   |       Main function       |
//   =============================
void show704()
{
    int fieldNumbers, fieldPicks;    // stats for field numbers
    int powerNumbers, powerPicks;    // stats for the power ball
    powerPicks = 1;                  // single power ball
    
    std::cout << "Enter the total number of choices on the game field\n"
                 "and the number of picks allowed:\n";
    while (                          // while bad input
           !(std::cin >> fieldNumbers >> fieldPicks) ||
           fieldNumbers < 0 ||
           fieldPicks   < 0 ||
           fieldPicks > fieldNumbers
          )
        badInputCleanup();           // request new input
    
    std::cout << "Enter the total number of choices for the power ball:\n";
    while (!(std::cin >> powerNumbers) || powerNumbers < powerPicks)
        badInputCleanup();
    
    std::cout
    << "You have one chance in "
    << probability(fieldNumbers, fieldPicks) * probability(powerNumbers, powerPicks)
    << " of winning.\n";
    
    std::cout << "\nDone.\n";
}

namespace
{
    // Calculates probability of picking `picks` numbers correctly
    // from `numbers` choices
    long double probability(unsigned numbers, unsigned picks)
    {
        long double result {1.0};
        long double n;
        unsigned p;
        
        for (n = numbers, p = picks; p > 0; n--, p--)
            result *= n / p;
        
        return result;
    }

    void badInputCleanup()
    {
        std::cout << "Bad input. Try again:\n";
        if (!std::cin)
        {
            std::cin.clear();
            while (std::cin.get() != '\n')
                continue;
        }
    }
}
