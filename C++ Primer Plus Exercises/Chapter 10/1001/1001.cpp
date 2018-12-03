//
//  1001.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 03/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
#include "BankAccount1001.hpp"

void show1001()
{
    Account dave {"Dave Bowman", "19682001"};
    std::cout << "Account created:\n";
    dave.print();
    
    std::cout << "\nDeposit recieved:\n";
    dave.deposit(500);
    dave.print(true);
    
    std::cout << "\nDave, please specify how much you would like to withdraw:\n$";
    double amount;
    while (!(std::cin >> amount) || amount < 0 || !dave.withdraw(amount))
    {
        std::cout << "I'm sorry, Dave. I'm afraid I can't do that.\n";
        std::cout << "Would you care to try again?\n$";
        
        std::cin.clear();
        while (std::cin.get() != '\n')
            continue;
    }
    std::cout << "\nSuccess!\n";
    dave.print(true);
    
    std::cout << "\nDone.\n";
}
