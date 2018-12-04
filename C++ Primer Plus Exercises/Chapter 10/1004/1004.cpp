//
//  1004.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 04/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
#include "Sales1004.hpp"

void show1004()
{
    using namespace SALES;
    
    double data[5] {1300.0, 2100.0, 1000.0, 2500.0, 1200.0};
    Sales companyA {data, 5};
    
    std::cout << "Company A Report:\n";
    companyA.show();
    
    Sales companyB;
    std::cout << "\nCompany B Report:\n";
    companyB.set();
    companyB.show();
}
