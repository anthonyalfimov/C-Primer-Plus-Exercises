//
//  MeanExcept1502.hpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 31/07/2020.
//  Copyright © 2020 Anthony. All rights reserved.
//

#ifndef MeanExcept1502_h
#define MeanExcept1502_h

#include <string>
#include <stdexcept>

namespace e1502
{
    class BadHarmonicMean : public std::logic_error
    {
    public:
        explicit BadHarmonicMean (const std::string& functionName)
            : std::logic_error ("> Error in " + functionName + ": invalid arguments for "
                                "harmonic mean calculation: a = -b\n") {}
    };

    class BadGeometricMean : public std::logic_error
    {
    public:
        explicit BadGeometricMean (const std::string& functionName)
            : std::logic_error ("> Error in " + functionName + ": invalid arguments for "
                                "geometric mean calculation: both arguments must be >= 0\n") {}
    };
}

#endif /* MeanExcept1502_h */
