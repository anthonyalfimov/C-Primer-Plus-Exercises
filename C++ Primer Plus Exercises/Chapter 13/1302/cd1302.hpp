//
//  cd1302.hpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 12/04/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef cd1302_hpp
#define cd1302_hpp

#define VERBOSE_CD

namespace e1302
{
    class CD                                    // represents a CD disk
    {
    public:
        CD(const char* performers, const char* label, int selections, double playtime);
        CD();
        CD(const CD&);
        virtual ~CD();
        
        CD& operator=(const CD&);
        virtual void report() const;            // report all CD data
        
    protected:
        const char* getLabel() const { return m_label; }
        
    private:
        char*  m_performers;
        char*  m_label;
        int    m_selections;                    // number of selections
        double m_playtime;                      // playing time in minutes
    };
}   // end namespace e1302

#endif /* cd1302_hpp */
