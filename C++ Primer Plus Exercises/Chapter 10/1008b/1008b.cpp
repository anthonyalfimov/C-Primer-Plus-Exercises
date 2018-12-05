//
//  1008b.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 05/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//
//  Text of this program is identical to version A with the exception of
//      the namespace used to demonstrate that List class interface remained
//      unchanged
//

#include <iostream>
#include "SimpleListB.hpp"

namespace e1008b
{
//  Functions to apply to list elements
    
    /**
     Print elements
     */
    void print(Item& item) { std::cout << item << " "; }
    
    /**
     Increment elements
     */
    void inc(Item& item) { item++; }
    
    /**
     Decrement elements
     */
    void dec(Item& item) { item--; }
    
    /**
     Square elements
     */
    void square(Item& item) { item *= item; }
    
}

void show1008b()
{
    using namespace e1008b;
    
    // Create an empty list
    List seq;
    
    // Confirm that list is empty
    if (seq.isEmpty())
        std::cout << "List: empty\n";
    
    // Fill the list with up to 10 consequent integers
    std::cout << "\nFilling the list...\n";
    for (int i = 0; !seq.isFull() && i < 10; i++)
        seq.add(i + 1);             // non-lvalue, temporary object is created
    
    // Print list contents
    std::cout << "List: ";
    seq.process(print);
    std::cout << std::endl;
    
    // Batch-modify list contents
    std::cout << "\nSquare, then increment list elements...\n";
    seq.process(square);
    seq.process(inc);
    std::cout << "List: ";
    seq.process(print);
    std::cout << std::endl;
    
    // Access item at given index
    std::cout << "\nEnter item index to print <q to quit>: ";
    int i;
    while (std::cin >> i)
    {
        if (seq.at(i) != nullptr)
            std::cout << "List [" << i << "] = " << *seq.at(i) << "\n";
        else
            std::cout << "Index out of bounds!\n";
        std::cout << "Next item index: ";
    }
    
    std::cout << "\nDone.\n";
}
