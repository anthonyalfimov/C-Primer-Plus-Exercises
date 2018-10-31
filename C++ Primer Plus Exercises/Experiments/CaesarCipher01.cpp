//
//  CaesarCipher01.cpp
//  Created by Anthony on 29/09/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
#include <cctype>                       // character type funcrions

const int LetterCount {26};

void showCaesarCipher01()
{
    std::cout << "Please, enter the shift: ";
    int shift {};
    while (!(std::cin >> shift) || shift < 0)
                                        // while input unsuccessful or negative
    {
        std::cout << "Invalid input! Try again: ";
        std::cin.clear();               // reset input fail state
        while (std::cin.get() != '\n')  // clear input buffer
            continue;
    }
    std::cin.get();                     // clean up the '\n' left in the buffer
    
    std::cout << "Enter your message now <simulate EOF to quit>:\n";
    char input;
    while (std::cin.get(input))         // while input is successful
    {
        if (std::islower(input))        // if input is lowercase letter
            input = static_cast<char>('a' + (input - 'a' + shift) % LetterCount);
        else if (std::isupper(input))   // if input is uppercase letter
            input = static_cast<char>('A' + (input - 'A' + shift) % LetterCount);
        
        std::cout << input;
    }
    std::cout << "Done!\n";
}
