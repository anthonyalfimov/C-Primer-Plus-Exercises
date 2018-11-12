//
//  708a.cpp
//  C++ Primer Plus Exercises
//
//  Listing 7.15 refactored to use ordinary (C-style) arrays
//

#include <iostream>

//  Constant data
constexpr int Seasons {4};
const char* const SeasonNames[Seasons]          // const pointers to const data
{
    "Spring", "Summer", "Autumn", "Winter"
};

namespace e708a
{
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

