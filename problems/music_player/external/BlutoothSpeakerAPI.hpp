#pragma once

#include<bits/stdc++.h>
using namespace std;

class BluetoothSpeakerAPI {
    public:
        void playSoundViaBluetooth(const string &data){
            cout << "[Bluetooth Speaker] playnig: " + data << endl;
        }
};