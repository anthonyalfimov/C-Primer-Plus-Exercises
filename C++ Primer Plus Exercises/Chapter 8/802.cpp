//
//  802.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 30/10/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
#include <cstring>

constexpr int stringSize {40};
constexpr int barCount {3};

namespace e802
{
    struct CandyBar
    {
        char brand[stringSize];
        float weight;
        int calories;
    };
    
    void fillInfo(CandyBar& bar,
                  const char * brand = "Millennium Munch",
                  double weight = 28.5f,
                  int calories = 350);
    
    void displayInfo(const CandyBar& bar);
}

using namespace e802;

void show802()
{
//    Create an array of CandyBar structs:
    CandyBar bars[barCount];
//    Use all default values to fill info:
    fillInfo(bars[0]);
//    Supply all values to fill info:
    fillInfo(bars[1],
             "Wonky Delight",
             56.7f,
             440);
//    Use default value for calories to fill info:
    fillInfo(bars[2], "Pirates of the CandyBarrian", 120.0f);
    
//    Display all bars:
    for (int i = 0; i < barCount; i++)
        displayInfo(bars[i]);
}

void e802::fillInfo(CandyBar& bar, const char * brand, double weight, int calories)
{
    std::strncpy(bar.brand, brand, stringSize);
    bar.weight = weight;
    bar.calories = calories;
}

void e802::displayInfo(const CandyBar& bar)
{
    std::cout
        << "Candy bar \"" << bar.brand << "\":\n"
        << "Weight: " << bar.weight << "g,\n"
        << "Calories: " << bar.calories << "\n\n";
}
