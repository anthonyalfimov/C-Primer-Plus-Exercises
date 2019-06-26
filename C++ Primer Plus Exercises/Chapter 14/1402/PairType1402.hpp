//
//  PairType1402.h
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 26/06/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef PairType1402_h
#define PairType1402_h

namespace e1402
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
}   // end namespace e1402

#endif /* PairType1402_h */
