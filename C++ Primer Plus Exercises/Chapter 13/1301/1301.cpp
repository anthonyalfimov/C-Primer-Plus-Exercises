//
//  1301.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 12/04/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "classic1301.hpp"

void bravo(e1301::CD&);

void show1301()
{
    using e1301::CD;
    using e1301::Classic;
    
    CD cd1("Beatles", "Capitol", 14, 35.5);
    Classic cd2 = Classic("Piano Sonata in B flat, Fantasia in C",
                          "Alfred Brendel", "Philips", 2, 57.17);
    
    CD* p_cd = &cd1;
    
    std::cout << "Using object directly:\n";
    cd1.report();           // use CD method
    cd2.report();           // use Classic method
    
    std::cout << "\nUsing type CD* pointer to objects:\n";
    p_cd->report();         // use CD method for CD object
    p_cd = &cd2;
    p_cd->report();         // use Classic method for Classic object
    
    std::cout << "\nCalling a function with a CD reference argument:\n";
    bravo(cd1);             // use CD method
    bravo(cd2);             // use Classic method
    
    std::cout << "\nTesting assignment:\n";
    Classic copy;
    copy.report();
    copy = cd2;
    copy.report();
    
    std::cout << "\nDone.\n";
}

void bravo(e1301::CD& disk)
{
    disk.report();
}
