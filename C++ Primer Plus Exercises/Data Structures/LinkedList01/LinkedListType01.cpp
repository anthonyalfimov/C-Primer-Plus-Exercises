//
//  LinkedListType01.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 05/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
#include "LinkedListType01.hpp"

namespace LinkedList01
{
    // Verbose destructor
    List::~List()
    {
        std::cout << "Delete list items: ";
        
        Node* current {m_head};
        Node* next;
        
        while (current != nullptr)
        {
            next = current->ref;
            std::cout << current->data << " ";
            delete current;
            current = next;
        }
        std::cout << std::endl;
    }
    
    void List::add(const Item& item)
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
    
    Item* List::at(std::size_t index)
    {
        Node* n {nodeAt(index)};
        if (n == nullptr)
            return nullptr;
        else
            return &n->data;
    }
    
    bool List::insertAfter(std::size_t index, const Item& item)
    {
        Node* prev {nodeAt(index)};
        if (prev == nullptr)
            return false;
        
        Node* newItem = new Node {item, prev->ref};
        prev->ref = newItem;
        return true;
    }
    
    Node* List::nodeAt(std::size_t index)   // size_t is unsigned, so passing a negative index
    {                                       //    results in it being a very large number
        Node* n {m_head};
        while (n != nullptr)
        {
            if (index == 0)                 // if index countdown reached 0, return the item
                return n;
            index--;                        // count down the index
            n = n->ref;
        }
        return nullptr;
    }
}
