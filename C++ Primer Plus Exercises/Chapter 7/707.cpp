//
//  707.cpp
//  C++ Primer Plus Exercises
//
//  Listing 7.7 refactored to use range for passing arrays to
//  functions
//

#include <iostream>

namespace e707 {
    constexpr int MaxEntries {5};
    
    /**
     Fills the passed array with user input and returns the pointer to a location
     one past the last input entry. Negative values and non-numbers terminate input.
     
     @param begin pointer to the first element in the array
     @param end pointer to the one-past-the-last element of the array
     @return pointer to the one-passt-the-last input element
     */
    double* fillEntires(double* begin, double* end);
    
    /**
     Displays contents of the passed array
     
     @param begin pointer to the first element in the array
     @param end pointer to the one-past-the-last element of the array
     */
    void showEntries(const double* begin, const double* end);
    
    /**
     Multiplies all elements of the passed array by the specified factor
     
     @param factor factor by which all values in the passed array are multiplied
     @param begin pointer to the first element in the array
     @param end pointer to the one-past-the-last element of the array
     */
    void revalueEntries(double factor, double* begin, double* end);
}

using namespace e707;

void show707()
{
    double properties[MaxEntries];
    
    double* propertiesEnd {fillEntires(properties, properties + MaxEntries)};
    showEntries(properties, propertiesEnd);
    
    if (properties != propertiesEnd)
    {
        std::cout << "Enter revaluation factor: ";
        double factor;
        while (!(std::cin >> factor) || factor < 0)   // bad input
        {
            std::cin.clear();
            while (std::cin.get() != '\n')
                continue;
            std::cout << "Bad input! Please enter a number: ";
        }
        
        revalueEntries(factor, properties, propertiesEnd);
        showEntries(properties, propertiesEnd);
    }
    std::cout << "Done!\n";
}

double* e707::fillEntires(double* begin, double* end)
{
    double value;
    double* pt;     // pointer to current position in array
    
    for (pt = begin; pt != end; pt++)
    {
        std::cout << "Enter value #" << (pt - begin) + 1 << ": ";
        std::cin >> value;
        if (!std::cin)
        {
            std::cin.clear();
            while (std::cin.get() != '\n')
                continue;
            std::cout << "Bad input! Input process terminated.\n";
            break;
        }
        else if (value < 0)
        {
            std::cout << "Negative input! Input process terminated.\n";
            break;
        }
        *pt = value;
    }
    
    return pt;
}

void e707::showEntries(const double* begin, const double* end)
{
    for (const double* pt = begin; pt != end; pt++)
        std::cout << "Property #" << (pt - begin) + 1 << ": $" << *pt << "\n";
}

void e707::revalueEntries(double factor, double* begin, double* end)
{
    for (double* pt = begin; pt != end; pt++)
        *pt *= factor;
}
