//
//  607.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 26/09/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
#include <string>
#include <cctype>

bool isVowel(char);

std::string sentinel {"q"};

void show607()
{
    int countVowel {};
    int countCons {};
    int countOther {};
    
    std::cout << "Enter words <q to quit>:\n";
    
    std::string input;
    std::cin >> input;
    while (input != sentinel)
    {
        if (!std::isalpha(input[0]))
            ++countOther;
        else if (isVowel(input[0]))
            ++countVowel;
        else
            ++countCons;
        std::cin >> input;
    }
    
    std::cout << countVowel << " words beginning with vowels,\n"
    << countCons << " words beginning with consonants,\n"
    << countOther << " others.\n";
}

bool isVowel(char ch)
{
    ch = std::tolower(ch);
    return
    ch == 'a' ||
    ch == 'e' ||
    ch == 'i' ||
    ch == 'o' ||
    ch == 'u' ||
    ch == 'y';
}
