//
//  1202.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 27/02/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "String1202.hpp"

void show1202()
{
    using e1202::String;
    
    String s1(" and I am a C++ student.");
    String s2 = "Please enter your name: ";
    String s3;
    
    std::cout << s2;                            // overloaded << operator
    std::cin >> s3;                             // overloaded >> operator
    
    s2 = "My name is " + s3;                    // overloaded =, + operators
    std::cout << s2 << ".\n";
    
    s2 += s1;                                   // overloaded += operator
    s2.upperCase();                             // convert string to upper case
    
    std::cout << "The string\n" << s2 << "\ncontains " << s2.count('A')
              << " 'A' characters in it.\n";
    
    s1 = "red";                                 // overloaded = operator
    String rgb[3]
    {
        s1,
        "green",
        "blue"
    };
    std::cout << "Enter the name of a primary colour for mixing light: ";
    String answer;
    bool success = false;
    while (std::cin >> answer)
    {
        answer.lowerCase();                     // convert to lower case
        
        for (int i = 0; i < 3; i++)
        {
            if (answer == rgb[i])               // overloaded == operator
            {
                std::cout << "That's right!\n";
                success = true;
                break;
            }
        }
        
        if (success)
            break;
        
        std::cout << "Try again!\n";
    }
    
    std::cout << "\nDone.\n";
}
