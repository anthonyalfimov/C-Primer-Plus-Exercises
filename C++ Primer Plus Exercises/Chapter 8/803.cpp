//
//  803.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 30/10/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
#include <string>
#include <cctype>

namespace e803
{
    void makeUpperCase(std::string & str);
}

using namespace e803;

void show803()
{
    std::string input;
    
    std::cout << "Enter a string (q to quit): ";
    std::getline(std::cin, input);
    while (std::cin && input != "q")
    {
        makeUpperCase(input);
        std::cout << input << "\n";
        std::cout << "Next string (q to quit): ";
        std::getline(std::cin, input);
    }
    std::cout << "\nDone\n";
}

void e803::makeUpperCase(std::string & str)
{
    for (int i = 0; i < str.length(); i++)
        str[i] = std::toupper(str[i]);
}
