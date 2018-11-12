//
//  703.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 10/10/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>

constexpr int markerLength {40};

namespace e703
{
    struct Box
    {
        char marker[markerLength];
        float height;
        float width;
        float length;
        float volume;
    };
    
//  Function prototypes
    void setBoxVolume(Box*);
    void displayBox(Box);
}

using namespace e703;

void show703()
{
    Box package
    {
        "Package",      // marker
        5, 10, 10,      // H x W x L
        0               // volume
    };
    
    displayBox(package);
    setBoxVolume(&package);
    std::cout << "\n";
    displayBox(package);
    std::cout << "\nDone.\n";
}

void e703::setBoxVolume(Box* pb)
{
    pb->volume = pb->height * pb->width * pb->length;
}

void e703::displayBox(Box b)
{
    std::cout
        << "Box: " << b.marker << "\n"
        << "Dimensions: "
        << b.height << " x " << b.width << " x " << b.length << "\n"
        << "Volume: ";
    if (b.volume)
        std::cout << b.volume << "\n";
    else
        std::cout << "Not calculated.\n";
}
