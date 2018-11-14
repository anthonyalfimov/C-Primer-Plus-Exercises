//
//  705.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 10/10/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>

namespace
{
    unsigned long long factorial(unsigned);
}

//   =============================
//   |       Main function       |
//   =============================
void show705()
{
    std::cout << "Enter a number to calculate factorial <q to quit>:\n";
    int number;
    while ((std::cin >> number) && number >= 0)
        std::cout
            << number << "! = " << factorial(number) << "\n"
            << "Next number <q to quit>:\n";
    
    std::cout << "\nDone.\n";
}

namespace
{
    unsigned long long factorial(unsigned x)
    {
        if (x == 0)
            return 1;
        else
            return x * factorial(x - 1);
    }
}
