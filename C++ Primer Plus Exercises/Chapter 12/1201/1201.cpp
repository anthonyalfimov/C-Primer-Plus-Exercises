//
//  1201.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 27/02/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "Cow1201.hpp"

const int SIZE = 20;
const int COW_COUNT = 4;

void show1201()
{
    using e1201::Cow;
    
    Cow daisy("Daisy", "Chess", 650.0);
    std::cout << "Here's your sample cow!\n";
    daisy.show();
    
    Cow cattle[COW_COUNT] {daisy};                  // initialise first cow to daisy using copy ctor
    char input[2][SIZE];                            // temporary string for user input
    double weight;                                  // temporary variable for weight input
    const char* message[2]                          // input prompts
    {
        "What is the cow's name? ",
        "What is the cow's hobby? "
    };
    
    for (int i = 1; i < COW_COUNT; i++)
    {
        std::cout << "\nCow #" << i + 1 << " out of " << COW_COUNT << "\n";
        
        // Read cow's name and hobby
        for (int j = 0; j < 2; j++)
        {
            std::cout << message[j];
            
            while (! std::cin.get(input[j], SIZE))
            {
                std::cout << "Resistance if futile. You will enter all "
                          << COW_COUNT - 1 << " cows!\n";
                std::cin.clear();
                std::cin.get();
                std::cout << message[j];
            }
            
            while (std::cin.get() != '\n')          // clean up possible overflow
                continue;
        }
        std::cout << "How much does the cow weight? ";
        
        // Read cow's weight
        while (! (std::cin >> weight))
        {
            std::cout << "Resistance if futile. You will enter all "
                      << COW_COUNT - 1 << " cows!\n";
            std::cin.clear();
            while (std::cin.get() != '\n')          // clean up
                continue;
            std::cout << "How much does the cow weight? ";
        }
        
        while (std::cin.get() != '\n')          // clean up
            continue;
        
        // Save cow data:
        cattle[i] = Cow(input[0], input[1], weight);
    }
    
    std::cout << "\nHere are your " << COW_COUNT << " glorious cows:\n";
    for (int i = 0; i < COW_COUNT; i++)
    {
        cattle[i].show();
        std::cout << "\n";
    }
    std::cout << "Done.\n";
}
