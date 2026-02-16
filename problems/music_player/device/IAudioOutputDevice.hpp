#pragma once
#include"../models/Songs.hpp"

class IAudioOutputDevice {
    public:
    virtual void playAudio(Song* song) = 0;
    virtual ~IAudioOutputDevice() {}
};