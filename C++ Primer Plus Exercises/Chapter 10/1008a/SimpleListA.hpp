//
//  SimpleListA.hpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 05/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//
//  A simple list implemented using an array
//

#ifndef SimpleListA_hpp
#define SimpleListA_hpp

namespace e1008a
{
//  Using typedef as class templates haven't been covered yet
    typedef int Item;
    
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
         @return False if list is already full, true otherwise
         */
        bool add(const Item& item);
        
        /**
         Determine whether list is empty

         @return True if list is empty, false otherwise
         */
        bool isEmpty() const;
        
        /**
         Determine whether list is full

         @return True if list is full, false otherwise
         */
        bool isFull() const;
        
        /**
         Visit every element of the list and perform operation defined by the passed
         function on it

         @param op Function defining the operation to perform on each list item
         */
        void process(void (*op)(Item&));
        
        /**
         Retrieve pointer to list item at given index

         @param index Index
         @return nullptr if index if out of bounds, pointer to item at index otherwise
         */
        Item* at(int index);
        
    private:
        static const int maxItems {5};
        
        Item m_list[maxItems];          // items are stored in an array
        int  m_end;                     // one-past-the-end index of the list
    };
}


#endif /* SimpleListA_hpp */
