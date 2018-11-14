//
//  708b.cpp
//  C++ Primer Plus Exercises
//
//  Listing 7.15 refactored to use a structure containing a C-style array
//  (similiar to the basic design of the std::array)
//

#include <iostream>


namespace
{
//  Constant data
    constexpr int Seasons {4};
    const char* const SeasonNames[Seasons]           // const pointers to const data
    {
        "Spring", "Summer", "Autumn", "Winter"
    };
    
//  Array structure
    struct Array
    {
        double entries[Seasons];
    };
    
//  Function prototypes
    void fillExpenses(Array* p_array);
    void showExpenses(Array array);
}

//   =============================
//   |       Main function       |
//   =============================
void show708b()
{
    Array expenses;
    fillExpenses(&expenses);
    showExpenses(expenses);
}

namespace
{
    void fillExpenses(Array* p_array)
    {
        for (int i = 0; i < Seasons; i++)
        {
            std::cout << "Enter " << SeasonNames[i] << " expenses: ";
            std::cin >> p_array->entries[i];
        }
    }
    
    void showExpenses(Array array)
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
}
