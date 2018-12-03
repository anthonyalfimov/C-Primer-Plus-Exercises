//
//  BankAccount.hpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 03/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//
//  Implemented using C-style strings
//

#ifndef BankAccount_hpp
#define BankAccount_hpp

class Account
{
private:
    // Static constants
    static const int nameLength {40};
    static const int numberLength{20};
    
    // Data members
    char m_name[nameLength];        // Depositor's name
    char m_number[numberLength];    // Account number
    double m_balance;               // Account balance
    
public:
    // Constructor - Initialization is always required
    Account(const char* name, const char* accountNumber, double balance = 0.0);
    
    // Methods
    /**
     Print depostior's name, account number and balance to the console
     
     @param balanceOnly Flag to print only the balance
     */
    void print(bool balanceOnly = false) const;
    
    /**
     Deposit specified amount into the account

     @param amount Amount to be deposited
     */
    void deposit(double amount);
    
    /**
     Withdraw specified amount from the account

     @param amount Amount to be withdrawn
     @return Returns true is successful, false otherwise
     */
    bool withdraw(double amount);
    
};

#endif /* BankAccount_hpp */
