//
//  1005.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 04/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
#include <cstdlib>          // support for exit()
#include "1005.hpp"         // Customer struct declaration
#include "Stack1005.hpp"    // Stack class declaration

namespace e1005
{
    // NOTE: this requires at least a '\n' to be left in the stream,
    //     otherwise it gets stuck in an endless loop. Don't use in case of EOF
    void clearInputBuffer() { while (std::cin.get() != '\n') continue; }
    
    /**
     Prompts user to input customer data and pushes it onto the passed stack

     @param s Customer stack
     */
    void addCustomer(Stack& s);
    
    /**
     Takes the next customer from the passed stack and returns the value
     of their payment

     @param s Customer stack
     @return Processed payment
     */
    double processCustomer(Stack& s);
}

void show1005()
{
    using namespace e1005;
    
    Stack custromers;           // Stack of customers to process
    double total {0};           // running total
    
    char choice;
    
    std::cout << "Please enter A to add a customer,\n"
                 "P to process a customer, or Q to quit.\n";
    while (std::cin >> choice && (choice = std::toupper(choice)) != 'Q')
    {
        clearInputBuffer();     // clear the rest of the input buffer
        
        switch (choice)
        {
            case 'A':
                if (custromers.isFull())
                    std::cout << "Stack is already full!\n";
                else
                    addCustomer(custromers);
                break;
                
            case 'P':
                if (custromers.isEmpty())
                    std::cout << "Stack is already empty!\n";
                else
                {
                    total += processCustomer(custromers);
                    std::cout << "Running total: $" << total << "\n";
                }
        }
        
        std::cout << "\nPlease enter A to add a customer,\n"
                     "P to process a customer, or Q to quit.\n";
    }
    
    std::cout << "\nTotal: $" << total << "\n";
}

namespace e1005
{
    void addCustomer(Stack& s)
    {
        Customer input;
        std::cout << "Full name: ";
        if (!std::cin.getline(input.fullName, nameLength))  // If the name didn't fit,
        {
            if (std::cin.eof()) exit(EXIT_FAILURE);         // Not dealing with EOF
            std::cin.clear();
            clearInputBuffer();                             // clear input leftovers
            std::cout << "Name is too long! Truncated to "
                      << nameLength - 1 << " characters.\n";
        }
        
        std::cout << "Payment: ";
        while (!(std::cin >> input.payment) || input.payment < 0)
        {
            if (std::cin.eof()) exit(EXIT_FAILURE);         // Not dealing with EOF
            std::cout << "Invalid input, try again\nPayment: ";
            std::cin.clear();                               // Reset failbit in case it was set
            clearInputBuffer();                             // clear input leftovers
        }
        clearInputBuffer();                                 // clear input leftovers
        
        s.push(input);
    }
    
    double processCustomer(Stack& s)
    {
        Customer output;
        s.pop(output);
        std::cout << "Processed customer: " << output.fullName << "\n";
        return output.payment;
    }
}
