#include<bits/stdc++.h>
using namespace std;

class ISubscriber {
    public:
        virtual void update() = 0;
        virtual ~ISubscriber() {} 
};

class IChannel {
    public:
        virtual void notifySubscribers() = 0;
        virtual void subscribe(ISubscriber* subscriber) = 0;
        virtual void unsubscribe(ISubscriber* subscriber) = 0;
        virtual ~IChannel() {}
};

class Channel: public IChannel {
    private:
        vector<ISubscriber*> subscribers;
        string name;
        string latestVideo;
    public:
        Channel(const string &n){
            this->name = n;
            // this->latestVideo = lv;
        }

        void subscribe(ISubscriber* subscriber) override {
            if(find(subscribers.begin(), subscribers.end(), subscriber) == subscribers.end()){
                subscribers.push_back(subscriber);
            }
        }

        void unsubscribe(ISubscriber* subscriber) override {
            auto it = find(subscribers.begin(), subscribers.end(), subscriber);
            if(it != subscribers.end()){
                subscribers.erase(it);
            }
        }

        void notifySubscribers() override {
            
          // cout << subscribers[0] << endl;
            for(ISubscriber *sub: subscribers){
                sub->update();
            }
        }

        void uploadVideo(const string &title){
            latestVideo = title;
            cout << "\n " << name << " Video uploaded: " << title << endl;
            notifySubscribers();
        }

        string getVideoData(){
            return "\n checkout our new video: " +  latestVideo + "\n";
        }
};

class Subscriber: public ISubscriber {
    private:
        string name;
        Channel* channel;
    public:
        Subscriber(const string &name, Channel *ch){
            this->name = name;
            this->channel = ch;
        }

        void update() override{
           // cout << "****" << endl;
            cout << "\n Hey, " <<  name << ", " << channel->getVideoData() << endl;
        }
};


int main() {
    Channel *channel = new Channel("MyChannel");
    Subscriber *sub1 = new Subscriber("Abhay", channel);
    Subscriber *sub2 = new Subscriber("Amit", channel);
    
    channel->subscribe(sub1);
    channel->subscribe(sub2);

    channel->uploadVideo("Hello World Video");
    channel->unsubscribe(sub1);

    channel->uploadVideo("Second Video");

    return 0;

}