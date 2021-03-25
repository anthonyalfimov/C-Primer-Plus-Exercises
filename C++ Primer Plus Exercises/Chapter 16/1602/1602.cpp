//
//  1602.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 25/03/2021.
//  Copyright © 2021 Anthony. All rights reserved.
//

#include <iostream>
#include <string>
#include <cctype>

namespace
{
    void sanitiseInput (std::string& string);
    void sanitizeInput (std::string& string);
    bool isPalindrome (const std::string& string);
}

void show1602()
{
    std::string input;
    
    while (true)
    {
        std::cout << "Enter a word (\"quit\" to quit): ";
        std::getline (std::cin, input);
        //sanitiseInput (input);
        sanitizeInput (input);
        
        if (input == "quit")
            break;
        
        if (isPalindrome (input))
            std::cout << input << " is a palindrome!\n\n";
        else
            std::cout << input << " is not a palindrome!\n\n";
    }
    
    // Silence the "Unused warning:
    sanitiseInput (input);
    //sanitizeInput (input);
    
    std::cout << "\nDone.\n";
}

namespace
{
    /** Remove all non-alphabetic characters and convert to lowercase using
        STL algorithms.
    */
    void sanitiseInput (std::string& s)
    {
        // Remove all non-alphabetic character, while taking note of the
        //  past-the-end of useful range iterator ...
        auto garbageBegin = std::remove_if (s.begin(), s.end(),
                                            [] (unsigned char c) { return ! std::isalpha(c); });
        // ... to later clean up the leftorvers after std::remove()
        s.erase (garbageBegin, s.end());
        
        // Convert the remains to lower case:
        for (auto& c : s)
            c = std::tolower (static_cast<unsigned char>(c));
    }
    
    /** Remove all non-alphabetic characters and convert to lowercase, but
        iterate through the characters just once.
     
    */
    void sanitizeInput (std::string& s)
    {
        auto iter = s.begin();
        
        while (iter != s.end())
        {
            const auto ch = static_cast<unsigned char> (*iter);
            
            if (std::isalpha (ch))
            {
                *iter = std::tolower (ch);
                ++iter;
            }
            else
            {
                iter = s.erase (iter);
            }
        }
    }
    
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
