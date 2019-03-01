//
//  Queue1200.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 01/03/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include "Queue1200.hpp"

namespace e1200
{
    Queue::Queue(int size) : m_size(size), m_head(nullptr), m_tail(nullptr), m_count(0)
    {
    }
    
    Queue::~Queue()
    {
        Node* current;
        while (m_head != nullptr)
        {
            current = m_head;                   // save current node address
            m_head = m_head->ref;               // point head to the next node
            delete current;                     // delete current node
        }
    }
    
    bool Queue::enqueue(const Item& item)
    {
        if (isFull())
            return false;
        
        Node* add = new Node {item, nullptr};   // use list initialisation for the struct
        
        if (isEmpty())                          // is queue is empty
            m_head = add;                       // - place item in head
        else
            m_tail->ref = add;                  // - else place at the tail
        
        m_tail = add;                           // save new tail node
        m_count++;                              // increment number of items in the queue
        
        return true;
    }
    
    bool Queue::dequeue(Item& item)
    {
        if (isEmpty())
            return false;
        
        item = m_head->data;                    // return the data from the head node
        
        Node* first = m_head;                   // save location of the first item
        m_head = m_head->ref;                   // reset head to the next node
        delete first;                           // deallocate former first item
        
        m_count--;                              // decrement number of items in the queue
        if (isEmpty())                          // if deleted last item, set tail to null
            m_tail = nullptr;
        
        return true;
    }
}
