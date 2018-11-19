//
//  902.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 19/11/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
#include <string>

namespace
{
    void strcount(const std::string&);
}

//   =============================
//   |       Main function       |
//   =============================
void show902()
{
    std::string input;
    
    std::cout << "Enter a line:\n";
    std::getline(std::cin, input);
    while (input != "")
    {
        strcount(input);
        std::cout << "Enter next line (empty line to quit):\n";
        std::getline(std::cin, input);
    }
    
    std::cout << "Done.\n";
}

namespace
{
    void strcount(const std::string& str)
    {
        static int total {0};           // static local variable
        total += str.length();
        std::cout
            << "\"" << str << "\" contains "
            << str.length() << " characters;\n"
            << total << " characters total.\n";
    }
}
