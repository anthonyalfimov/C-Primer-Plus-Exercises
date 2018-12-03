//
//  708a.cpp
//  C++ Primer Plus Exercises
//
//  Listing 7.15 refactored to use ordinary (C-style) arrays
//

#include <iostream>

namespace
{
//  Constant data
    constexpr int Seasons {4};
    const char* const SeasonNames[Seasons]          // const pointers to const data
    {
        "Spring", "Summer", "Autumn", "Winter"
    };
    
//  Function prototypes
    void fillExpenses(double array[], int size);
    void showExpenses(const double array[], int size);
}

//   =============================
//   |       Main function       |
//   =============================
void show708a()
{
    double expenses[Seasons];
    fillExpenses(expenses, Seasons);
    showExpenses(expenses, Seasons);
}

namespace
{
    void fillExpenses(double array[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << "Enter " << SeasonNames[i] << " expenses: ";
            std::cin >> array[i];
        }
    }
    
    void showExpenses(const double array[], int size)
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
}
