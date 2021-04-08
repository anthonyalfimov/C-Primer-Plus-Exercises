//
//  1603.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 08/04/2021.
//  Copyright © 2021 Anthony. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

namespace
{
    void sanitiseInput (std::string& entry);
}

void show1603()
{
//= Read the word list from file
    std::string sourceFileName ("Words.txt");
    std::ifstream sourceFile;
    
    // For simplicity, we expect that the provided txt file is placed in the
    //  same location as the compiled executable
    sourceFile.open (sourceFileName);
    
    if (! sourceFile.is_open()) // on failure to open the file
    {
        std::cout << "Could not open the file " << sourceFileName << "\n"
                  << "Program terminating.\n";
        exit (EXIT_FAILURE);    // <cstdlib> function that communicated failure to the OS
    }
    
    std::vector<std::string> wordList;
    
    do
    {
        std::string wordEntry;
        sourceFile >> wordEntry;
        sanitiseInput (wordEntry);
        
        if (wordEntry.empty())
            continue;
        
        wordList.push_back (wordEntry);
    }
    while (sourceFile.good());
    
    sourceFile.close();
    
    if (wordList.empty())
    {
        std::cout << "File " << sourceFileName << " did not contain any words.\n"
                  << "Program terminating.\n";
        exit (EXIT_FAILURE);    // <cstdlib> function that communicated failure to the OS
    }
    
    // Initialise simple RNG
    std::srand (static_cast<unsigned> (std::time (nullptr)));

    char playChoice;
    
    std::cout << "Will you play a word game? <y/n> ";
    std::cin >> playChoice;
    playChoice = std::tolower (playChoice);
    
    while (playChoice == 'y')
    {
        std::string targetWord = wordList[std::rand() % wordList.size()];
        const auto targetLength = targetWord.length();
        
        std::string guessedWord (targetLength, '-');
        std::string wrongGuesses;
        
        int guesses = 6;
        
        std::cout
            << "Guess the secret word. It has " << targetLength << " letters, and you "
            << "guess one letter at a time. You get " << guesses << " wrong guesses.\n"
            << "Your word: " << guessedWord << "\n";
        
        while (guesses > 0 && guessedWord != targetWord)
        {
            char letter;
            std::cout << "Guess a letter: ";
            std::cin >> letter;
            
            if (wrongGuesses.find (letter) != std::string::npos
                || guessedWord.find (letter) != std::string::npos)
            {
                std::cout << "You already guessed that! Try again.\n";
                continue;
            }
            
            auto letterPosition = targetWord.find (letter);
            
            if (letterPosition == std::string::npos)
            {
                std::cout << "Bad guess!\n\n";
                --guesses;
                wrongGuesses += letter;     // add bad guess to the string
            }
            else
            {
                std::cout << "Good guess!\n\n";
                
                do
                {
                    guessedWord[letterPosition] = letter;
                    letterPosition = targetWord.find (letter, letterPosition + 1);
                }
                while (letterPosition != std::string::npos);
            }
            
            std::cout << "Your word: " << guessedWord << "\n";
            
            if (guessedWord != targetWord)
            {
                if (! wrongGuesses.empty())
                    std::cout << "Wrong guesses: " << wrongGuesses << "\n";
                
                std::cout << guesses << " wrong guesses left.\n";
            }
        }
        
        if (guesses > 0)
            std::cout << "That's right!\n";
        else
            std::cout << "Sorry, the word is " << targetWord << ".\n";
        
        std::cout << "\nWill you play another? <y/n> ";
        std::cin >> playChoice;
        playChoice = std::tolower(playChoice);
    }
    
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
}

