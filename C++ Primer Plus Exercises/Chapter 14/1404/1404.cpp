//
//  1404.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 02/07/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include <cstring>          //  for strchr() - return address of char in C-string, null if not found
#include "PersonType1404.hpp"

const int size = 4;

void show1404()
{
    using namespace e1404;
    
    Person* people[size];
    
    int ct;
    
    for (ct = 0; ct < size; ct++)
    {
        char choice;
        std::cout << "Another person walks into the saloon. It's a:\n"
        << "r: regular person   g: gunslinger   p: poker player   b: bad dude   q: quit\n";
        
        std::cin >> choice;
        
        while (std::strchr("rgpbq", choice) == nullptr)
        {
            std::cout << "Please enter \"r\", \"g\", \"p\", \"b\" or \"q\": ";
            std::cin >> choice;
        }
        
        if (choice == 'q')
        {
            std::cout << "\n";
            break;
        }
        
        switch(choice)
        {
            case 'r':   people[ct] = new Person;
                break;
            case 'g':   people[ct] = new Gunslinger;
                break;
            case 'p':   people[ct] = new PokerPlayer;
                break;
            default:    people[ct] = new BadDude;
        }
        
        std::cin.get();
        people[ct]->set();
        std::cout << "\n";
    }
    
    if (ct == 0)
        std::cout << "The saloon is empty!\n";
    else
    {
        std::cout << "Here are the people who gathered in the saloon:\n";
        
        for (int i = 0; i < ct; i++)
        {
            std::cout << "\n";
            people[i]->show();
        }
        
        for (int i = 0; i < ct; i++)
            delete people[i];
    }
    
    std::cout << "\nDone.\n";
}

