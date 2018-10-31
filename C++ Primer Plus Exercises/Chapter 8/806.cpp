//
//  806.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 30/10/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
#include <cstring>

namespace e806
{
    template <typename T>
    T maxn(T arr[], int size);
    
    template <>
    const char* maxn(const char* arr[], int size);
}

using namespace e806;

void show806()
{
    int intTest[6] {12, 2, 41, 5, 32, 41};
    double doubleTest[4] {12.23, 1.2453e2, 123.2, -9.0};
    
    const char* strTest[5]
    {
        "I am so sad",
        "Depression",
        "Disappointment",
        "Hey, la la la!",
        "Oh, no"
    };
    
    std::cout << "Max in int array:    " << maxn(intTest, 6) << "\n";
    std::cout << "Max in double array: " << maxn(doubleTest, 4) << "\n";
    std::cout << "Max in string array: " << maxn(strTest, 5) << "\n";
}

template <typename T>
T e806::maxn(T arr[], int size)
{
    T max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max) max = arr[i];
    
    return max;
}

template <>
const char* e806::maxn(const char* arr[], int size)
{
    int imax = 0;       // index of the longest string
    for (int i = 1; i < size; i++)
        if (std::strlen(arr[i]) > std::strlen(arr[imax]))
            imax = i;
    
    return arr[imax];
}
