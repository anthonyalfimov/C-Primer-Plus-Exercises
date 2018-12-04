//
//  golf1003.hpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 04/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#ifndef golf1003_hpp
#define golf1003_hpp

class Golf
{
private:
//  Static constants
    static const int nameLength {40};
    
//  Data members
    char m_fullName[nameLength];
    int m_handicap;
    
//  Implementation methods
    void clearInputBuffer()                             // clear trailing input and '\n'
    { while (std::cin.get() != '\n') continue; }
    
public:
//  Constructors
    Golf(){ m_fullName[0] = '\0'; m_handicap = 0; }     // Default
    Golf(const char* fullName, int handicap = 0);
    
//  Methods
    
    /**
     Method solicits name and handicap from user
     and sets the data members to the values entered
     @return True if name is entered, false if name is empty string
     */
    bool set();
    
    /**
     Method resets handicap to new value
     
     @param newHandicap New handicap value
     @param isVerbose If true, log change to console
     @return Const reference to the object itself
     */
    const Golf& handicap(int newHandicap, bool isVerbose = false);
    
    /**
     Method displays contents of Golf object
     */
    void show() const;
};

#endif /* golf1003_hpp */
