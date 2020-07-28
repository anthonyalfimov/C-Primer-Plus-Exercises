//
//  TvType1501.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 28/07/2020.
//  Copyright © 2020 Anthony. All rights reserved.
//

#include <iostream>
#include "TvType1501.hpp"

namespace e1501
{
    bool Tv::volumeUp()
    {
        if (! isOn() || mVolume >= maxVolume)
            return false;
        
        ++mVolume;
        return true;
    }

    bool Tv::volumeDown()
    {
        if (! isOn() || mVolume <= minVolume)
            return false;
        
        --mVolume;
        return true;
    }

    void Tv::channelUp()
    {
        if (! isOn())
            toggleOnOff();      // changing channel turns the TV on
        
        if (mChannel < mMaxChannel)
            ++mChannel;
        else
            mChannel = 0;
    }

    void Tv::channelDown()
    {
        if (! isOn())
            toggleOnOff();      // changing channel turns the TV on
        
        if (mChannel > 0)
            --mChannel;
        else
            mChannel = mMaxChannel;
    }

    void Tv::toggleTuning()
    {
        if (! isOn())
            return;             // works only when TV is on
        
        mTuning = (mTuning == Tuning::cable) ? Tuning::antenna : Tuning::cable;
    }

    void Tv::toggleInput()
    {
        if (! isOn())
            return;             // works only when TV is on
        
        mInput = (mInput == Input::tv) ? Input::dvd : Input::tv;
    }

    void Tv::toggleInteractiveMode (Remote& r) const
    {
        if (! isOn())
            return;             // works only when TV is on
        
        r.mMode = (r.mMode == Remote::Mode::normal) ? Remote::Mode::interactive : Remote::Mode::normal;
    }
    
    void Tv::showSettings() const
    {
        std::cout << "TV is " << (isOn() ? "On" : "Off") << "\n";
        
        if (! isOn())
            return;
        
        std::cout
            << "Volume setting = " << mVolume << "\n"
            << "Channel setting = " << mChannel << "\n"
            << "Tuning set to " << (mTuning == Tuning::cable ? "Cable" : "Antenna") << "\n"
            << "Input set to " << (mInput == Input::tv ? "TV" : "DVD") << "\n";
    }

    void Remote::setChannel (Tv& t, int channel) const
    {
        if (! t.isOn())
            t.toggleOnOff();      // changing channel turns the TV on
        
        if (channel < 0 || channel > t.mMaxChannel)
            return;
        
        t.mChannel = channel;
    }
    
    void Remote::showMode() const
    {
        std::cout << "Remote is in " << (mMode == Mode::normal ? "Normal" : "Interactive") << " mode.\n";
    }
}

