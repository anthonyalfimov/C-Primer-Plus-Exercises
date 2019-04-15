//
//  DMA1303.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 15/04/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <cstring>
#include "DMA1303.hpp"

namespace e1303
{
//  AbstractDMA methods
    AbstractDMA::AbstractDMA(const char* label, int rating) : m_rating(rating)
    {
        m_label = new char[std::strlen(label) + 1];
        std::strcpy(m_label, label);
    }
    
    AbstractDMA::AbstractDMA(const AbstractDMA& ad) : m_rating(ad.m_rating)
    {
        m_label = new char[std::strlen(ad.m_label) + 1];
        std::strcpy(m_label, ad.m_label);
    }
    
    AbstractDMA::~AbstractDMA()
    {
        delete [] m_label;
    }
    
    AbstractDMA& AbstractDMA::operator=(const AbstractDMA& ad)
    {
        if (this == &ad)                // prevent self-copying
            return *this;
        
        delete [] m_label;              // delete old data
        m_label = new char[std::strlen(ad.m_label) + 1];
        std::strcpy(m_label, ad.m_label);
        m_rating = ad.m_rating;
        
        return *this;
    }
    
    std::ostream& operator<<(std::ostream& os, const AbstractDMA& ad)
    {
        os << ad.getType() << " object \"" << ad.m_label << "\"";   // can access m_label directly
        return os;
    }
    
//  BaseDMA methods
    BaseDMA::BaseDMA(const char* label, int rating) : AbstractDMA(label, rating) {}

    void BaseDMA::view() const
    {
        std::cout
            << "Type:   BaseDMA\n"
            << "Label:  " << getLabel() << "\n"
            << "Rating: " << getRating() << "\n";
    }
    
    std::ostream& operator<<(std::ostream& os, const BaseDMA& bd)
    {
        os << "BaseDMA object \"" << bd.getLabel() << "\"";         // can't access m_label directly
        return os;
    }
    
//  LacksDMA methods
    LacksDMA::LacksDMA(const char* label, int rating, const char* colour)
        : AbstractDMA(label, rating)
    {
        std::strncpy(m_colour, colour, c_lenght - 1);
        m_colour[c_lenght - 1] = '\0';
    }
    
    void LacksDMA::view() const
    {
        std::cout
            << "Type:   LacksDMA\n"
            << "Label:  " << getLabel() << "\n"
            << "Rating: " << getRating() << "\n"
            << "Colour: " << m_colour << "\n";
    }
    
    std::ostream& operator<<(std::ostream& os, const LacksDMA& ld)
    {
        os << "LacksDMA object \"" << ld.getLabel() << "\"";        // can't access m_label directly
        return os;
    }
    
//  HasDMA methods
    HasDMA::HasDMA(const char* label, int rating, const char* style) : AbstractDMA(label, rating)
    {
        m_style = new char[std::strlen(style) + 1];
        std::strcpy(m_style, style);
    }
    
    HasDMA::HasDMA(const HasDMA& hd) : AbstractDMA(hd)
    {
        m_style = new char[std::strlen(hd.m_style) + 1];
        std::strcpy(m_style, hd.m_style);
    }
    
    HasDMA::~HasDMA()
    {
        delete [] m_style;
    }
    
    HasDMA& HasDMA::operator=(const HasDMA& hd)
    {
        if (this == & hd)           // prevent self-copying
            return * this;
        
        AbstractDMA::operator=(hd); // call base-class assignment to assign base-class component
        
        delete [] m_style;          // delete old data
        m_style = new char[std::strlen(hd.m_style) + 1];
        std::strcpy(m_style, hd.m_style);
        
        return *this;
    }
    
    void HasDMA::view() const
    {
        std::cout
            << "Type:   HasDMA\n"
            << "Label:  " << getLabel() << "\n"
            << "Rating: " << getRating() << "\n"
            << "Style:  " << m_style << "\n";
    }
    
    std::ostream& operator<<(std::ostream& os, const HasDMA& hd)
    {
        os << "HasDMA object \"" << hd.getLabel() << "\"";          // can't access m_label directly
        return os;
    }
    
}   // end namespace e1303
