//
//  904.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 19/11/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
#include "Sales904.hpp"

//   =============================
//   |       Main function       |
//   =============================
void show904()
{
    using namespace SALES;
    
    Sales companyA;
    double data[5] {1300.0, 2100.0, 1000.0, 2500.0, 1200.0};
    
    setSales(companyA, data, 5);
    std::cout << "Company A Report:\n";
    showSales(companyA);
    
    Sales companyB;
    std::cout << "\nCompany B Report:\n";
    setSales(companyB);
    showSales(companyB);
}
