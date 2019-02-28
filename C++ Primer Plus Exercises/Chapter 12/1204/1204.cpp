//
//  1204.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 28/02/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "Stack1204.hpp"

const int COUNT = 5;

void show1204()
{
    using namespace e1204;              // for Stack class and Item typedef
    
    std::cout << "Let's reverse a number sequence and multiply it with the original "
                 "sequence using stacks!\n";
    Item tmp;
    Stack input(COUNT);
    std::cout << "Enter a sequence of " << COUNT << " integer numbers:\n";
    
    while (! input.isFull())
    {
        while (! (std::cin >> tmp))     // keep trying until get a number
        {
            std::cin.clear();
            std::cin.get();
        }
        
        input.push(tmp);
    }
    
    while (std::cin.get() != '\n')      // clean up after numbers were read
        continue;
    
    Stack reverse = input;              // copy the input stack into a new one | copy ctor
    Stack direct(COUNT);                // new empty stack for sequence in direct order
    
    while (! input.isEmpty())           // reverse sequence
    {
        input.pop(tmp);
        direct.push(tmp);
    }
    
    input = direct;                     // preserve sequence in direct order | operator=
    std::cout << "\nDirect and inverse order sequences multiplied:\n";
    Item a, b;
    
    while (! direct.isEmpty() && ! reverse.isEmpty())
    {
        reverse.pop(a);
        direct.pop(b);
        std::cout << a * b << ' ';
    }
    
    std::cout << "\n\nYour original sequence:\n";
    while (! input.isEmpty())
    {
        input.pop(tmp);
        std::cout << tmp << ' ';
    }
    std::cout << "\n";
}
