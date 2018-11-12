//
//  708b.cpp
//  C++ Primer Plus Exercises
//
//  Listing 7.15 refactored to use a structure containing a C-style array
//  (similiar to the basic design of the std::array)
//

#include <iostream>

//  Constant data
constexpr int Seasons {4};
const char* SeasonNames[Seasons]
{
    "Spring", "Summer", "Autumn", "Winter"
};

namespace e708b {
    // Array structure
    struct Array
    {
        double entries[Seasons];
    };
    
    //  Function prototypes
    void fillExpenses(Array* p_array);
    void showExpenses(Array array);
}

using namespace e708b;

void show708b()
{
    Array expenses;
    fillExpenses(&expenses);
    showExpenses(expenses);
}

void e708b::fillExpenses(Array* p_array)
{
    for (int i = 0; i < Seasons; i++)
    {
        std::cout << "Enter " << SeasonNames[i] << " expenses: ";
        std::cin >> p_array->entries[i];
    }
}

void e708b::showExpenses(Array array)
{
    double total {};
    std::cout << "\nEXPENSES\n";
    for (int i = 0; i < Seasons; i++)
    {
        std::cout << SeasonNames[i] << ": $" << array.entries[i] << "\n";
        total += array.entries[i];
    }
    std::cout << "TOTAL : $" << total;
}
