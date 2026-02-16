#pragma once

#include<bits/stdc++.h>
#include"../models/Songs.hpp"
#include"../device/IAudioOutputDevice.hpp"

using namespace std;

class AudioEngine {
    private:
        Song *currentSong;
        bool songIsPaused;
    public:
        AudioEngine(){
            currentSong = nullptr;
            songIsPaused = false;
        }

    string getCurrentSongTitle(){
        if(currentSong != nullptr){
            return currentSong->getTitle();
        }
        return "";
    }

    bool isPaused(){
        return songIsPaused;
    }

    void play(IAudioOutputDevice *aod, Song *song){
        if(song == nullptr){
            throw runtime_error("Cannot play a null song");
        };

        if(songIsPaused && song == currentSong){
            songIsPaused = false;
            cout << "Resuming song: " + song->getTitle() << endl;
            aod->playAudio(song);
            return;
        }

        currentSong = song;
        songIsPaused = false;
        cout << "Playing song: " << song->getTitle() << endl;
        aod->playAudio(song);        
    }

    void pause(){
        if(currentSong == nullptr){
            throw runtime_error("Cannot pause null song");
        }

        if(songIsPaused){
            throw runtime_error("Already paused");
        }

        songIsPaused = true;
        cout << "Pausing Song: " << currentSong->getTitle() << endl;
    }

};