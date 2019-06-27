//
//  WineType1402.hpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 26/06/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef WineType1402_hpp
#define WineType1402_hpp

#include <string>
#include <valarray>
#include "PairType1402.hpp"

namespace e1402
{
    class Wine : private std::string, private Pair<std::valarray<int>, std::valarray<int>>
    {
    public:
        Wine (const char* label, int yearCount, const int years[], const int bottles[]);
        Wine (const char* label, int yearCount);
        
        virtual ~Wine() {}
        
        const std::string& getLabel() const { return (const std::string&) *this; }
        int getBottlesTotal() const { return PairArrayInt::second().sum(); }
        
        void inputYearsAndBottles();
        void display() const;
        
    private:
        using ArrayInt = std::valarray<int>;
        using PairArrayInt = Pair<ArrayInt, ArrayInt>;
        
        int mYearCount = 0;
    };
}   // end namespace e1401

#endif /* WineType1402_hpp */
