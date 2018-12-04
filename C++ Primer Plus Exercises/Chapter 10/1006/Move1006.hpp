//
//  Move1006.hpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 04/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#ifndef Move1006_hpp
#define Move1006_hpp

class Move
{
private:
    double m_X;
    double m_Y;
    
public:
    Move(double x = 0, double y = 0) { m_X = x; m_Y = y; }
    
    /**
     Show current x and y values
     */
    void show() const;
    
    /**
     Add x and y of invoking object to those of the passe object

     @param m Move object to add
     @return Resulting move object
     */
    Move add(const Move& m) const;
    
    /**
     Reset object's x and y to passed values
     */
    const Move& reset(double x = 0, double y = 0);
};

#endif /* Move1006_hpp */
