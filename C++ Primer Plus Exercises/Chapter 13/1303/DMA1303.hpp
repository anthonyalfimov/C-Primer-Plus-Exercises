//
//  DMA1303.hpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 15/04/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef DMA1303_hpp
#define DMA1303_hpp

#include <iostream>

namespace e1303
{
//  Abstract base class using DMA
    class AbstractDMA
    {
    public:
        AbstractDMA(const char* label = "null", int rating = 0);
        AbstractDMA(const AbstractDMA&);
        
        virtual ~AbstractDMA();
        
        AbstractDMA& operator=(const AbstractDMA&);
        
        virtual void view() const = 0;
        
//      General overload for any derived class:
        friend std::ostream& operator<<(std::ostream& os, const AbstractDMA& ad);
                                        
    protected:
        const char* getLabel() const { return m_label; }
        int getRating() const { return m_rating; }
        virtual const char* getType() const = 0;            // report name of the class
        
    private:
        char* m_label;
        int   m_rating;
    };
    
//  Basic derived class
    class BaseDMA : public AbstractDMA
    {
    public:
        BaseDMA(const char* label = "null", int rating = 0);
        
        virtual void view() const override;
        
//      Simple overload for BaseDMA:
        friend std::ostream& operator<<(std::ostream& os, const BaseDMA& bd);
        
    protected:
        virtual const char* getType() const override { return "BaseDMA"; }
    };
    
//  Derived class without DMA
    class LacksDMA : public AbstractDMA
    {
    public:
        LacksDMA(const char* label = "null", int rating = 0, const char* colour = "blank");
        
        virtual void view() const override;
        
//      Simple overload for LacksDMA:
        friend std::ostream& operator<<(std::ostream& os, const LacksDMA& ld);
        
    protected:
        virtual const char* getType() const override { return "LacksDMA"; }
        
    private:
        static const int c_lenght = 40;
        char m_colour[c_lenght];
    };
    
//  Derived class with DMA
    class HasDMA : public AbstractDMA
    {
    public:
        HasDMA(const char* label = "null", int rating = 0, const char* style = "none");
        HasDMA(const HasDMA&);
        
        virtual ~HasDMA();
        
        HasDMA& operator=(const HasDMA&);
        
        virtual void view() const override;
        
//      Simple overload for HasDMA:
        friend std::ostream& operator<<(std::ostream& os, const HasDMA& hd);
        
    protected:
        virtual const char* getType() const override { return "HasDMA"; }
        
    private:
        char* m_style;
    };
}   // end namespace e1303

#endif /* DMA1303_hpp */
