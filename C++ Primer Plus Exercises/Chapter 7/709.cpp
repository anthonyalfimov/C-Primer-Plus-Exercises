//
//  709.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 11/10/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>

constexpr int SLEN {30};
struct Student
{
    char fullname[SLEN];
    char hobby[SLEN];
    int  oopLevel;
};

int getinfo(Student pa[], int size);

void display1(Student st);

void display2(const Student* pst);

void display3(const Student pa[], int size);

void show709()
{
    std::cout << "Enter class size: ";
    int classSize;
    std::cin >> classSize;
    while (std::cin.get() != '\n')
        continue;
    
    Student* ptr_stu {new Student[classSize]};
    int entries {getinfo(ptr_stu, classSize)};
    std::cout << "\nRead " << entries << " student entries.\n\n";
    for (int i = 0; i < entries; i++)
    {
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
        std::cout << "\n";
    }
    display3(ptr_stu, entries);
    
    delete [] ptr_stu;
    std::cout << "\nDone.\n";
}

int getinfo(Student pa[], int size)
{
    std::cout << "Enter information about students.\n"
                 "Leave the name field blank to terminate input.\n";
    
    int i;   // array iterator
    for (i = 0; i < size; i++)
    {
        std::cout << "Student #" << i + 1 << "\n";
        
        std::cout << "Full name: ";
        std::cin.getline(pa[i].fullname, SLEN);
        if (pa[i].fullname[0] == '\0')          // terminate on empty line
            break;
        
        std::cout << "Hobby: ";
        std::cin.getline(pa[i].hobby, SLEN);
        
        std::cout << "OOP Level: ";
        while (!(std::cin >> pa[i].oopLevel) || pa[i].oopLevel < 0)
        {
            std::cout << "Bad input, try again: ";
            if (!std::cin)                      // on bad input, clear the failbit
                std::cin.clear();
            while (std::cin.get() != '\n')      // clear input buffer in both cases
                continue;
        }
        while (std::cin.get() != '\n')          // clear input buffer after using `cin >>`
            continue;
    }
    
    return i;
}

void display1(Student st)
{
    std::cout
        << st.fullname << "\n"
        << "Hobby: " << st.hobby << "\n"
        << "OOP Level: " << st.oopLevel << "\n";
}

void display2(const Student* pst)
{
    std::cout
        << pst->fullname << "\n"
        << "Hobby: " << pst->hobby << "\n"
        << "OOP Level: " << pst->oopLevel << "\n";
}

void display3(const Student pa[], int n)
{
    for (int i = 0; i < n; i++)
    {
        display1(pa[i]);
        std::cout << "\n";
    }
}
