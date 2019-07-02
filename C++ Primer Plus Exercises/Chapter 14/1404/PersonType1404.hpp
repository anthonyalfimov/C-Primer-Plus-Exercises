//
//  PersonType1404.hpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 02/07/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef PersonType1404_hpp
#define PersonType1404_hpp

#include <string>
#include "CardType1404.hpp"

namespace e1404
{
    class Person
    {
    public:
        Person()
            : mFirstName ("John"), mLastName ("Doe") {}
        Person (const std::string& firstName, const std::string& lastName)
            : mFirstName (firstName), mLastName (lastName) {}
        
        virtual ~Person() {}
        
        virtual void show() const;
        virtual void set();
        
    protected:
        virtual void getData() const;
        virtual void setData();
        
    private:
        std::string mFirstName;
        std::string mLastName;
    };
    
    class Gunslinger : virtual public Person
    {
    public:
        Gunslinger()
            : Person() {}
        Gunslinger (const std::string& firstName, const std::string& lastName, double drawTime = 1000.0, int gunNotches = 0)
            : Person (firstName, lastName), mDrawTime (drawTime), mGunNotches (gunNotches) {}
        Gunslinger (const Person& p, double drawTime = 1000.0, int gunNotches = 0)
            : Person (p), mDrawTime (drawTime), mGunNotches (gunNotches) {}
        
        void show() const override;
        void set() override;
        
        double draw() const { return mDrawTime; }
        
    protected:
        void getData() const override;
        void setData() override;
        
    private:
        double mDrawTime = 1000.0;
        int mGunNotches = 0;
    };
    
    class PokerPlayer : virtual public Person
    {
    public:
        PokerPlayer()
            : Person() { if (! isInitialised()) initialise(); }
        PokerPlayer (const std::string& firstName, const std::string& lastName)
            : Person (firstName, lastName) { if (! isInitialised()) initialise(); }
        
        void show() const override;
        
        Card draw() const;
    
    protected:
        static void initialise();           // rand() seeding
        static bool isInitialised() { return sIsInitialised; }
    
    private:
        static bool sIsInitialised;         // flag for whether rand() was seeded
    };
    
    class BadDude : public Gunslinger, public PokerPlayer
    {
    public:
        BadDude()
            : Person(), PokerPlayer(), Gunslinger() {}
        BadDude (const std::string& firstName, const std::string& lastName, double drawTime = 1000.0, int gunNotches = 0)
            : Person (firstName, lastName), PokerPlayer(), Gunslinger (firstName, lastName, drawTime, gunNotches) {}
        BadDude (const Person& p, double drawTime = 1000.0, int gunNotches = 0)
            : Person (p), PokerPlayer(), Gunslinger (p, drawTime, gunNotches) {}
        BadDude (const Gunslinger& gs)
            : Person(gs), PokerPlayer(), Gunslinger (gs) {}
        
        void show() const override;
        
        double gunDraw() const { return Gunslinger::draw(); }
        Card cardDraw() const { return PokerPlayer::draw(); }
    };
    
}   // end namespace e1404



#endif /* PersonType1404_hpp */
