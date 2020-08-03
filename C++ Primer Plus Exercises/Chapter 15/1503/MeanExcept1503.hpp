//
//  MeanExcept1503.hpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 03/08/2020.
//  Copyright © 2020 Anthony. All rights reserved.
//

#ifndef MeanExcept1503_h
#define MeanExcept1503_h

#include <string>
#include <stdexcept>

namespace e1503
{
    class BadMean : public std::logic_error
    {
    public:
        BadMean (double arg1, double arg2, const std::string& functionName)
            : std::logic_error ("Erron in " + functionName + ": invalid arguments for mean calculation"),
              mArgument1 (arg1), mArgument2 (arg2) {}
        
        virtual void report() const = 0;
        
    protected:
        const double mArgument1;
        const double mArgument2;
    };

    class BadHarmonicMean : public BadMean
    {
    public:
        BadHarmonicMean (double arg1, double arg2, const std::string& functionName)
            : BadMean (arg1, arg2, functionName) {}
        
        void report() const override;
    };

    class BadGeometricMean : public BadMean
    {
    public:
        BadGeometricMean (double arg1, double arg2, const std::string& functionName)
            : BadMean (arg1, arg2, functionName) {}
        
        void report() const override;
    };
}

#endif /* MeanExcept1503_h */
