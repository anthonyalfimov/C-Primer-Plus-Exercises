//
//  901.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 16/11/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
#include "golf901.hpp"

const int maxClubSize {5};

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
    
    Golf club[maxClubSize];
    int count;                      // actual number of entires
    for (count = 0; count < maxClubSize; count++)
    {
        std::cout
            << "Enter data for golfer #" << count + 1
            << " of " << maxClubSize << " (empty line to stop):\n";
        if (!setGolf(club[count]))
            break;
    }
    if (count == 0)
        std::cout << "\n> No entries.\n";
    else
    {
        std::cout << "\n> Read " << count << " entries.\n";
        for (int i = 0; i < count; i++)
            showGolf(club[i]);
    }
    
    std::cout << "\nDone.\n";
}
