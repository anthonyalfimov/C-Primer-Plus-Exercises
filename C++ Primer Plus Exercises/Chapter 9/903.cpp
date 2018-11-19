//
//  903.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 19/11/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
#include <cstring>

namespace
{
    constexpr int stringSize {20};
    constexpr int structCount {2};
    
    struct Chaff
    {
        char dross[stringSize];
        int slag;
    };
    
    // Amount of bytes needed to store required amount of Chaff structs:
    constexpr int bufferSize {structCount * sizeof(Chaff)};
    // NOTE: sizeof is a compile-time operator, so if an executable compiled on one platform
    //    is run on another platform this code can lead to issues (if filetype sizes are different).
    //    Better use a buffer size based on the maximum possible struct size?
    
//  Function prototype
    void showChaff(const Chaff&);
}

void show903()
{
    char* buffer = new char[bufferSize];        // Dynamically allocate buffer
    
    Chaff* pc = new (buffer) Chaff[structCount];
    
    std::strcpy(pc[0].dross, "I am in a buffer");
    pc[0].slag = 5;
    
    std::strcpy(pc[1].dross, "Hello");
    pc[1].slag = -5;
    
    for (int i = 0; i < structCount; i++)
        showChaff(pc[i]);
    
    delete [] buffer;                           // Deallocate buffer
}

namespace
{
    void showChaff(const Chaff& c)
    {
        std::cout
            << c.dross << "\n"
            << c.slag  << "\n";
    }
}
