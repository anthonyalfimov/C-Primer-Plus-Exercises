//
//  708a.cpp
//  C++ Primer Plus Exercises
//
//  Listing 7.15 refactored to use ordinary (C-style) arrays
//

#include <iostream>

namespace e708a {
    //  Constant data
    constexpr int Seasons {4};
    const char* SeasonNames[Seasons]
    {
        "Spring", "Summer", "Autumn", "Winter"
    };
    
    //  Function prototypes
    void fillExpenses(double array[], int size);
    void showExpenses(const double array[], int size);
}

using namespace e708a;

void show708a()
{
    double expenses[Seasons];
    fillExpenses(expenses, Seasons);
    showExpenses(expenses, Seasons);
}

void e708a::fillExpenses(double array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "Enter " << SeasonNames[i] << " expenses: ";
        std::cin >> array[i];
    }
}

void e708a::showExpenses(const double array[], int size)
{
    double total {};
    std::cout << "\nEXPENSES\n";
    for (int i = 0; i < size; i++)
    {
        std::cout << SeasonNames[i] << ": $" << array[i] << "\n";
        total += array[i];
    }
    std::cout << "TOTAL : $" << total;
}

