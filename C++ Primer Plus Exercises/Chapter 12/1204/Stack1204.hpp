//
//  Stack1204.hpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 28/02/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef Stack1204_hpp
#define Stack1204_hpp

namespace e1204
{
    // Until class templates are covered, use typedef:
    typedef unsigned long Item;
    
    class Stack
    {
    public:
        Stack(int size = MAX);
        Stack(const Stack&);
        ~Stack();
        
        Stack& operator=(const Stack&);
        
        /**
         @return true if stack is empty, false otherwise
         */
        bool isEmpty() const { return m_top == 0; }
        
        /**
         @return true if stack is full, false otherwise
         */
        bool isFull()  const { return m_top == m_size; }
        
        /**
         Add item to the stack
         
         @param item Item to add to the stack
         @return false if stack is already full, true otherwise
         */
        bool push(const Item& item);
        
        /**
         Pop top of the stack into the passed item
         
         @param item Item to pop top of the stack into
         @return false if the stack is already empty, true otherwise
         */
        bool pop(Item& item);
        
    private:
        static const int MAX = 10;
        
        Item* m_items;              // pointer to stack items memory location
        int m_size;                 // number of elements stack can hold
        int m_top;                  // index for top stack item
    };
}   // end namespace e1204

#endif /* Stack1204_hpp */
