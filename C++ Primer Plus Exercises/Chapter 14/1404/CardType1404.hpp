//
//  CardType1404.hpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 02/07/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef CardType1404_hpp
#define CardType1404_hpp

#include <string>
#include <iostream>

namespace e1404
{
    class Card
    {
    public:
        enum class Suit {clubs = 0, diamonds, hearts, spades};
        enum class Face {two = 0, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace};
        
        Card() {}
        Card (Face f, Suit s) : mFace (f), mSuit (s) {}
        Card (int cardIndex);       // create Card object from a [1, 52] integer
        
        const std::string& getFace() const { return sFaceLabels[static_cast<int> (mFace)]; }
        const std::string& getSuit() const { return sSuitLabels[static_cast<int> (mSuit)]; }
        std::string getCard() const;
        
        friend std::ostream& operator<<(std::ostream& os, const Card& card);
        
        static int getFaceCount() { return sFaceCount; }
        static int getSuitCount() { return sSuitCount; }
        static int getTotalCount() { return sFaceCount * sSuitCount; }
        
    private:
        static const int sSuitCount = 4;
        static const int sFaceCount = 13;
        
        static const std::string sSuitLabels[sSuitCount];
        static const std::string sFaceLabels[sFaceCount];
        
        Face mFace = Face::two;
        Suit mSuit = Suit::clubs;
    };
}   // end namespace e1404

#endif /* CardType1404_hpp */
