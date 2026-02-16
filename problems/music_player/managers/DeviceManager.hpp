#pragma once

#include<bits/stdc++.h>

#include"../device/IAudioOutputDevice.hpp"
#include"../factory/DeviceFactory.hpp"
#include"../enums/DeviceType.hpp"

using namespace std;

class DeviceManager {
    private:
        static DeviceManager* instance;
        IAudioOutputDevice *currentOutputDevice;
        DeviceManager(){
            currentOutputDevice = nullptr;
        }
    public:
        static DeviceManager* getInstance(){
            if(instance == nullptr){
                instance = new DeviceManager();
            }
            return instance;
        }

        void connect(DeviceType deviceType){
            if(currentOutputDevice){
                delete currentOutputDevice;
            }
            currentOutputDevice = DeviceFactory::createDevice(deviceType);

            switch(deviceType){
                case DeviceType::BLUETOOTH:
                    cout << "Bluetooth connected" << endl;
                    break;
                case DeviceType::HEADPHONE:
                    cout << "Headphone connected" << endl;
                    break;
                case DeviceType::WIRED:
                    cout << "Wired connected" << endl;
                    break;
            }
        }

        IAudioOutputDevice* getOutputDevice(){
            if(!currentOutputDevice){
                throw runtime_error("No output device is connected");
            }
            return currentOutputDevice;
        }

        bool hasOutputDevice(){
            return currentOutputDevice != nullptr;
        }
};

DeviceManager* DeviceManager::instance = nullptr;