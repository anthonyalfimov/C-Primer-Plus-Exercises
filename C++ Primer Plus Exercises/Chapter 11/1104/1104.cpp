//
//  1104.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 31/01/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "Time1104.hpp"

void show1104()
{
    using e1104::Time;
    
    Time aida(3, 35);
    Time tosca(2, 48);
    Time temp;
    
    std::cout << "Aida and Tosca:\n";
    std::cout << aida << "; " << tosca << "\n\n";
    
    temp = aida + tosca;
    std::cout << "Aida + Tosca: " << temp << "\n";
    
    temp = aida * 1.17;
    std::cout << "Aida * 1.17: " << temp << "\n";
    
    std::cout << "10.0 * Tosca: " << 10.0 * tosca << "\n\n";
    
    std::cout << "Try negative time!\n"
                 "1 hour - 90 minutes  = " << Time(1, 0) - Time(0, 90) << "\n"
                 "20 minutes - 2 hours = " << Time(0, 20) - Time(2, 0) << "\n";
}

