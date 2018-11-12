//
//  604.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 26/09/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
#include <cctype>

constexpr int StrSize {50};
constexpr int MemberCount {4};

namespace e604
{
//  Benevolent Order of Programmers name structure
    struct Bop
    {
        const char fullname[StrSize];
        const char title[StrSize];
        const char bopname[StrSize];
        int preference;
    };
    
    enum {fullname, title, bopname};
    
//  Function prototypes
    void showMenu();
    char getCharacter();
    bool isGoodInput(char);
    
    void displayFullname();
    void displayTitle();
    void displayBopname();
    void displayPreference();
}

using namespace e604;

const Bop members[MemberCount]
{
    {
        "Boris Forest",
        "CEO",
        "FluffyTat",
        bopname
    },
    {
        "Judy Froo",
        "PA",
        "SexyBun5000",
        fullname
    },
    {
        "John Ohh",
        "Junior Developer",
        "JUNI0R",
        title
    },
    {
        "Too Faa",
        "Senior Developer",
        "Foo",
        title
    }
};

void show604()
{
    std::cout << "Benevolent Order of Programmers report\n";
    showMenu();
    char choice;
    while ((choice = getCharacter()) != 'q')
    {
        switch (choice) {
            case 'a' :      displayFullname();      break;
            case 'b' :      displayTitle();         break;
            case 'c' :      displayBopname();       break;
            case 'd' :      displayPreference();    break;
            default  :      std::cout << "Invalid input! Try again.\n";
        }
        while (std::cin.get() != '\n')      // clean the buffer
            continue;                       // in case of input with multiple characters
    }
    std::cout << "Done!\n";
}

void e604::displayFullname()
{
    for (int i = 0; i < MemberCount; ++i)
    {
        std::cout << members[i].fullname << "\n";
    }
}

void e604::displayTitle()
{
    for (int i = 0; i < MemberCount; ++i)
    {
        std::cout << members[i].title << "\n";
    }
}

void e604::displayBopname()
{
    for (int i = 0; i < MemberCount; ++i)
    {
        std::cout << members[i].bopname << "\n";
    }
}

void e604::displayPreference()
{
    for (int i = 0; i < MemberCount; ++i)
    {
        switch (members[i].preference)
        {
            case fullname   : std::cout << members[i].fullname << "\n"; break;
            case title      : std::cout << members[i].title << "\n"; break;
            case bopname    : std::cout << members[i].bopname << "\n"; break;
        }
    }
}

char e604::getCharacter()
{
//  showTheMenu();                  // Add to display menu every time input is prompted
    std::cout << "\nYour choice: ";
    return std::tolower(std::cin.get());
}

bool e604::isGoodInput(char ch)
{
    return (ch >= 'a' && ch <= 'd') || ch == 'q';
}

void e604::showMenu()
{
    std::cout <<
    "===================================================\n"
    "a) display by name         b) display by title\n"
    "c) display by bopname      d) display by preference\n"
    "q) quit\n"
    "===================================================\n";
}
