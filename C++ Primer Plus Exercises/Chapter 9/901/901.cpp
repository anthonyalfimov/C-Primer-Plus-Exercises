//
//  901.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 16/11/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
#include "golf.hpp"

const int clubMaxSize {5};

//   =============================
//   |       Main function       |
//   =============================
void show901()
{
    using namespace e901;
    
    Golf loneGolfer;
    setGolf (loneGolfer, "Panther Forests", 4);
    showGolf(loneGolfer);
    handicap(loneGolfer, 8);
    showGolf(loneGolfer);
    
    std::cout << "\n";
    
    Golf club[clubMaxSize];
    int clubSize {0};                   // actual number of entires
    for (int i = 0; i < clubMaxSize; i++)
    {
        std::cout
            << "Enter data for golfer #" << i + 1
            << " of " << clubMaxSize << " (empty line to stop):\n";
        if (!setGolf(club[i]))
            break;
        clubSize = i + 1;               // on succesful input, update actual number of entries
    }
    if (clubSize == 0)
        std::cout << "\n> No entries.\n";
    else
    {
        std::cout << "\n> Read " << clubSize << " entries.\n";
        for (int i = 0; i < clubSize; i++)
            showGolf(club[i]);
    }
    
    std::cout << "\nDone.\n";
}
