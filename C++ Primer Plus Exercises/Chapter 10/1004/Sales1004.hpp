//
//  Sales1004.hpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 04/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#ifndef Sales1004_hpp
#define Sales1004_hpp

#include <iostream>

namespace SALES
{
    class Sales
    {
    private:
//      Constants:
        static const int quaters {4};
        
//      Data members:
        double m_sales[quaters];
        double m_average;
        double m_max;
        double m_min;
        
//      Implementation methods:
        /**
         Updates average, minimum and maximum sales and marks unused entries
         as invalid

         @param entries Number of first sales entries to use for update
         */
        void update(int entries = quaters);
        
        /**
         Clear trailing input and '\n'
         */
        void clearInputBuffer() { while (std::cin.get() != '\n') continue; }
        
    public:
//      Constructors:
        Sales() { update(0); }                  // initialize to no valid entries
        Sales(const double data[], int size);
        
//      Methods:
        
        /**
         Gathers sales for 4 quarters interactively, stores them
         in the sales member and computes and stores the
         average, maximum, and minimum values
         */
        void set();
        
        /**
         Display all information in Sales object
         */
        void show() const;
    };
}

#endif /* Sales1004_hpp */
