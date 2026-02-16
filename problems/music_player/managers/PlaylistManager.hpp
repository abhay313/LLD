#pragma once

#include<bits/stdc++.h>
#include"../models/Playlist.hpp"

using namespace std;

class PlaylistManager {
    private:
        static PlaylistManager* instance;
        map<string, Playlist*> playlists;
        PlaylistManager() {}
    public:
        static PlaylistManager* getInstance(){
            if(instance == nullptr){
                instance = new PlaylistManager();
            }
            return instance;
        }

        void createPlaylist(const string& name){
            if(playlists.count(name)){
                throw runtime_error("Playlist: " + name + " already exist");
            }
            playlists[name] = new Playlist(name);
        }

        void addSongToPlaylist(const string& playlistName, Song *song){
            if(!playlists.count(playlistName)){
                throw runtime_error("Playlist: " + playlistName + " does not exist");
            }

            playlists[playlistName]->addSongToList(song);
        }

        Playlist* getPlaylist(const string& name){
            if(!playlists.count(name)){
                throw runtime_error("Playlist: " + name + " does not exist");
            }
            return playlists[name];
        }
};

PlaylistManager* PlaylistManager::instance = nullptr;