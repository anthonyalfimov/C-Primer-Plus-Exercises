//
//  710.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 11/10/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>


namespace
{
//  Constant data:
    constexpr int opNumber {4};
    const char* const opNames[opNumber]
    {
        "Sum: ",
        "Difference: ",
        "Product: ",
        "Quotient: "
    };
    
//  Calculation functions:
    typedef double (*pcalc)(double, double);
    
    double add(double x, double y) { return x + y; }
    double subtract(double x, double y) { return x - y; }
    double multiply(double x, double y) { return x * y; }
    double divide(double x, double y) { return x / y; }
    
    double calculate(double x, double y, pcalc operation);
}

//   =============================
//   |       Main function       |
//   =============================
void show710()
{
    pcalc operations[opNumber]             // array of function pointers to operations
        {add, subtract, multiply, divide};
    
    double x, y;
    std::cout << "Enter x and y values: ";
    while (std::cin >> x >> y)
    {
        for (int i = 0; i < opNumber; i++)
            std::cout << opNames[i] << calculate(x, y, operations[i]) << "\n";
        std::cout << "Next x and y pair: ";
    }
    std::cout << "\nDone.\n";
}

namespace
{
    double calculate(double x, double y, pcalc operation)
    {
        return operation(x, y);
    }
}
