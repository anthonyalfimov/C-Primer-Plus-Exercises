//
//  ReadToVector01.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 28/09/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//
//
//==================================================================
// |                                                               |
// |  This program reads a text file containing lines of integers  |
// |  Each line contains a different number of integers (or none)  |
// |  Non-integer value terminate input; empty lines are ignored   |
// |  The program then reports back the read integers              |
// |                                                               |
//==================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

const char* filepath {"test.txt"};
constexpr int MaxLines {20};

void showReadToVector01()
{
//    Open file
    std::ifstream inFile;
    inFile.open(filepath);
    if (!inFile.is_open())
    {
        std::cout << "Error reading file " << filepath << "\n Program is terminating.\n";
        exit(EXIT_FAILURE);
    }
    
//    Read file
    std::vector<int> line[MaxLines];
    int value;
    int iter {};
    while (iter < MaxLines && (inFile >> value))
    {
        line[iter].push_back(value);
        if (inFile.get() == '\n') ++iter;
    }
    
//    Check how reading terminated
    if (inFile.eof())
        std::cout << "Reached end of file\n";
    else if (inFile.fail())
        std::cout << "Reading file terminated due to bad input\n";
    
//    Display read data
    int lineCount {iter};
    for (int i = 0; i < lineCount; ++i)
    {
        for (int num : line[i])     // range-based for loop
            std::cout << num << "\t";
        std::cout << "\n";
    }
}
