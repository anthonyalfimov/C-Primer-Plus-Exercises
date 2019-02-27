//
//  Cow1201.hpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 27/02/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef Cow1201_hpp
#define Cow1201_hpp

namespace e1201
{
    class Cow
    {
    public:
        Cow();
        Cow(const char* name, const char* hobby, double weight);
        Cow(const Cow&);
        ~Cow();
        
        Cow& operator=(const Cow&);
        
        void show() const;
        
    private:
        static const int s_size = 20;
        
        char   m_name[s_size];
        char*  m_hobby;
        double m_weight;
    };
}   // end namespace e1201

#endif /* Cow1201_hpp */
