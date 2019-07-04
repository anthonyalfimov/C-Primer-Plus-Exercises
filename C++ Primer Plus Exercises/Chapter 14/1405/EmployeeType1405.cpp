//
//  EmployeeType1405.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 04/07/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include "EmployeeType1405.hpp"

namespace e1405
{
// AbstractEmployee methods

    AbstractEmployee::AbstractEmployee()
        : mFirstName ("John"), mLastName ("Doe"), mJob ("None") {}
    AbstractEmployee::AbstractEmployee (const std::string& firstName, const std::string& lastName,
                                        const std::string& job)
        : mFirstName (firstName), mLastName (lastName), mJob (job) {}
    
    AbstractEmployee::~AbstractEmployee() {}
    
    void AbstractEmployee::showAll() const
    {
        std::cout << "Name: " << *this << "\n"
                  << "Job: " << mJob << "\n";
    }
    
    void AbstractEmployee::setAll()
    {
        std::cout << "First name: ";
        std::getline (std::cin, mFirstName);
        std::cout << "Last name: ";
        std::getline (std::cin, mLastName);
        std::cout << "Job: ";
        std::getline (std::cin, mJob);
    }
    
    std::ostream& operator<< (std::ostream& os, const AbstractEmployee& employee)
    {
        os << employee.mFirstName << " " << employee.mLastName;
        return os;
    }

// Employee methods
    
    Employee::Employee()
        : AbstractEmployee() {}
    Employee::Employee (const std::string& firstName, const std::string& lastName,
                        const std::string& job)
        : AbstractEmployee (firstName, lastName, job) {}
    
    void Employee::showAll() const
    {
        AbstractEmployee::showAll();
        std::cout << "Status: None\n";
    }
    
    void Employee::setAll()
    {
        AbstractEmployee::setAll();
    }

    
// Manager methods
    
    Manager::Manager()
        : AbstractEmployee(), mEmployeesManaged (0) {}
    Manager::Manager (const std::string& firstName, const std::string& lastName,
                      const std::string& job, int employeesManaged)
        : AbstractEmployee (firstName, lastName, job), mEmployeesManaged (employeesManaged) {}
    Manager::Manager (const AbstractEmployee& e, int employeesManaged)
        : AbstractEmployee (e), mEmployeesManaged (employeesManaged) {}
    Manager::Manager (const Manager& m)
        : AbstractEmployee (m), mEmployeesManaged (m.mEmployeesManaged) {}
    
    void Manager::showAll() const
    {
        AbstractEmployee::showAll();
        std::cout << "Status: Manager\n"
                  << "Employees managed: " << mEmployeesManaged << "\n";
    }
    
    void Manager::setAll()
    {
        AbstractEmployee::setAll();
        std::cout << "Employees managed: ";
        std::cin >> mEmployeesManaged;
        
        while (std::cin.get() != '\n')
            continue;
    }
    
// Fink methods
    
    Fink::Fink()
        : AbstractEmployee(), mReportsTo ("None") {}
    Fink::Fink (const std::string& firstName, const std::string& lastName,
                const std::string& job, const std::string& reportsTo)
        : AbstractEmployee (firstName, lastName, job), mReportsTo (reportsTo) {}
    Fink::Fink (const AbstractEmployee& e, const std::string& reportsTo)
        : AbstractEmployee (e), mReportsTo (reportsTo) {}
    Fink::Fink (const Fink& f)
        : AbstractEmployee (f), mReportsTo (f.mReportsTo) {}
    
    void Fink::showAll() const
    {
        AbstractEmployee::showAll();
        std::cout << "Status: Fink\n"
                  << "Reports to: " << mReportsTo << "\n";
    }
    
    void Fink::setAll()
    {
        AbstractEmployee::setAll();
        std::cout << "Reports to: ";
        std::getline(std::cin, mReportsTo);
    }

// HighFink methods
    
    HighFink::HighFink()
        : AbstractEmployee(), Manager(), Fink() {}
    HighFink::HighFink (const std::string& firstName, const std::string& lastName,
                        const std::string& job, const std::string& reportsTo, int employeesManaged)
        : AbstractEmployee (firstName, lastName, job),
          Manager (firstName, lastName, job, employeesManaged),
          Fink (firstName, lastName, job, reportsTo) {}
    HighFink::HighFink (const AbstractEmployee& e, const std::string& reportsTo,
                        int employeesManaged)
        : AbstractEmployee (e), Manager (e, employeesManaged), Fink (e, reportsTo) {}
    HighFink::HighFink (const Fink& f, int employeesManaged)
        : AbstractEmployee(f), Manager(f, employeesManaged), Fink(f) {}
    HighFink::HighFink (const Manager& m, const std::string& reportsTo)
        : AbstractEmployee(m), Manager(m), Fink(m, reportsTo) {}
    HighFink::HighFink (const HighFink& h)
        : AbstractEmployee(h), Manager(h), Fink(h) {}
    
    void HighFink::showAll() const
    {
        AbstractEmployee::showAll();
        std::cout << "Status: Manager, Fink\n"
                  << "Employees managed: " << getEmployeesManaged() << "\n"
                  << "Reports to: " << getReportsTo() << "\n";
    }
    
    void HighFink::setAll()
    {
        AbstractEmployee::setAll();
        std::cout << "Employees managed: ";
        std::cin >> getEmployeesManaged();
        
        while (std::cin.get() != '\n')
            continue;
        
        std::cout << "Reports to: ";
        std::getline(std::cin, getReportsTo());
    }
}   // end namespace e1405
