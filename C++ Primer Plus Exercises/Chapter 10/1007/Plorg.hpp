//
//  Plorg.hpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 05/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#ifndef Plorg_hpp
#define Plorg_hpp

class Plorg
{
private:
    static const int nameLength {20};
    
    char m_name[nameLength];
    int  m_cIndex;
    
public:
    Plorg(const char* name = "Plorga");
    
    /**
     Update Plorg's contentment index to the supplied value

     @param cIndex New contentment index
     */
    void cUpdate(int cIndex, bool isVerbose = true);
    
    /**
     Report Plorgs name and contentment index
     */
    void report() const;
    
    /**
     Return pointer to the name string of the Plorg

     @return Pointer to the name string of the Plorg
     */
    const char* name() const { return m_name; };
};

#endif /* Plorg_hpp */
