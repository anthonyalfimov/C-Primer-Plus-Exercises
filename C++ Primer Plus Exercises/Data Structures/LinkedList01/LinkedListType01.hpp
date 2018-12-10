//
//  LinkedListType01.hpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 05/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#ifndef LinkedListType01_hpp
#define LinkedListType01_hpp

#include <cstddef>          // for std::size_t
                            //     use as an index type because no index can overflow it
                            //     as it can hold size of any object possible
                            //     hence, even indices of maximum-size array of a 1-byte type
                            //     will not overflow it

namespace LinkedList01
{
    //  Using typedef as class templates haven't been covered yet
    typedef int Item;
    
    struct Node
    {
        Item data;
        Node* ref;
    };
    
    class List
    {
    public:
        //  Constructors and destructors
        List();         // Create an empty list
        ~List();
        
        //  Methods
        
        /**
         Add a new item to the end of the list
         
         @param item Item to add to the list
         */
        void add(const Item& item);
        
        /**
         Determine whether list is empty
         
         @return True if list is empty, false otherwise
         */
        bool isEmpty() const;
        
        /**
         Visit every element of the list and perform operation defined by the passed
         function on it
         
         @param op Function defining the operation to perform on each list item
         */
        void process(void (*op)(Item&));
        
        /**
         Retrieve pointer to list item at given index
         
         @param index Item index
         @return nullptr if index if out of bounds, pointer to item at index otherwise
         */
        Item* at(std::size_t index);
        
        /**
         Inserts a new list item after an item with supplied index
         
         @param index Index of item to insert after
         @param item New item
         @return False if insertion is impossible, true otherwise
         */
        bool insertAfter(std::size_t index, const Item& item);
        
    private:
        // Basic linked list with only head pointer stored
        Node* m_head;
        
        /**
         Returns the pointer to a node at a given index
         
         @param index Node index
         @return nullptr if index if out of bounds, pointer to node at index otherwis
         */
        Node* nodeAt(std::size_t index);
    };
    
    // Keep inline implementations out of the interface for clarity
    inline List::List() { m_head = nullptr; }
    inline bool List::isEmpty() const { return m_head == nullptr; }
}

#endif /* LinkedListType01_hpp */
