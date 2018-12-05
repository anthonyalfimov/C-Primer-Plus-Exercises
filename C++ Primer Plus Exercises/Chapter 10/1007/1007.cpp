//
//  1007.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 05/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
#include "Plorg.hpp"

void show1007()
{
    std::cout << "Create a default Plorg:\n";
    Plorg plorga;
    plorga.report();
    std::cout << "\nCreate a friend for " << plorga.name() << ":\n";
    Plorg plorgus("Plorgus");
    plorgus.report();
    std::cout << "\n" << plorga.name() << " has a friend now!\n";
    plorga.cUpdate(75);
    plorgus.cUpdate(50);
    std::cout << "\nLooks like " << plorgus.name() << " is not impressed...\n";
    plorga.cUpdate(25);
    
    std::cout << "\nPlorg status at the end of simulation:\n";
    plorga.report();
    plorgus.report();
    std::cout << "\nDone.\n";
}
