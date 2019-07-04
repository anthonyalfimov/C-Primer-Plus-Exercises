//
//  1405.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 04/07/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "EmployeeType1405.hpp"

void show1405()
{
    using namespace e1405;
    
    Employee em ("Trip", "Harris", "Thumper");
    std::cout << em << "\n";
    em.showAll();
    
    Manager ma ("Amorphia", "Spindragon", "Nuancer", 5);
    std::cout << "\n" <<  ma << "\n";
    ma.showAll();
    
    Fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
    std::cout << "\n" << fi << "\n";
    fi.showAll();
    
    HighFink hf1 (ma, "Curly Kew");     // recruitment
    std::cout << "\n" << hf1 << "\n";
    hf1.showAll();
    
    std::cout << "\nTest copy constructor:\n";
    HighFink test(hf1);
    test.showAll();
    
    std::cout << "\nPress a key for the next phase:\n";
    std::cin.get();
    
    HighFink hf2;
    hf2.setAll();
    
    std::cout << "\nUsing an Abstract Employee* pointer:\n\n";
    AbstractEmployee* staff[4] {&em, &fi, &hf1, &hf2};
    
    for (int i = 0; i < 4; ++i)
    {
        staff[i]->showAll();
        std::cout << "\n";
    }
    
    std::cout << "\nDone.\n";
}
