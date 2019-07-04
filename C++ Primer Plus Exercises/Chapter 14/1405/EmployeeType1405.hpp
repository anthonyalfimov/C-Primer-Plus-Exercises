//
//  EmployeeType1405.hpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 04/07/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef EmployeeType1405_hpp
#define EmployeeType1405_hpp

#include <iostream>
#include <string>

namespace e1405
{
    class AbstractEmployee
    {
    public:
        AbstractEmployee();
        AbstractEmployee (const std::string& firstName, const std::string& lastName,
                          const std::string& job);
        
        virtual ~AbstractEmployee() = 0;    // abstrast base class
        
        virtual void showAll() const;       // labels and shows all data
        virtual void setAll();              // prompts user input for all data
        
        friend std::ostream& operator<< (std::ostream& os, const AbstractEmployee& employee);
                                            // displays first and last name only
        
    private:
        std::string mFirstName;
        std::string mLastName;
        std::string mJob;
    };
    
    class Employee : public AbstractEmployee
    {
    public:
        Employee();
        Employee (const std::string& firstName, const std::string& lastName,
                  const std::string& job);
        
        void showAll() const override;
        void setAll() override;
    };
    
    class Manager : virtual public AbstractEmployee
    {
    public:
        Manager();
        Manager (const std::string& firstName, const std::string& lastName,
                 const std::string& job, int employeesManaged = 0);
        Manager (const AbstractEmployee& employee, int employeesManaged);
        Manager (const Manager& m);         // why do we need an explicit copy-ctor?
        
        void showAll() const override;
        void setAll() override;
        
    protected:
        int  getEmployeesManaged() const { return mEmployeesManaged; }   // output
        int& getEmployeesManaged() { return mEmployeesManaged; }         // input
        
    private:
        int mEmployeesManaged;              // number of employees managed
    };
    
    class Fink : virtual public AbstractEmployee
    {
    public:
        Fink();
        Fink (const std::string& firstName, const std::string& lastName,
              const std::string& job, const std::string& reportsTo);
        Fink (const AbstractEmployee& employee, const std::string& reportsTo);
        Fink (const Fink& f);
        
        void showAll() const override;
        void setAll() override;
        
    protected:
        const std::string& getReportsTo() const { return mReportsTo; }  // output
        std::string& getReportsTo() { return mReportsTo; }              // input
        
    private:
        std::string mReportsTo;             // to whom fink reports
    };
    
    class HighFink : public Manager, public Fink    // management fink
    {
    public:
        HighFink();
        HighFink (const std::string& firstName, const std::string& lastName,
                  const std::string& job, const std::string& reportsTo, int employeesManaged);
        HighFink (const AbstractEmployee& employee, const std::string& reportsTo,
                  int employeesManaged);
        HighFink (const Fink& f, int employeesManaged);
        HighFink (const Manager& m, const std::string& reportsTo);
        HighFink (const HighFink& h);
        
        void showAll() const override;
        void setAll() override;
    };
}   // end namespace e1405

#endif /* EmployeeType1405_hpp */
