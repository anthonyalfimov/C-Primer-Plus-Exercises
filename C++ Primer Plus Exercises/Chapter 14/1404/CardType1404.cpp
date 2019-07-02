//
//  CardType1404.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 02/07/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "CardType1404.hpp"

namespace e1404
{
    const std::string Card::sSuitLabels[sSuitCount]
    {
        "Clubs", "Diamonds", "Hearts", "Spades"
    };
    const std::string Card::sFaceLabels[sFaceCount]
    {
        "Two", "Three", "Four", "Five", "Six", "Seven","Eight",
        "Nine", "Ten","Jack", "Queen", "King", "Ace"
    };
    
    Card::Card (int cardIndex)
    {
        if (cardIndex < 1 || cardIndex > 52)
            std::cout << "ERROR: card index out of bounds\n";
        else
        {
            --cardIndex;            // [1, 52] --> [0, 51]
            mFace = static_cast<Face> (cardIndex % sFaceCount);
            mSuit = static_cast<Suit> (cardIndex / sFaceCount);
        }
    }
    
    std::string Card::getCard() const
    {
        return sFaceLabels[static_cast<int> (mFace)] + " of " + sSuitLabels[static_cast<int> (mSuit)];
    }
    
    std::ostream& operator<<(std::ostream& os, const Card& card)
    {
        os << card.getCard();
        
        return os;
    }
}   // end namespace e1404
