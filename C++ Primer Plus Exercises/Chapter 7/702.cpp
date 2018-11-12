//
//  702.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 10/10/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>

constexpr int maxScores {10};

namespace e702
{
//  Function prototypes
    /**
     Fills the array with user-input scores; returns the number of scores filled.
     
     @param scores pointer to array
     @param limit array size
     @return number of scores filled
     */
    int fillScores(int scores[], int limit);
    void displayScores(const int scores[], int size);
    double averageScore(const int scores[], int size);
}

using namespace e702;

void show702()
{
    int golfScores[maxScores];
    int entires {fillScores(golfScores, maxScores)};    // fill array and retrieve number of
                                                        // entries
    displayScores(golfScores, entires);
    if (entires != 0)
        std::cout << "Average score: " << averageScore(golfScores, entires) << "\n";
    std::cout << "Done.\n";
}

int e702::fillScores(int scores[], int limit)
{
    std::cout << "Enter your golf scores <q to terminate>:\n";
    int i {};
    
    std::cout << "Score #1: ";
    // use a buffer value to test for negative input
    while (i < limit && (std::cin >> scores[i]))
    {
        ++i;
        if (i < limit)
            std::cout << "Score #" << i + 1 << ": ";
    }
    return i;
}

void e702::displayScores(const int scores[], int size)
{
    if (size == 0)
        std::cout << "No data!\n";
    else
    {
        std::cout << scores[0];
        for (int i = 1; i < size; i++)
            std::cout << "\t" << scores[i];
        std::cout << "\n";
    }
}

double e702::averageScore(const int scores[], int size)
{
    if (size == 0)
        return 0;
    else
    {
        double total {};
        for (int i = 0; i < size; i++)
            total += scores[i];
        
        return total / size;
    }
}
