//
//  WineType1401.hpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 26/06/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef WineType1401_h
#define WineType1401_h

#include <string>
#include <valarray>
#include "PairType1401.hpp"

namespace e1401
{
    class Wine
    {
    public:
        Wine (const char* label, int yearCount, const int years[], const int bottles[]);
        Wine (const char* label, int yearCount);
        
        virtual ~Wine() {};
        
        const std::string& getLabel() const { return mLabel; }
        int getBottlesTotal() const { return mYearsAndBottles.second().sum(); }
        
        void inputYearsAndBottles();
        void display() const;
        
    private:
        using ArrayInt = std::valarray<int>;
        using PairArrayInt = Pair<ArrayInt, ArrayInt>;
        
        std::string mLabel;
        PairArrayInt mYearsAndBottles;
        int mYearCount = 0;
    };
}   // end namespace e1401

#endif /* WineType1401_h */
