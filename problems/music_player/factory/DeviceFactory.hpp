#pragma once

#include<bits/stdc++.h>
#include"../device/BluetoothSpeakerAdapter.hpp"
#include"../device/HeadPhoneAdapter.hpp"
#include"../device/IAudioOutputDevice.hpp"
#include"../device/WiredSpeakerAdapter.hpp"
#include"../enums/DeviceType.hpp"

using namespace std;

class DeviceFactory {
    public:
        static IAudioOutputDevice* createDevice(DeviceType deviceType){
            if(deviceType == DeviceType::BLUETOOTH){
                return new BluetoothSpeakerAdapter(new BluetoothSpeakerAPI());
            }else if(deviceType == DeviceType::HEADPHONE){
                return new HeadPhoneAdapter(new HeadPhoneAPI());
            }else{
                return new WiredSpeakerAdapter(new WiredSpeakerAPI());
            }
        }
};

