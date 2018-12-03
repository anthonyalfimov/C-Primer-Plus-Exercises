//
//  807.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 30/10/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>

namespace
{
//  Struct name size
    constexpr int stringSize {50};
//  Template A: array elements are data
    template <typename T>
    T sumArray(T arr[], int n);
    
//  Template B: array elements are pointers
    template <typename T>
    T sumArray(T* arr[], int n);
    
    struct Debts
    {
        char name[stringSize];
        double amount;
    };
}

//   =============================
//   |       Main function       |
//   =============================
void show807()
{
//  Int array:
    int things[6] {13, 31, 103, 301, 310, 130};
//  Struct array:
    struct Debts mr_E[3]        // keyword `struct` is optional in C++ in declaration
    {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0}
    };
//  Pointer-to-double array:
    double* pd[3];              // set pointers to the amount members of mr_E struct
    for (int i = 0; i < 3; i++)
        pd[i] = &mr_E[i].amount;

//  Things is an array of int - uses Template A
    std::cout << "Total number of Mr. E's things: " << sumArray(things, 6) << "\n";

//  pd is an array of pointers-to-double - uses Template B (more specialized)
    std::cout << "Total sum of Mr. E's debts: " << sumArray(pd, 3) << "\n";
}

namespace
{
    //  Template A
    template <typename T>
    T sumArray(T arr[], int n)
    {
        std::cout << "(A) ";
        T sum {0};
        for (int i = 0; i < n; i++)
            sum += arr[i];
        
        return sum;
    }

    //  Template B
    template <typename T>
    T sumArray(T* arr[], int n)
    {
        std::cout << "(B) ";
        T sum {0};
        for (int i = 0; i < n; i++)
            sum += *arr[i];
        
        return sum;
    }
}
