//
//  1304.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 15/04/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "VintagePort1304.hpp"

void show1304()
{
    using e1304::Port;
    using e1304::VintagePort;
    
    Port bottle1("Gallo", "tawny", 5);
    std::cout << "Created: " << bottle1 << "\n";
    
    VintagePort bottle2("Taylor's", 10, "The Noble", 1985);
    std::cout << "Created: " << bottle2 << "\n";
    
    std::cout << "\nRestock...\n";
    bottle1 += 15;
    bottle2 += 12;
    
    bottle1.show();
    std::cout << "\n";
    bottle2.show();
    std::cout << "\n";
    
    std::cout << "Order 25 bottles from " << bottle2 << "...\n";
    bottle2 -= 25;
    std::cout << "Remaining bottles: " << bottle2.bottleCount() << "\n\n";
    
    Port bottle3;
    bottle3 = bottle2;
    bottle3 += 15;

    Port* p_bottle = &bottle3;
    std::cout << "Access Port-type copy of bottle2 with " << p_bottle->bottleCount()
              << "-bottle stock:\n";
    p_bottle->show();
    
    p_bottle = &bottle2;
    std::cout << "\nAccess VintagePort-type bottle2 with " << p_bottle->bottleCount()
              << "-bottle stock:\n";
    p_bottle->show();
    
    std::cout << "\nDone.\n";
}
