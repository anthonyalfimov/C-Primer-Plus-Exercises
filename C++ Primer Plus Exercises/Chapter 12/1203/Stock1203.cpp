//
//  Stock1203.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 27/02/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include <cstring>
#include "Stock1203.hpp"

namespace e1203
{
//  Constructors
    Stock::Stock()
    {
        int lenght = static_cast<int>(std::strlen(s_defaultName));
        m_name = new char[lenght + 1];
        std::strcpy(m_name, s_defaultName);
        m_shares     = 0;
        m_shareValue = 0.0;
        m_totalValue = 0.0;
        
    #ifdef VERBOSE_STOCK_
        std::cout << "> Empty stock object created\n";
    #endif
    }
    
    Stock::Stock(const char* name, long num, double price)
    {
        int length = static_cast<int>(std::strlen(name));
        m_name = new char[length + 1];
        std::strcpy(m_name, name);
        
        if (num < 0)
        {
            std::cout << "Number of shares can't be negative;"
                      << m_name << " shares set to 0.\n";
        }
        else
            m_shares = num;
        
        m_shareValue = price;
        setTotal();
        
    #ifdef VERBOSE_STOCK_
        std::cout << "> " << m_name << " stock object created\n";
    #endif
    }
    
//  Destructor
    Stock::~Stock()
    {
    #ifdef VERBOSE_STOCK_
        std::cout << "> " << m_name << " stock object being destroyed... ";
    #endif
        
        delete [] m_name;
        
    #ifdef VERBOSE_STOCK_
        std::cout << "Done\n";
    #endif
    }
    
//  Methods
    void Stock::buy(long num, double price)
    {
        if (num < 0)
            std::cout << "Number of shares purchased can't be negative. "
            "Transaction is aborted.\n";
        else
        {
            m_shares += num;
            m_shareValue = price;
            setTotal();
        }
    }
    
    void Stock::sell(long num, double price)
    {
        using std::cout;
        
        if (num < 0)
            cout << "Number of shares sold can't be negative. "
            "Transaction is aborted.\n";
        else if (num > m_shares)
            cout << "You can't sell more than you have! "
            "Transaction is aborted.\n";
        else
        {
            m_shares -= num;
            m_shareValue = price;
            setTotal();
        }
    }
    
    void Stock::update(double price)
    {
        m_shareValue = price;
        setTotal();
    }
    
    std::ostream& operator<<(std::ostream& os, const Stock& st)
    {
        using std::ios_base;
//      Set number output format to #.###
        
        // `setf` returns previous settings that are saved into `orig`
        // `floatfield` is a mask that applies changes only to float format flags
        ios_base::fmtflags orig = os.setf(ios_base::fixed, ios_base::floatfield);
        
        // `precision` returns previous setting that is saved into `orig`
        std::streamsize prec = os.precision(3);
        
        os << "Company: " << st.m_name
           << " | Shares: " << st.m_shares
           << " | Share Price: $" << st.m_shareValue;
        
//      Set number output format to #.##
        os.precision(2);
        os << " | Total Worth: $" << st.m_totalValue;
        
//      Restore formatting to pre-existing state:
        os.setf(orig, ios_base::floatfield);     // apply changes only to float format flags
        os.precision(prec);
        
        return os;
    }
    
    const Stock& Stock::topValue(const Stock& s) const
    {
        if (s.m_totalValue > m_totalValue)
            return s;

        return *this;           
    }
    
}
