//
//  golf.hpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 16/11/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#ifndef golf_hpp
#define golf_hpp

namespace e901
{
    const int Len {40};
    struct Golf
    {
        char fullname[Len];
        int handicap;
    };
    
//  Function prototypes
    
    /**
     Non-interactive version:
        function sets Golf struct to provided name and handicap
        using values passed as args to the function
     @param name Full name
     @param handicap Handicap
     */
    void setGolf(Golf&, const char* name, int handicap);
    
    /**
     Interactive version:
        function solicits name and handicap from user
        and sets the members of passed struct to the values entered
     @return 1 if name is entered, 0 if name is empty string
     */
    int setGolf(Golf&);
    
    /**
     Function resets handicap to new value
     */
    void handicap(Golf&, int newHandicap);
    
    /**
     Function displays contents of Golf structure
     */
    void showGolf(const Golf&);
}

#endif /* golf_hpp */
