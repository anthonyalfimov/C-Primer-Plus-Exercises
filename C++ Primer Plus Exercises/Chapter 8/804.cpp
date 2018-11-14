//
//  804.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 30/10/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
#include <cstring>              // for strlen(), strcpy()

namespace
{
    struct stringy
    {
        char * str;             // pointer to a string
        unsigned long length;   // length of the string (not counting '\0')
    };
    
    void set(stringy& dst, const char * src);
    
    void show(const stringy& msg, int times = 1);
    void show(const char * msg, int times = 1);
}

//   =============================
//   |       Main function       |
//   =============================
void show804()
{
    stringy beany;
    char testing[] = "Reality is not what it used to be.";      // auto determine the array size
    
    set(beany, testing);    // first argument is a reference
    show(beany);            // print member string once
    show(beany, 2);         // print member string twice
    
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);          // print testing string once
    show(testing, 3);       // print testing string thrice
    show("Done");
    
    delete [] beany.str;
}

namespace
{
    void set(stringy& dst, const char * src)
    {
        dst.length = std::strlen(src);
        dst.str = new char [dst.length];
        std::strcpy(dst.str, src);
    }

    void show(const stringy& msg, int times)
    {
        for (; times > 0; times--)
            std::cout << msg.str << "\n";
        std::cout << "# ============================== #\n";
    }

    void show(const char * msg, int times)
    {
        for (; times > 0; times--)
            std::cout << msg << "\n";
        std::cout << "# ============================== #\n";
    }
}
