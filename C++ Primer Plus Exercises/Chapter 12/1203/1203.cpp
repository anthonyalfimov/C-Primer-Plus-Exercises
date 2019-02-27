//
//  1203.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 27/02/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "Stock1203.hpp"

const int size = 4;

void show1203()
{
    using e1203::Stock;
    
    //  Create an array of initialized objects (use list initialization)
    Stock stocks[size]
    {
        {"NanoSmart", 12, 20.0},
        {"Boffo Objects", 200, 2.0},
        {"Monolithic Obelisks", 130, 3.25},
        {"Fleep Enterprises", 60, 6.5}
    };
    
    std::cout << "\nStock holdings:\n";
    for (int i = 0; i < size; i++)
        std::cout << stocks[i] << "\n";
    
    //  Set a pointer to the first element
    const Stock* top = &stocks[0];
    
    for (int i = 1; i < size; i++)
        top = &top->topValue(stocks[i]);    // `->` is higher precedense than `&-address`
    
    //  Display the most valuable holding
    std::cout << "\nMost valuable holding:\n" << *top << "\n\n";
}
