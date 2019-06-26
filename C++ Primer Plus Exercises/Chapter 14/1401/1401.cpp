//
//  1401.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 26/06/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "WineType1401.hpp"

constexpr int labelSize = 50;

void show1401()
{
    using e1401::Wine;
    
    std::cout << "Enter name of wine: ";
    char label[labelSize];
    std::cin.getline (label, labelSize);
    
    std::cout << "Enter number of years: ";
    int yearsCount;
    std::cin >> yearsCount;
    std::cout << "\n";
    
    Wine holding (label, yearsCount);       // store label, years, give arrays yearsCount elements
    holding.inputYearsAndBottles();         // solicit input for years and bottles
    std::cout << "\n";
    holding.display();                      // display object contents
    std::cout << "\n";
    
    constexpr int gushingGrapeCount = 3;
    int years[gushingGrapeCount] {1993, 1995, 1998};
    int bottles[gushingGrapeCount] {48, 60, 72};
    
    // Create a new object initialised to data in years[], bottles[]
    Wine gushingGrape ("Gushing Grape Red", gushingGrapeCount, years, bottles);
    gushingGrape.display();
    std::cout << "\nTotal bottles for " << gushingGrape.getLabel()
              << ": " << gushingGrape.getBottlesTotal() << "\n";
    
    std::cout << "\nDone.\n";
}
