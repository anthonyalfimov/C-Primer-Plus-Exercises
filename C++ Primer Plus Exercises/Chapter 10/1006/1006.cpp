//
//  1006.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 04/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
#include "Move1006.hpp"

void show1006()
{
    std::cout << "Create a vector:\n";
    Move vec;
    vec.show();
    
    std::cout << "Update vector to (5, 4):\n";
    vec.reset(5, 4).show();
    
    std::cout << "Add (-3, 2) to the vector:\n";
    vec.add(Move(-3, 2)).show();    // use constructor for a temporary object
    
    std::cout << "Original vector remained unchanged:\n";
    vec.show();
    
    std::cout << "Create a new vector double the size of original:\n";
    Move newVec;                    // not using the copy-constructor as it hasn't been covered yet
    newVec = vec.add(vec);
    newVec.show();
    
    std::cout << "Reset the new vector:\n";
    newVec.reset().show();
    
    std::cout << "\nDone.\n";
}
