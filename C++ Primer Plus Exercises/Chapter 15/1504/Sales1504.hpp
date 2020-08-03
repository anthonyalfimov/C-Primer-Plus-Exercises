//
//  Sales1504.hpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 03/08/2020.
//  Copyright © 2020 Anthony. All rights reserved.
//

#ifndef Sales1504_hpp
#define Sales1504_hpp

#include <stdexcept>
#include <string>

namespace e1504
{
    class Sales
    {
    public:
        explicit Sales (int year);
        Sales (int year, const double* monthlySales, int numberOfMonths);
        virtual ~Sales() {}
        
        int getYear() const { return mYear; }
        
        virtual double operator[] (int index) const;
        virtual double& operator[] (int index);
        
        class BadIndex : public std::logic_error
        {
        public:
            explicit BadIndex (int badIndexValue,
                               const std::string& message = "> Index error in Sales object\n");
            virtual ~BadIndex() {}
            
            int getBadIndexValue() const { return mBadIndexValue; }
            
        private:
            const int mBadIndexValue;
        };
        
    protected:
        static const int maxMonths = 12;
        
    private:
        int mYear;
        double mMonthlySales[maxMonths];
        
    };

    class LabeledSales : public Sales
    {
    public:
        explicit LabeledSales (int year, const std::string& label = "none");
        LabeledSales (int year, const std::string& label, const double* monthlySales,
                      int numberOfMonths);
        virtual ~LabeledSales() {}
        
        const std::string& getLabel() const { return mLabel; }
        double operator[] (int index) const override;
        double& operator[] (int index) override;
        
        class BadIndex : public Sales::BadIndex
        {
        public:
            BadIndex (int badIndexValue, const std::string& label,
                      const std::string& message = "> Index error in LabeledSales object\n");
            virtual ~BadIndex() {}
            
            const std::string& getLabel() const { return mLabel; }
            
        private:
            const std::string mLabel;
        };
        
    private:
        std::string mLabel;
    };
}

#endif /* Sales1504_hpp */
