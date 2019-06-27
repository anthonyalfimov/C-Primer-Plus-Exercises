//
//  WorkerType1403.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 27/06/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "WorkerType1403.hpp"

namespace e1403
{
//  Worker methods
    
    // Protected methods
    void Worker::data() const
    {
        std::cout
            << "Name: " << mFullName << "\n"
            << "Employee ID: " << mId << "\n";
    }
    
    void Worker::get()
    {
        std::getline(std::cin, mFullName);
        
        std::cout << "Enter worker's ID: ";
        std::cin >> mId;
        
        while (std::cin.get() != '\n')
            continue;
    }
    
//  Waiter methods
    
    void Waiter::set()
    {
        std::cout << "Enter waiter's name: ";
        Worker::get();
        get();
    }
    
    void Waiter::show() const
    {
        std::cout << "Category: waiter\n";
        Worker::data();
        data();
    }
    
    // Protected methods
    void Waiter::data() const
    {
        std::cout << "Panache rating: " << mPanache << "\n";
    }
    
    void Waiter::get()
    {
        std::cout << "Enter waiter's panache rating: ";
        std::cin >> mPanache;
        
        while (std::cin.get() != '\n')
            continue;
    }
    
//  Singer methods
    
    const char* Singer::sVoiceLabels[] =
    {
        "other", "alto", "contralto", "soprano",
        "bass", "baritone", "tenor"
    };
    
    void Singer::set()
    {
        std::cout << "Enter singer's name: ";
        Worker::get();
        get();
    }
    
    void Singer::show() const
    {
        std::cout << "Category: singer\n";
        Worker::data();
        data();
    }
    
    // Protected methods
    void Singer::data() const
    {
        std::cout << "Vocal range: " << sVoiceLabels[static_cast<int>(mVoice)] << "\n";
    }
    
    void Singer::get()
    {
        std::cout << "Enter number for singer's vocal range:\n";
        int i;
        
        for (i = 0; i < sVoiceTypes; i++)
        {
            std::cout << i << ": " << sVoiceLabels[i] << " ";
            
            if (i % 4 == 3)
                std::cout << "\n";
        }
        
        if (i % 4 != 0)
            std::cout << "\n";
        
        int voiceInput;
        
        while (std::cin >> voiceInput && (voiceInput < 0 || voiceInput >= sVoiceTypes))
            std::cout << "Please enter a value between 0 and " << sVoiceTypes - 1 << "\n";
        
        mVoice = static_cast<VoiceType>(voiceInput);
        
        while (std::cin.get() != '\n')
            continue;
    }
    
//  SingingWaiter methods
    
    void SingingWaiter::set()
    {
        std::cout << "Enter singing waiter's name: ";
        Worker::get();
        get();
    }
    
    void SingingWaiter::show() const
    {
        std::cout << "Category: singing waiter\n";
        Worker::data();
        data();
    }
    
    // Protected methods
    void SingingWaiter::data() const
    {
        Singer::data();
        Waiter::data();
    }
    
    void SingingWaiter::get()
    {
        Singer::get();
        Waiter::get();
    }
}   // end namespace e1403
