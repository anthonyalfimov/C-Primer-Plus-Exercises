//
//  601.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 25/09/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
#include <cctype>

void show601()
{
    std::cout << "Input characters. Type @ to finish.\n";
    
    char ch;
    
    while (std::cin.get(ch) && ch != '@')   // until sentinel character is encountered
    {
        if (!std::isdigit(ch))              // if char is not a digit
        {
            if (std::islower(ch))           // test if lower case character
                ch = std::toupper(ch);
            else if (std::isupper(ch))      // test if upper case character
                ch = std::tolower(ch);
            
            std::cout << ch;                // echo character
        }
    }
    
    std::cout << "\nDone!\n";
}
