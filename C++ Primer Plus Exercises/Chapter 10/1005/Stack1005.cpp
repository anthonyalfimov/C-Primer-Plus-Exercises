//
//  Stack1005.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 04/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include "Stack1005.hpp"

namespace e1005
{
    Stack::Stack()
    {
        top = 0;
    }
    
    bool Stack::isEmpty() const
    {
        return top == 0;
    }
    
    bool Stack::isFull() const
    {
        return top == MAX;
    }
    
    bool Stack::push(const Item &item)
    {
        if (top < MAX)
        {
            items[top++] = item;
            return true;
        }
        else
            return false;
    }
    
    bool Stack::pop(Item &item)
    {
        if (top > 0)
        {
            item = items[--top];
            return true;
        }
        else
            return false;
    }

}
