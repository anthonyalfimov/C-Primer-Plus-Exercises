//
//  1501.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 28/07/2020.
//  Copyright © 2020 Anthony. All rights reserved.
//

#include <iostream>
#include "TvType1501.hpp"

void show1501()
{
    using e1501::Tv;
    using e1501::Remote;
    
    Tv alpha;
    
    std::cout << "Initial settings of TV Alpha:\n";
    alpha.showSettings();
    std::cout << "\n";
    
    Remote blackRemote;
    std::cout << "Initial state of the remote:\n";
    blackRemote.showMode();
    std::cout << "\n";
    
    blackRemote.setChannel(alpha, 100);         // turn the TV on by entering a channel
    alpha.toggleTuning();
    blackRemote.volumeUp(alpha);
    std::cout << "Adjusted settings of TV Alpha:\n";
    alpha.showSettings();
    std::cout << "\n";
    
    std::cout << "Demonstate that interactive mode can be toggled only when TV is on:\n";
    alpha.toggleInteractiveMode(blackRemote);
    blackRemote.showMode();
    blackRemote.toggleOnOff(alpha);
    alpha.showSettings();
    alpha.toggleInteractiveMode(blackRemote);
    blackRemote.showMode();
    std::cout << "\n";
    
    std::cout << "Turn the TV Alpha back on, change some settings and disable interactive mode:\n";
    blackRemote.toggleOnOff(alpha);
    blackRemote.toggleInput(alpha);
    alpha.toggleInteractiveMode(blackRemote);
    alpha.volumeDown();
    
    alpha.showSettings();
    blackRemote.showMode();
    
    std::cout << "\n";
    
    alpha.toggleOnOff();        // turn the TV off when you're done
    alpha.showSettings();
}

