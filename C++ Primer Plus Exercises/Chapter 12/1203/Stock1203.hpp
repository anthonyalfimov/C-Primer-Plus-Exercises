//
//  Stock1203.hpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 27/02/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef Stock1203_hpp
#define Stock1203_hpp

#define VERBOSE_STOCK_

#include <iostream>

namespace e1203
{
    class Stock
    {
    public:
        Stock();
        Stock(const char* name, long num = 0, double price = 0.0);
        ~Stock();
        
    //  Methods
        /**
         Buy more shares of the same stock
         
         @param num Number of shares
         @param price Value of each share
         */
        void buy(long num, double price);
        
        /**
         Sell stock
         
         @param num Number of shares
         @param price Value of each share
         */
        void sell(long num, double price);
        
        /**
         Update the per-share value of stock
         
         @param price Value of each share
         */
        void update(double price);
        
        /**
         Return reference to the stock holding entry with the largest total value
         out of the object itself and the passed object
         
         @param other Stock holding to compare with
         @return Reference to stock holding with highest total value
         */
        const Stock& topValue(const Stock& other) const;
        
    //  Operator overloads
        friend std::ostream& operator<<(std::ostream& os, const Stock& st);
        
    private:
        char*  m_name;
        long   m_shares;
        double m_shareValue;
        double m_totalValue;
        
        constexpr static const char* const s_defaultName = "no name";
    
        void setTotal() { m_totalValue = m_shares * m_shareValue; }
        
        // Disable copy initialisation and assignment using private dummy member functions:
        Stock(const Stock& st) {}
        Stock& operator=(const Stock& st) { return *this; }
    };
}   // end namespace e1203

#endif /* Stock1203_hpp */
