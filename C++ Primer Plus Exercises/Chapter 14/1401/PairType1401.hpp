//
//  PairType1401.hpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 26/06/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef PairType1401_h
#define PairType1401_h

namespace e1401
{
    template <typename TypeFirst, typename TypeSecond>
    class Pair
    {
    public:
        Pair() {}
        Pair (const TypeFirst& a, const TypeSecond& b) : mFirst (a), mSecond (b) {}
        
        TypeFirst&  first()  { return mFirst; }
        TypeSecond& second() { return mSecond; }
        TypeFirst   first()  const { return mFirst; }
        TypeSecond  second() const { return mSecond; }
        
    private:
        TypeFirst  mFirst;
        TypeSecond mSecond;
    };
}   // end namespace e1401

#endif /* PairType1401_h */
