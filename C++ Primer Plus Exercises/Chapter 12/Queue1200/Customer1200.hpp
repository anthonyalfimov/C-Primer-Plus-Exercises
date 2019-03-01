//
//  Customer1200.hpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 01/03/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef Customer1200_hpp
#define Customer1200_hpp

namespace e1200
{
    class Customer
    {
    public:
        Customer() : m_arrivalTime(0), m_processTime(0) {}  // Default constructor
        
        /**
         Sets customer arrival time to the passed value and randomly generates
         processing time in the range [1, 3]
         
         @param arrivalTime time at which the customer arrives
         */
        void set(long arrivalTime);
        
            //      Getters
        long getArrivalTime() const { return m_arrivalTime; }
        int  getProcessTime() const { return m_processTime; }
        
    private:
        long m_arrivalTime;       // arrival time for the customer
        int  m_processTime;       // processing time for the customer
    };
}   // end namespace e1200

#endif /* Customer1200_hpp */
