//
//  1106.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 01/02/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "Stonewt1106.hpp"

void show1106()
{
    constexpr int SIZE = 6;
    
    using e1106::Stonewt;
    
    Stonewt weights[SIZE]
    {
        {12, 11.5},
        {124.2},
        {221.0}
    };
    
    double pounds;
    std::cout << "Please, enter " << SIZE - 3 << " weights in pounds:\n";
    for (int i = 3; i < SIZE; i++)
    {
        std::cout << "Weigt #" << i + 1 << ": ";
        while (!(std::cin >> pounds) || pounds < 0)
        {
            std::cout << "Invalid! Try again: ";
            std::cin.clear();
            while (std::cin.get() != '\n') continue;
        }
        weights[i] = pounds;
        
        while (std::cin.get() != '\n') continue;
    }
    
    int indMin = 0;                                     // index of the smallest element
    int indMax = 0;                                     // index of the largest element
    const Stonewt thresh(11, 0);                        // threshold of 11 stones
    int threshCount = weights[0] >= thresh ? 1 : 0;      // count of weights above the threshold
    
    for (int i = 1; i < SIZE; i++)
    {
        if (weights[i] > weights[indMax])
            indMax = i;
        else if (weights[i] < weights[indMin])
            indMin = i;
        
        if (weights[i] >= thresh)
            threshCount++;
    }
    
    std::cout << "\nThe largest weight: ";
    weights[indMax].showStone();
    std::cout << "The smallest weight: ";
    weights[indMin].showStone();
    std::cout << "There are " << threshCount << " weights greater or equal to ";
    thresh.showStone();
}
