//
//  SimpleListA.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 05/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include "SimpleListA.hpp"

namespace e1008a
{
    List::List()
    {
        m_end = 0;
    }
    
    List::~List()
    {
    }
    
    bool List::add(const Item& item)
    {
        if (m_end < maxItems)
        {
            m_list[m_end] = item;
            m_end++;
            return true;
        }
        else
            return false;
    }
    
    bool List::isEmpty() const
    {
        return m_end == 0;
    }
    
    bool List::isFull() const
    {
        return m_end == maxItems;
    }
    
    void List::process(void (*op)(Item&))
    {
        for (int i = 0; i < m_end; i++)
            op(m_list[i]);
    }
    
    Item* List::at(int i)
    {
        if (i >= 0 && i < m_end)
            return &m_list[i];
        else
            return nullptr;
    }
}






