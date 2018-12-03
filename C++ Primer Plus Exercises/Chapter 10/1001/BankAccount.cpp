//
//  BankAccount.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 03/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <cstring>
#include "BankAccount.hpp"

Account::Account(const char *name, const char *number, double balance)
{
    std::strncpy(m_name, name, nameLength);
    m_name[nameLength - 1] = '\0';              // ensure null-termination
    
    std::strncpy(m_number, number, numberLength);
    m_number[numberLength - 1] = '\0';          // ensure null-termination
    
    m_balance = balance;
}


void Account::print(bool balanceOnly) const
{
    // Set float format to fixed point, save the original formatting
    std::ios_base::fmtflags originalFormat =
        std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    
    // Set float precision to 2 decimall point, save original precision
    std::streamsize originalPrecision = std::cout.precision(2);
    
    if (!balanceOnly)
        std::cout
            << "Depositor: " << m_name << "\n"
            << "Account number: " << m_number << "\n";
    
    std::cout
        << "Balance: $" << m_balance << "\n";
    
    // Restore original formatting
    std::cout.setf(originalFormat);
    // Restore orifinal precision
    std::cout.precision(originalPrecision);
}


void Account::deposit(double amount)
{
    m_balance += amount;
}


bool Account::withdraw(double amount)
{
    if (amount > m_balance)
        return false;
    else
    {
        m_balance -= amount;
        return true;
    }
}
