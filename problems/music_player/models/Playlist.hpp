#pragma once

#include<bits/stdc++.h>
#include"Songs.hpp"

using namespace std;

class Playlist {
    private:
        string playlistName;
        vector<Song*> songList;
    public:
        Playlist(string name){
            playlistName = name;
        }

        string getPlaylistName(){
            return playlistName;
        }

        const vector<Song*> getSongs(){
            return songList;
        }

        int getSize(){
            return songList.size();
        }

        void addSongToList(Song* song){
            if(song == nullptr){
                throw runtime_error("Cannot add null song to playlist");
            }
            songList.push_back(song);
        }
};