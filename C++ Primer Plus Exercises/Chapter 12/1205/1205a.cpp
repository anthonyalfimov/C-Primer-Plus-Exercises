//
//  1205a.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 01/03/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//
//  Solve the problem for customers per hour by stepping through possible integer values
//

#include <iostream>
#include <cstdlib>              // for rand() and srand()
#include <ctime>                // for time()
#include "Queue1200.hpp"

namespace
{
    const int        MinutesPerHour = 60;
    const int        MinSimHours = 100;             // minimum amount of simulation hours required
    constexpr double MaxArrivalRate = 60.0;         // threshold due to running 1 cycle per minute
    constexpr double ArrivalRateIncrement = 1.0;    // step size for number of customers per hour
    constexpr int    MaxTrials = MaxArrivalRate / ArrivalRateIncrement;
    
    struct Stats                    // statistics of a single simulation run
    {
        long turnaways;             // turned away by full queue
        long customers;             // joined the queue
        long served;                // served duting the simulation
        
        double lineCount;           // average line length
        double lineWait;            // average time in line
        
        void reset()                // set all values to 0
        {
            turnaways = 0;
            customers = 0;
            served    = 0;
            
            lineCount = 0.0;
            lineWait  = 0.0;
        }
    };
    
    /**
     Determines whether a new customer shows up on this cycle of the simulation
     
     @param rate cutomer per hour rate
     @return true if customer shows up this cycle, false otherwise
     */
    bool isNewCustomer(double rate);     // is there a new customer?
}

void show1205a()
{
    using e1200::Queue;
    using e1200::Item;
    
    std::srand(static_cast<int>(std::time(nullptr)));       // seed the random number generator
    
    std::cout << "===| ATM Simulation |===\n"
              << "> Determine number of clients per hour that leads "
              << "to the target avarage wait time\n\n";
    
    std::cout << "Enter the maximum size of the queue: ";
    int queueSize;
    std::cin >> queueSize;
    Queue line(queueSize);                  // create a Queue object with max of queueSize items
    
    std::cout << "Enter the number of simulated hours: ";
    int hours;
    std::cin >> hours;
    
    if (hours < MinSimHours)
    {
        std::cout << "WARNING: Insufficient simulation time requested. Using default value of "
                  << MinSimHours << " hours instead.\n";
        hours = MinSimHours;
    }
    
    long cycleCount = MinutesPerHour * hours;   // simulation runs at 1 cycle per minute
    
    std::cout << "Enter the target average wait time (minutes): ";
    double targetTime;
    std::cin >> targetTime;
    
    // Variables for performing trials
    double arrivalRate = ArrivalRateIncrement;  // number of customers arriving per hour
    int    trials;                              // counter for number of trials
    int    waitTime;                            // temp storage for time until ATM is free
    Item   tmp;                                 // temp storage for enqueuing and dequeueing items
    Stats  trialStats;                          // temp storage for statistics of current trial
    Stats  resultStats;                         // output for statistics of last succesful trial
    
    for (trials = 0; trials < MaxTrials; trials++)
    {
        // Running the simulation
        trialStats.reset();
        waitTime = 0;
        for (int cycle = 0; cycle < cycleCount; cycle++)
        {
            // Handle new customers
            if (isNewCustomer(arrivalRate))
            {
                if (line.isFull())
                    trialStats.turnaways++;
                else
                {
                    trialStats.customers++;
                    tmp.set(cycle);                         // cycle = time of arrival
                    line.enqueue(tmp);                      // add new customer to the line
                }
            }
            // Handle processing the clients
            if (waitTime <= 0 && ! line.isEmpty())
            {
                line.dequeue(tmp);                          // attend next customer from the queue
                waitTime = tmp.getProcessTime();            // get processing time for the customer
                trialStats.served++;                        // count customer as served
                trialStats.lineWait += cycle - tmp.getArrivalTime();
                                                            // accumulate time in line
            }
            // Handle waiting for processing
            if (waitTime > 0)
                waitTime--;
            // Update average line length calculation
            trialStats.lineCount += line.count();
        }
        
        trialStats.lineWait /= trialStats.served;           // calculate avarage wait time
        
        if (trialStats.lineWait > targetTime)               // break if target exceeded
            break;
        
        while (! line.isEmpty())                            // empty leftover items from the queue
            line.dequeue(tmp);
        
        arrivalRate += ArrivalRateIncrement;                // increase customer per hour rate
        resultStats = trialStats;                           // save stats from current trial
    }

    // Reporing the results
    if (trials > 0)
    {
        resultStats.lineCount /= cycleCount;                 // calculate average line length
        arrivalRate -= ArrivalRateIncrement;    // undo step that took wait time over threshold
        
        // Output format for floating point values
        std::cout.precision(2);
        std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
        std::cout << "\nWith " << arrivalRate << " customers per hour the average wait time of "
                  << resultStats.lineWait << " minutes was achieved [after "
                  << trials << " trials]\n";
        
        if (trials == MaxTrials)
            std::cout << "NOTE: maximum number of customers per hour allowed by the simulation "
                         "was reached.\n";
        
        std::cout
        << "\n"
        << "Customers accepted: " << resultStats.customers << "\n"
        << "  Customers served: " << resultStats.served << "\n"
        << "         Turnaways: " << resultStats.turnaways << "\n"
        << "Average queue size: " << resultStats.lineCount << "\n";
    }
    else
        std::cout << "\nSimulation failed to reach designated average wait time!\n";
    
    std::cout << "\nDone.\n";
}

namespace
{
    bool isNewCustomer(double rate)
    {
        double averageTime = MinutesPerHour / rate;     // average time between customer arrivals
        return (std::rand() * averageTime / RAND_MAX < 1.0);      // true one time in averageTime
    }
}
