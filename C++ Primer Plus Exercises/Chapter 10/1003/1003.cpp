//
//  1003.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 04/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
#include "golf1003.hpp"

constexpr int clubSize {5};

void show1003()
{
    Golf bob("Bob Builder");
    bob.show();
    bob.handicap(12, true).show();
    
    std::cout << "\n";
    
    Golf club[clubSize];        // Use default constructor
    
    std::cout << "Fill in up to " << clubSize << " entries for the golf club\n"
                 "(leave name empty to finish)\n";
    int count {0};            // Actual number of club entries
    while (count < clubSize && club[count].set())
        count++;
    
    
    if (count == 0)
        std::cout << "\nNo entries!\n";
    else
    {
        std::cout << "\nRead " << count << " entries:\n";
        for (int i = 0; i < count; i++)
            club[i].show();
    }
}
