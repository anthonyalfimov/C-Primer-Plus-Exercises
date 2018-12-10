//
//  LinkedList101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 05/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
#include "LinkedListType01.hpp"

namespace LinkedList01
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

void showLinkedList101()
{
    using namespace LinkedList01;
    
    // Create an empty list
    List seq;
    
    // Confirm that list is empty
    if (seq.isEmpty())
        std::cout << "List: empty\n";
    
    // Fill the list with 10 consequent integers
    std::cout << "\nFilling the list...\n";
    for (int i = 0; i < 10; i++)
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
    
    // Insert an item into list
    std::cout << "\nInsert a couple of 0's into the list...\n";
    if (!seq.insertAfter(5, 0)) std::cout << "...failed...\n";
    if (!seq.insertAfter(9, 0)) std::cout << "...failed...\n";
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
