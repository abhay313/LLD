#pragma once

#include"../models/Songs.hpp"
#include"IAudioOutputDevice.hpp"
#include"../external/HeadPhoneAPI.hpp"
 
class HeadPhoneAdapter: public IAudioOutputDevice {
    private:
        HeadPhoneAPI *headphonehAPI;
    public:
        HeadPhoneAdapter(HeadPhoneAPI *api){
            headphonehAPI = api;
        }

        void playAudio(Song *song) override {
            string payload = song->getTitle() + " by " + song->getArtist();
            headphonehAPI->playSoundViaJack(payload);
        }
};