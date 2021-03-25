//
//  1601.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 25/03/2021.
//  Copyright © 2021 Anthony. All rights reserved.
//

#include <iostream>
#include <string>

namespace
{
    bool isPalindrome (const std::string& string);
}

void show1601()
{
    std::string input;
    
    while (true)
    {
        std::cout << "Enter a word (\"quit\" to quit): ";
        std::getline (std::cin, input);
        
        if (input == "quit")
            break;
        
        if (isPalindrome (input))
            std::cout << input << " is a palindrome!\n\n";
        else
            std::cout << input << " is not a palindrome!\n\n";
    }
    
    std::cout << "\nDone.\n";
}

namespace
{
    bool isPalindrome (const std::string& string)
    {
        bool result = true;
        
        const int length = static_cast<int> (string.length());
        const int halfPoint = length / 2;
        
        for (int i = 0; i < halfPoint; ++i)
        {
            if (string[i] != string[length - 1 - i])
                result = false;
        }
        
        return result;
    }
}
