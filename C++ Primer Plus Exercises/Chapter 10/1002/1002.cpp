//
//  1002.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 03/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
#include "Person1002.hpp"

void show1002()
{
    Person people[3]
    {
        {"Peterson", "Jake"},   // use #2
        {"Youhey"}              // use #2 with default argument
    };                          // omitting initialization uses #1
    
    std::cout << "Formal introductions:\n";
    for (int i = 0; i < 3; i++)
    {
        std::cout << "#" << i + 1 << ": ";
        people[i].formalShow();
        std::cout << std::endl;
    }
    std::cout << "Informal introductions:\n";
    for (int i = 0; i < 3; i++)
    {
        std::cout << "#" << i + 1 << ": ";
        people[i].show();
        std::cout << std::endl;
    }
    
    std::cout << "\nDone.\n";
}
