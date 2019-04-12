//
//  cd1301.hpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 12/04/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef cd1301_hpp
#define cd1301_hpp

namespace e1301
{
    class CD                                    // represents a CD disk
    {
    public:
        CD(const char* performers, const char* label, int selections, double playtime);
        CD();
        virtual ~CD() {};
        
        virtual void report() const;            // report all CD data
        
    private:
        static const int c_perfLength = 50;
        static const int c_labelLength = 20;
        
        char   m_performers[c_perfLength];
        char   m_label[c_labelLength];
        int    m_selections;                    // number of selections
        double m_playtime;                      // playing time in minutes
    };
}   // end namespace e1301

#endif /* cd1301_hpp */
