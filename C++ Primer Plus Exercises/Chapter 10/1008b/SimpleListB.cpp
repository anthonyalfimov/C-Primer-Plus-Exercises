//
//  SimpleListB.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 05/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include "SimpleListB.hpp"

namespace e1008b
{
    List::~List()
    {
        Node* current {m_head};
        Node* next;
        
        while (current != nullptr)
        {
            next = current->ref;
            delete current;
            current = next;
        }
    }
    
    bool List::add(const Item& item)
    {
        // Allocate the new node to add to the end of the list
        Node* newNode = new Node {item, nullptr};
        
        if (isEmpty())
            m_head = newNode;               // if empty list, assing new node to head
        else
        {
            Node* tail = m_head;
            while (tail->ref != nullptr)    // step though nodes until you find the last one (tail)
                tail = tail->ref;
            tail->ref = newNode;            // set assign new node to tail's reference
        }
        return true;                        // comply with the interface (linked list is never full)
    }
    
    void List::process(void (*op)(Item&))
    {
        Node* n {m_head};                   // start from head
        while (n != nullptr)
        {
            op(n->data);                    // process current node
            n = n->ref;                     // advance to the next node
        }
    }
    
    Item* List::at(int index)
    {
        if (index < 0)
            return nullptr;
        
        Node* n {m_head};
        while (n != nullptr)
        {
            if (index == 0)                 // if index countdown reached 0, return the item
                return &n->data;
            index--;                        // count down the index
            n = n->ref;
        }
        return nullptr;
    }
}
