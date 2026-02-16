#pragma once

#include"../models/Songs.hpp"
#include"IAudioOutputDevice.hpp"
#include"../external/WiredSpeakerAPI.hpp"

class WiredSpeakerAdapter: public IAudioOutputDevice {
    private:
        WiredSpeakerAPI *wiredSpeakerAPI;
    public:
        WiredSpeakerAdapter(WiredSpeakerAPI *api){
            wiredSpeakerAPI = api;
        }

        void playAudio(Song *song) override {
            string payload = song->getTitle() + " by " + song->getArtist();
            wiredSpeakerAPI-> playSoundViaCable(payload);
        }
};