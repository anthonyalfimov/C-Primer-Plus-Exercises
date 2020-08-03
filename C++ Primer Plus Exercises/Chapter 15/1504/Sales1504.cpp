//
//  Sales1504.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 03/08/2020.
//  Copyright © 2020 Anthony. All rights reserved.
//

#include "Sales1504.hpp"

namespace e1504
{
    Sales::Sales (int year) : mYear(year)
    {
        for (int i = 0; i < maxMonths; ++i)
            mMonthlySales[i] = 0.0;
    }

    Sales::Sales (int year, const double* monthlySales, int numberOfMonths) : mYear(year)
    {
        int monthLimit = numberOfMonths < maxMonths ? numberOfMonths : maxMonths;
        int month = 0;
        
        for (; month < monthLimit; ++month)
            mMonthlySales[month] = monthlySales[month];
        
        for (; month < maxMonths; ++month)
            mMonthlySales[month] = 0.0;
    }
    
    double Sales::operator[] (int i) const
    {
        if (i < 0 || i >= maxMonths)
            throw Sales::BadIndex(i);
        
        return mMonthlySales[i];
    }

    double& Sales::operator[] (int i)
    {
        if (i < 0 || i >= maxMonths)
            throw Sales::BadIndex(i);
        
        return mMonthlySales[i];
    }
    
    Sales::BadIndex::BadIndex (int badIndexValue, const std::string& message)
        : std::logic_error(message), mBadIndexValue(badIndexValue)
    {
    }
        
    LabeledSales::LabeledSales (int year, const std::string& label) : Sales(year), mLabel(label)
    {
    }

    LabeledSales::LabeledSales (int year, const std::string& label, const double* monthlySales,
                                int numberOfMonths)
        : Sales(year, monthlySales, numberOfMonths), mLabel(label)
    {
    }
    
    double LabeledSales::operator[] (int i) const
    {
        if (i < 0 || i >= maxMonths)     // check bounds again to throw appropriate exception
            throw LabeledSales::BadIndex (i, mLabel);
        
        return Sales::operator[] (i);
    }

    double& LabeledSales::operator[] (int i)
    {
        if (i < 0 || i >= maxMonths)     // check bounds again to throw appropriate exception
            throw LabeledSales::BadIndex (i, mLabel);
        
        return Sales::operator[] (i);
    }
    
    LabeledSales::BadIndex::BadIndex (int badIndexValue, const std::string& label,
                                      const std::string& message)
        : Sales::BadIndex(badIndexValue, message), mLabel(label)
    {
    }
}
