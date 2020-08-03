//
//  MeanExcept1503.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 03/08/2020.
//  Copyright © 2020 Anthony. All rights reserved.
//

#include <iostream>
#include "MeanExcept1503.hpp"

namespace e1503
{
    void BadHarmonicMean::report() const
    {
        std::cout
            << "> " << what() << "!\n"
            << "> Cannot compute the harmonic mean of " << mArgument1 << " and " << mArgument2 << "\n";
    }

    void BadGeometricMean::report() const
    {
        std::cout
            << "> " << what() << "!\n"
            << "> Cannot compute the geometric mean of " << mArgument1 << " and " << mArgument2 << "\n";
    }
}
