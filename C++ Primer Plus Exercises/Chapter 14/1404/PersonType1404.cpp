//
//  PersonType1404.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 02/07/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include <cstdlib>              // for rand(), srand()
#include <ctime>                // for time()
#include "PersonType1404.hpp"

namespace e1404
{
//  Person methods
        
    void Person::show() const
    {
        getData();
        std::cout << "Specialisation: none\n";
    }
    
    void Person::set()
    {
        std::cout << "Enter data for a regular person\n";
        setData();
    }
    
    void Person::getData() const
    {
        std::cout << "Name: " << mFirstName << " " << mLastName << "\n";
    }
    
    void Person::setData()
    {
        std::cout << "First name: ";
        std::getline(std::cin, mFirstName);
        std::cout << "Last name: ";
        std::getline(std::cin, mLastName);
    }

//  Gunslinger methods
        
    void Gunslinger::show() const
    {
        Person::getData();
        std::cout << "Specialisation: Gunslinger\n";
        getData();
        std::cout << "Gun draw: " << draw() << " s\n";
    }
    
    void Gunslinger::set()
    {
        std::cout << "Enter data for a gunslinger\n";
        Person::setData();
        setData();
    }
    
    void Gunslinger::getData() const
    {
        std::cout << "Gun notches: " << mGunNotches << "\n";
    }
    
    void Gunslinger::setData()
    {
        std::cout << "Draw time: ";
        std::cin >> mDrawTime;
        std::cout << "Gun notches: ";
        std::cin >> mGunNotches;
        
        while (std::cin.get() != '\n')
            continue;
    }

//  PokerPlayer methods
    
    bool PokerPlayer::sIsInitialised = false;
    
    void PokerPlayer::initialise()
    {
        std::srand(static_cast<int>(std::time(nullptr)));
        std::cout << "Seeding rand()...\n";
        sIsInitialised = true;
    }
    
    void PokerPlayer::show() const
    {
        getData();
        std::cout << "Specialisation: Poker Player\n";
        std::cout << "Card draw: " << draw() << "\n";
    }
    
    Card PokerPlayer::draw() const
    {
        int choice = 1 + (std::rand()) % (Card::getTotalCount());
        return Card(choice);
    }

// BadDude methods
        
    void BadDude::show() const
    {
        Person::getData();
        std::cout << "Specialisation: Gunslinger, Poker Player\n";
        std::cout << "Gun draw: " << gunDraw() << " s\n";
        std::cout << "Card draw: " << cardDraw() << "\n";
    }
    
}   // end namespace e1404
