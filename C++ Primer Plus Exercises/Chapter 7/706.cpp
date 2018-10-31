//
//  706.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 10/10/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>

namespace e706 {
    constexpr int ArraySize {10};
    
    // Function names from the exercise are used:
    
    /**
     Fills passed array with user input, returns the actual number of entries
     
     @param array pointer to array
     @param size array size
     @return number of entries
     */
    int fillArray(double array[], int size);
    
    void showArray(const double array[], int size);
    
    void reverseArray(double array[], int size);
}

using namespace e706;

void show706()
{
    double values[ArraySize];
    int entries {fillArray(values, ArraySize)};    // fill the array, get number of entries
    std::cout << entries << " value(s) entered.\n\n";
    showArray(values, entries);
    
    reverseArray(values, entries);
    showArray(values, entries);
    
    reverseArray(values + 1, entries - 2);
    showArray(values, entries);
    
    std::cout << "\nDone.\n";
}

int e706::fillArray(double array[], int size)
{
    int i {};
    
    std::cout << "Enter up to " << size << " numbers <q to stop>:\n";
    while (i < size && (std::cin >> array[i]))
        ++i;
   
    return i;
}

void e706::showArray(const double array[], int size)
{
    if (size == 0)
        std::cout << "No data!\n";
    else
    {
        std::cout << array[0];
        for (int i = 1; i < size; i++)
            std::cout << "\t\t" << array[i];
        std::cout << "\n";
    }
}

void e706::reverseArray(double array[], int size)
{
    if (size == 0)
        return;
    else
    {
        int front, back;
        
        for (front = 0, back = size - 1;
             front < back;
             front++, back--)
        {
            double temp {array[back]};
            array[back] = array[front];
            array[front] = temp;
        }
    }
}
