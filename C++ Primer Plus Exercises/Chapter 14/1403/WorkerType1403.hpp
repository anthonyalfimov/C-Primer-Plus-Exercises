//
//  WorkerType1403.hpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 27/06/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef WorkerType1403_hpp
#define WorkerType1403_hpp

#include <string>

namespace e1403
{
    class Worker                        // abstract base class
    {
    public:
        Worker()
            : mFullName ("No one"), mId (0L) {}
        Worker (const std::string& fullName, long id)
            : mFullName (fullName), mId (id) {}
        
        virtual ~Worker() {}
        virtual void set() = 0;         // don't need to define these in modular approach
        virtual void show() const = 0;  //
        
    protected:
        virtual void data() const;      // helper functions for modular approach
        virtual void get();             //
        
    private:
        std::string mFullName;
        long mId;
    };
    
    class Waiter : virtual public Worker
    {
    public:
        Waiter()
            : Worker(), mPanache (0) {}
        Waiter (const std::string& fullName, long id, int panache = 0)
            : Worker (fullName, id), mPanache (panache) {}
        Waiter (const Worker& w, int panache = 0)
            : Worker (w), mPanache (panache) {}
        
        virtual void set() override;
        virtual void show() const override;
        
    protected:
        virtual void data() const override;
        virtual void get() override;
        
    private:
        int mPanache;
    };
    
    class Singer : virtual public Worker
    {
    public:
        enum class VoiceType {other = 0, alto, contralto, soprano, bass, baritone, tenor};
        
        Singer()
            : Worker(), mVoice (VoiceType::other) {}
        Singer(const std::string& fullName, long id, VoiceType voice = VoiceType::other)
            : Worker(fullName, id), mVoice(voice) {}
        Singer(const Worker& w, VoiceType voice = VoiceType::other)
            : Worker(w), mVoice(voice) {}
        
        virtual void set() override;
        virtual void show() const override;
        
    protected:
        static const int sVoiceTypes = 7;
        
        virtual void data() const override;
        virtual void get() override;
        
    private:
        static const char* sVoiceLabels[sVoiceTypes];     // string equivalents of voice types
        VoiceType mVoice;
        
    };
    
    // Multiple inheritance
    class SingingWaiter : public Singer, public Waiter
    {
    public:
        SingingWaiter() {}                  // default ctor - use all default ctors for base classes
        
        // Explicitely calling the virtual base class constructor
        // Base-class parameters for the immidiate parent constructors have to be provided,
        //     despite them not actually calling the virtual base class constructor
        SingingWaiter(const std::string& fullName, long id, int panache = 0, VoiceType voice = VoiceType::other)
            : Worker(fullName, id), Waiter(fullName, id, panache), Singer(fullName, id, voice) {}
        SingingWaiter(const Worker& w, int panache = 0, VoiceType voice = VoiceType::other)
            : Worker(w), Waiter(w, panache), Singer(w, voice) {}
        SingingWaiter(const Waiter& wt, VoiceType voice = VoiceType::other)
            : Worker(wt), Waiter(wt), Singer(wt, voice) {}
        SingingWaiter(const Singer& sn, int panache = 0)
            : Worker(sn), Waiter(sn, panache), Singer(sn) {}
        
        virtual void set() override;            // must override inherited virtual functions
        virtual void show() const override;     //     to avoid ambiguity due to both base classes
                                                //     having methods with the same name
    protected:
        virtual void data() const override;
        virtual void get() override;
    };
}   // end namespace e1403

#endif /* WorkerType1403_hpp */
