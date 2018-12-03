//
//  golf.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 16/11/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include "golf.hpp"
#include <cstring>
#include <iostream>

namespace e901
{
    void clearInputBuffer()                 // clear trailing input and '\n' from buffer
    {
        while (std::cin.get() != '\n')
            continue;
    }
    
    void setGolf(Golf& g, const char* name, int hc)
    {
        std::strncpy(g.fullname, name, Len);
        g.fullname[Len - 1] = '\0';         // enforce null-termination in case
                                            //     `name` didn't fit in `g.fullname`
        g.handicap = hc;
    }

    int setGolf(Golf& g)
    {
        std::cout << "Full name: ";
        if (!std::cin.get(g.fullname, Len)) // if empty line is read
        {
            std::cin.clear();               // clear failbit
            std::cin.get();                 // clear '\n' from buffer
            return 0;                       // return "empty string read"
        }
        clearInputBuffer();                 // clear chars that might not fit into
                                            //     target array and '\n' from buffer
        
        std::cout << "Handicap: ";
        while(!(std::cin >> g.handicap))    // prompt input until it is valid
        {
            std::cout
                << "Invalid input, try again!\n"
                << "Handicap: ";
            std::cin.clear();
            clearInputBuffer();
        }
        clearInputBuffer();                 // clear trailing input and '\n' from buffer
        
        return 1;                           // return "successfull input"
    }

    void handicap(Golf& g, int newHandicap)
    {
        std::cout
            << "Handicap for " << g.fullname
            << " changed from " << g.handicap
            << " to " << newHandicap << ".\n";
        g.handicap = newHandicap;
    }
    
    void showGolf(const Golf& g)
    {
        std::cout << g.fullname << ", handicap: " << g.handicap << "\n";
    }
}
