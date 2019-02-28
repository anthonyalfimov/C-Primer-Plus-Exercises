//
//  Stack1204.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 28/02/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "Stack1204.hpp"

namespace e1204
{
    Stack::Stack(int size)
    {
        if (size < 1 || size > MAX)         // validate requested stack size
        {
            std::cout << "WARNING: Invalid size requested, created default stack instead\n";
            m_size = MAX;
        }
        else
            m_size = size;
        
        m_top = 0;
        m_items = new Item[m_size];
    }
    
    Stack::Stack(const Stack& st)
    {
        m_size = st.m_size;
        m_top  = st.m_top;
        m_items = new Item[m_size];
        
        for (int i = 0; i < m_top; i++)     // copy elements over
            m_items[i] = st.m_items[i];
    }
    
    Stack::~Stack()
    {
        delete [] m_items;
    }
    
    Stack& Stack::operator=(const Stack& st)
    {
        if (this == &st)                    // prevent self-copying
            return *this;
        
        m_size = st.m_size;
        m_top  = st.m_top;
        delete [] m_items;                  // deallocate previous stack storage
        m_items = new Item[m_size];         // allocate new stack storage
        
        for (int i = 0; i < m_top; i++)     // copy elements over
            m_items[i] = st.m_items[i];
        
        return *this;
    }

    bool Stack::push(const Item& item)
    {
        if (m_top < MAX)
        {
            m_items[m_top] = item;
            m_top++;
            return true;
        }
        
        return false;
    }
    
    bool Stack::pop(Item& item)
    {
        if (m_top > 0)
        {
            m_top--;
            item = m_items[m_top];
            return true;
        }
        
        return false;
    }
}
