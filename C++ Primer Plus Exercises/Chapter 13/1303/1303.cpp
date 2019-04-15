//
//  1303.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 15/04/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include <string>
#include <cctype>
#include "DMA1303.hpp"

const int itemCount = 3;

void inputClear() { while (std::cin.get() != '\n') continue; }

void show1303()
{
    using e1303::AbstractDMA;
    using e1303::BaseDMA;
    using e1303::LacksDMA;
    using e1303::HasDMA;
    
    AbstractDMA* p_items[itemCount];                // array of pointers to abstract base class
    
    std::string tmpLabel;
    std::string tmpExtra;
    int tmpRating;
    
    char choice;
    
    for (int i = 0; i < itemCount; i++)
    {
        std::cout << "Enter item label: ";
        std::getline(std::cin, tmpLabel);
        
        std::cout << "Enter item rating: ";
        
        while (!(std::cin >> tmpRating) || tmpRating < 0)
        {
            std::cout << "Must be a positive integer: ";
            std::cin.clear();
            inputClear();
        }
        
        inputClear();
        
        while (true)
        {
            std::cout << "Choose item type: [B]aseDMA, [L]acksDMA or [H]asDMA: ";
            std::cin.get(choice);
            inputClear();
            choice = std::tolower(choice);
        
            switch (choice)
            {
                case 'b':
                    p_items[i] = new BaseDMA(tmpLabel.c_str(), tmpRating);
                    break;
                    
                case 'l':
                    std::cout << "Enter item colour: ";
                    std::getline(std::cin, tmpExtra);
                    p_items[i] = new LacksDMA(tmpLabel.c_str(), tmpRating, tmpExtra.c_str());
                    break;
                    
                case 'h':
                    std::cout << "Enter item style: ";
                    std::getline(std::cin, tmpExtra);
                    p_items[i] = new HasDMA(tmpLabel.c_str(), tmpRating, tmpExtra.c_str());
                    break;
                    
                default:
                    std::cout << "Invalid input! ";
                    continue;
            }
        
            std::cout << "Created " << *p_items[i] << "\n\n";   // use general overload defined in
                                                                //   AbstractDMA based on ptr type
            break;
        }
    }
    
    std::cout << "====[ Entered items ]====\n";
    
    for (int i = 0; i < itemCount; i++)
    {
        p_items[i]->view();
        std::cout << "\n";
    }
    
    std::cout << "Done.\n";
}
