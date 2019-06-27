//
//  QueueType1403.h
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 27/06/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef QueueType1403_h
#define QueueType1403_h

namespace e1403
{
    template <typename Type>
    class Queue
    {
    public:
        Queue (int size) : mSize (size) {}
        virtual ~Queue();
        
        // State checks
        bool isEmpty() const { return mCount == 0; }
        bool isFull()  const { return mCount == mSize; }
        int  count()   const { return mCount; }
        
        // Operations
        /**
         Add item to the end of the queue
         
         @param item item to be enqueued
         @return returns true if succesful, false if queue is full
         */
        bool enqueue(const Type& item);
        
        /**
         Remove item from the front of the queue
         
         @param item storage for the dequeued item
         @return returns true if succesful, false if queue is empty
         */
        bool dequeue(Type& item);
        
    private:
        struct Node                 // queue node
        {
            Type data;
            Node* reference;
        };
        
        Node* mHead = nullptr;      // pointer to the first element in the queue
        Node* mTail = nullptr;      // pointer to the last element in the queue
        int   mCount = 0;           // current number of elements in the queue
        const int mSize;            // maximum number of elements in the queue
    
        // Define non-copyable
        Queue (const Queue&) = delete;
        Queue& operator= (const Queue&) = delete;
        
    };
    
    template <typename Type>
    Queue<Type>::~Queue()
    {
        while (mHead != nullptr)
        {
            Node* oldHead = mHead;
            mHead = mHead->reference;
            delete oldHead;
        }
    }
    
    template <typename Type>
    bool Queue<Type>::enqueue(const Type& item)
    {
        if (isFull())
            return false;
        
        Node* add = new Node {item, nullptr};
        
        if (isEmpty())
            mHead = add;
        else
            mTail->reference = add;
        
        mTail = add;
        ++mCount;
        
        return true;
    }
    
    template <typename Type>
    bool Queue<Type>::dequeue(Type& item)
    {
        if (isEmpty())
            return false;
        
        item = mHead->data;
        Node* oldHead = mHead;
        mHead = mHead->reference;
        delete oldHead;
        --mCount;
        
        if (isEmpty())                      // if deleted last item, set tail to nullptr for safety
            mTail = nullptr;
        
        return true;
    }
    
}   // end namespace e1403

#endif /* QueueType1403_h */
