//
//  1504.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 03/08/2020.
//  Copyright © 2020 Anthony. All rights reserved.
//

#include <iostream>
#include "Sales1504.hpp"

void show1504()
{
    using e1504::Sales;
    using e1504::LabeledSales;
    
    const int monthCount = 12;
    
    double monthlySales1[monthCount]
    {
        1220, 1100, 1122, 2212, 1232, 2334,
        2884, 2393, 3302, 2922, 3002, 3544
    };
    
    double monthlySales2[monthCount]
    {
        12, 11, 22, 21, 32, 34,
        28, 29, 33, 29, 32, 35
    };
    
    Sales sales1 (2011, monthlySales1, 12);
    LabeledSales sales2 (2012, "BlogStar", monthlySales2, 12);
    
    std::cout << "Begin try block 1\n\n";
    
    try
    {
        std::cout << "Year: " << sales1.getYear() << "\n";
        
        for (int i = 0; i < monthCount; ++i)
        {
            std::cout << sales1[i];
            
            if (i % 6 == 5)
                std::cout << "\n";
            else
                std::cout << " ";
        }
        
        std::cout << "\nYear: " << sales2.getYear() << "\n";
        std::cout << "Label: " << sales2.getLabel() << "\n";
        
        for (int i = 0; i < monthCount + 1; ++i)    // go out of bounds with the index
        {
            std::cout << sales2[i];
            
            if (i % 6 == 5)
                std::cout << "\n";
            else
                std::cout << " ";
        }
        
        std::cout << "\nEnd try block 1\n\n";
    }
    catch (Sales::BadIndex& exception)      // catching the base class reference only
    {
        std::cout << exception.what();
        
        LabeledSales::BadIndex* labeledException = dynamic_cast<LabeledSales::BadIndex*> (&exception);
        
        if (labeledException != nullptr)
            std::cout << "> Label: " << labeledException->getLabel() << "\n";
        
        std::cout << "> Bad index: " << exception.getBadIndexValue() << "\n";
    }
    
    std::cout << "\nBegin try block 2\n\n";
    
    try
    {
        sales2[2] = 37.5;
        sales1[20] = 23345;
        
        std::cout << "\nEnd try block 2\n\n";
    }
    catch (Sales::BadIndex& exception)      // catching the base class reference only
    {
        std::cout << exception.what();
        
        LabeledSales::BadIndex* labeledException = dynamic_cast<LabeledSales::BadIndex*> (&exception);
        
        if (labeledException != nullptr)
            std::cout << "> Label: " << labeledException->getLabel() << "\n";
        
        std::cout << "> Bad index: " << exception.getBadIndexValue() << "\n";
    }
    
    std::cout << "\nDone.\n";
}
