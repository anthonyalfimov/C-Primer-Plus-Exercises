//
//  1403.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 27/06/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "QueueType1403.hpp"
#include "WorkerType1403.hpp"

constexpr int size = 5;

void show1403()
{
    using namespace e1403;
    
    Queue<Worker*> staff (size);             // create queue of Worker ptrs
    
    while (! staff.isFull())
    {
        std::cout << "Enter the employee category:\n"
                  << "w: waiter   s: singer   t: singing waiter   q: quit\n";
        
        char choice;
        std::cin >> choice;
        
        while (std::strchr ("wstq", choice) == nullptr)
        {
            std::cout << "Please enter \"w\", \"s\", \"t\" or \"q\": ";
            std::cin >> choice;
        }
        
        while (std::cin.get() != '\n')
            continue;
        
        if (choice == 'q')
        {
            std::cout << "\n";
            break;
        }
        
        Worker* addWorker;
        
        switch (choice)
        {
            case 'w':   addWorker = new Waiter;
                break;
            case 's':   addWorker = new Singer;
                break;
            default:    addWorker = new SingingWaiter;
        }

        addWorker->set();
        staff.enqueue (addWorker);
        std::cout << "\n";
    }
    
    if (staff.count() > 0)
        std::cout << "Here is your staff:\n";
    else
        std::cout << "You have no staff!\n";
    
    while (! staff.isEmpty())
    {
        std::cout << "\n";
        Worker* getWorker;
        staff.dequeue(getWorker);
        getWorker->show();
        delete getWorker;
    }
    
    std::cout << "\nDone.\n";
}
