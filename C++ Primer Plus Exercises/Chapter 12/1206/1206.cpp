//
//  1206.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 04/03/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include <cstdlib>                      // for rand() and srand()
#include <ctime>                        // for time()
#include <cmath>                        // for abs()
#include "Queue1200.hpp"

namespace
{
    const int    MinutesPerHour = 60;
    const int    MinSimHours = 100;     // minimum amount of simulation hours required
    const int    MaxTrials = 50;        // stop simmulation after this number exceeded
    const double InitDelta = 30.0;
    
    struct Stats                        // statistics of a single simulation run
    {
        long turnaways;                 // turned away by full queue
        long customers;                 // joined the queue
        long served;                    // served duting the simulation
        
        double lineCount;               // average line length
        double lineWait;                // average time in line
        
        void reset()                    // set all values to 0
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
    bool isNewCustomer(double rate);        // is there a new customer?
}

void show1206()
{
    using e1200::Queue;
    using e1200::Item;
    
    std::srand(static_cast<int>(std::time(nullptr)));       // seed the random number generator
    
    std::cout << "===| ATM Simulation |===\n"
    << "> Determine number of clients per hour that leads "
    << "to the target avarage wait time when using two ATMs\n\n";
    
    std::cout << "Enter the maximum size of the queues: ";
    int queueSize;
    std::cin >> queueSize;
    Queue lines[2]                          // create two Queue objects with max of queueSize items
    {
        {queueSize},
        {queueSize}
    };
    
    Queue line2(queueSize);
    
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
    
    std::cout << "Enter the desired precision: ";
    double precision;
    std::cin >> precision;
    
    // Variables for performing trials
    double delta = InitDelta;                   // arrival rate displacement
    double arrivalRate = delta;                 // number of customers arriving per hour
    int    trials = 0;                          // counter for number of trials
    int    waitTime[2];                         // temp storage for times until ATM (0, 1) are free
    Item   tmp;                                 // temp storage for enqueuing and dequeueing items
    Stats  resultStats;                         // output for statistics of the trial
    
    do
    {
        // Running the simulation
        if (trials > 0)                                 // update arrival rate
        {
            if (resultStats.lineWait < targetTime)      // if wait time is too long, decrease
                arrivalRate += delta;                   // - number of customers per hour
            else                                        // - otherwise increase it
                arrivalRate -= delta;
        }
        
        resultStats.reset();                            // reset trial statistics
        waitTime[0] = waitTime[1] = 0;                  // reset wait times
        
        for (int cycle = 0; cycle < cycleCount; cycle++)
        {
            // Handle new customers
            if (isNewCustomer(arrivalRate))
            {
                if (lines[0].isFull() && lines[1].isFull())
                    resultStats.turnaways++;
                else
                {
                    resultStats.customers++;
                    tmp.set(cycle);                     // cycle = time of arrival
                    
                    if (lines[0].count() < lines[1].count())
                        lines[0].enqueue(tmp);          // add new customer to the line 0
                    else
                        lines[1].enqueue(tmp);          // add new customer to the line 1
                }
            }
            
            // Handle processing clients in two lines
            for (int ln = 0; ln < 2; ln++)
            {
                if (waitTime[ln] <= 0 && ! lines[ln].isEmpty())
                {
                    lines[ln].dequeue(tmp);                 // attend next customer from the queue
                    waitTime[ln] = tmp.getProcessTime();    // get processing time for the customer
                    resultStats.served++;                   // count customer as served
                    resultStats.lineWait += cycle - tmp.getArrivalTime();
                                                            // accumulate time in line
                }
                
                // Handle waiting for processing
                if (waitTime[ln] > 0)
                    waitTime[ln]--;
                
                // Update average line length calculation
                resultStats.lineCount += lines[ln].count();
            }
        }
        
        for (int ln = 0; ln < 2; ln++)
            while (! lines[ln].isEmpty())                   // empty leftover items from the queues
                lines[ln].dequeue(tmp);
        
        resultStats.lineWait /= resultStats.served;         // calculate average wait time
        delta /= 2.0;           // set next arrival rate displacement to half of the previous one
        trials++;
        
        if (trials > MaxTrials)
            break;
        
    } while (std::abs(resultStats.lineWait - targetTime) > precision);
    
    // Reporing the results
    if (trials <= MaxTrials)
    {
        resultStats.lineCount = resultStats.lineCount / cycleCount / 2;
                                                            // calculate average line length
        
        // Output format for floating point values
        std::cout.precision(2);
        std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
        std::cout << "\nWith " << arrivalRate << " customers per hour the average wait time of "
                  << resultStats.lineWait << " minutes was achieved [after "
                  << trials << " trials]\n";
        
        std::cout
            << "\n"
            << "Customers accepted: " << resultStats.customers << "\n"
            << "  Customers served: " << resultStats.served << "\n"
            << "         Turnaways: " << resultStats.turnaways << "\n"
            << "Average queue size: " << resultStats.lineCount << "\n";
    }
    else
        std::cout << "\nSimulation exceeded maximum number of trials!\n";
    
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
