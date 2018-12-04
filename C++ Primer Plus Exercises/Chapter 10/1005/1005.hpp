//
//  1005.hpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 04/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#ifndef _005_hpp
#define _005_hpp

namespace e1005
{
    constexpr int nameLength {40};
    
    struct Customer
    {
        char fullName[nameLength];
        double payment;
    };
}

#endif /* _005_hpp */
