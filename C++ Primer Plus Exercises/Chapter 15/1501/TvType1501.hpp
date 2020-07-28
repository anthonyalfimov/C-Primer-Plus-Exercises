//
//  TvType1501.hpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 28/07/2020.
//  Copyright © 2020 Anthony. All rights reserved.
//

#ifndef TvType1501_hpp
#define TvType1501_hpp

namespace e1501
{
    class Remote;       // forward declaration for mutual friendship

    class Tv
    {
    public:
        enum class Power {off, on};
        enum class Tuning {antenna, cable};
        enum class Input {tv, dvd};
        
        static const int minVolume = 0;
        static const int maxVolume = 20;
        
        Tv (Power power = Power::off, int maxChannel = 125)
            : mPower (power), mTuning (Tuning::cable), mInput (Input::tv), mVolume (5),
              mMaxChannel (maxChannel), mChannel (1) {}
        
        void toggleOnOff() { mPower = (mPower == Power::on) ? Power::off : Power::on; }
        bool isOn() const { return mPower == Power::on; }
        bool volumeUp();
        bool volumeDown();
        void channelUp();
        void channelDown();
        void toggleTuning(); // { mTuning = (mTuning == Tuning::cable) ? Tuning::antenna : Tuning::cable; }
        void toggleInput();  // { mInput = (mInput == Input::tv) ? Input::dvd : Input::tv; }
        
        void toggleInteractiveMode (Remote&) const; // toggle interactive mode on the remote
        
        void showSettings() const;      // display all settings

        friend class Remote;
        
    private:
        Power mPower;
        Tuning mTuning;
        Input mInput;
        int mVolume;
        const int mMaxChannel;
        int mChannel;
    };

    class Remote
    {
    public:
        enum class Mode {normal, interactive};
        
        Remote () : mMode (Mode::normal) {}
        
        void toggleOnOff (Tv& t) const  { t.toggleOnOff(); }
        bool volumeUp (Tv& t) const     { return t.volumeUp(); }
        bool volumeDown (Tv& t) const   { return t.volumeDown(); }
        void channelUp (Tv& t) const    { t.channelUp(); }
        void channelDown (Tv& t) const  { t.channelDown(); }
        void toggleTuning (Tv& t) const { t.toggleTuning(); }
        void toggleInput (Tv& t) const  { t.toggleInput(); }
        void setChannel (Tv& t, int channel) const;
        
        void showMode() const;          // display remote mode: normal or interactive

        friend class Tv;
        
    private:
        Mode mMode;
    };
}



#endif /* TvType1501_hpp */
