#include <bits/stdc++.h>
using namespace std;

class INotification {
    public:
        virtual string getContent() const = 0;
        virtual ~INotification() {}
};

class SimpleNotification: public INotification {
    private:
        string text;
    public:
        SimpleNotification(const string &msg){
            text = msg;
        }
        string getContent() const override{
            return text;
        }
};

class INotificationDecorator: public INotification {
    protected:
        INotification *notification;
    public:
        INotificationDecorator(INotification *n){
            notification = n;
        }

        virtual ~INotificationDecorator() {}

};

class TimeStampDecorator: public INotificationDecorator {
    public:
        TimeStampDecorator(INotification *n): INotificationDecorator(n){}

        string getContent() const override{
            return "\n4th Feb 2026 13:29 ---" + notification->getContent();
        }
};

class SignatureDecorator: public INotificationDecorator {
    private:
        string signature;
    public:
        SignatureDecorator(INotification *n, const string &sign): INotificationDecorator(n){
            signature = sign;
        }

        string getContent() const override {
            return notification->getContent() + " " + signature;
        }
};

class IObserver {
    public:
        virtual void update() = 0;
        virtual ~IObserver() {}
};

class IObservable {
    public:
        virtual void addObserver(IObserver *observer) = 0;
        virtual void removeObserver(IObserver *observer) = 0;
        virtual void notifyObserver() = 0;
};

class NotificationObservable: public IObservable {
    private:
        vector<IObserver*> observers;
        INotification *currentNotification;
    public:
        NotificationObservable(){
            currentNotification = nullptr;
        }

        void addObserver(IObserver *observer) override {
            observers.push_back(observer);
        }

        void removeObserver(IObserver *observer) override {
            observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
        }
        
        void notifyObserver() override {
            for(unsigned int i = 0; i < observers.size(); i++){
                observers[i]->update();
            }
        }

        void setNotification(INotification *notification){
            if(currentNotification != nullptr){
                delete currentNotification;
            }
            currentNotification = notification;
            notifyObserver();
        }

        INotification* getNotification() {
            return currentNotification;
        }

        string getNotificationContent(){
            return currentNotification->getContent();
        }

        ~NotificationObservable(){
            if(currentNotification != NULL){
                delete currentNotification;
            }
        }
};
class NotificationService {
    private:
        NotificationObservable *observable;
        static NotificationService *instance;
        vector<INotification*> notifications;
        
        NotificationService() {
            observable = new NotificationObservable();
        }
    public:

        static NotificationService* getInstance() {
            if(instance == nullptr){
                instance = new NotificationService();
            }
            return instance;
        }

        NotificationObservable* getObservable() {
            return observable;
        }

        void sendNotification(INotification *notifcation){
            notifications.push_back(notifcation);
            observable->setNotification(notifcation);
        }

        ~NotificationService(){
            delete observable;
        }
};

NotificationService* NotificationService::instance = nullptr;

class Logger: public IObserver {
    private:
        NotificationObservable* notificationObservable;
    public:
        Logger() {
            this->notificationObservable = NotificationService::getInstance()->getObservable();
            notificationObservable->addObserver(this);
        }
        Logger(NotificationObservable *observable){
            this->notificationObservable = observable;
        }

        void update() {
            cout << "\n Logging new notification: \n" << notificationObservable->getNotificationContent();
        }
};

class INotificationStrategy {
    public:
        virtual void sendNotification(string content) = 0;
};

class EmailStrategy: public INotificationStrategy {
    private:
        string emailId;
    public:
        EmailStrategy(string emailId){
            this->emailId = emailId;
        }

        void sendNotification(string content) override {
            cout << "\n Sending notification to " << emailId << " " << content << endl;
        }
};

class SMSStrategy: public INotificationStrategy {
    private:
        string mobileNumber;
    public:
        SMSStrategy(string mobileNumber){
            this->mobileNumber = mobileNumber;
        }

        void sendNotification(string content) override {
            cout << "\n Sending notification to " << mobileNumber << " " << content << endl;
        }
};

class PopUpStrategy: public INotificationStrategy {

    public:
        void sendNotification(string content) override {
            cout << "\n Sending popup notification: " << content << endl;
        }
};

class NotificationEngine: public IObserver {
    private:
        NotificationObservable *notificationObservable;
        vector<INotificationStrategy*> notifcationStratgies;
    public:
        NotificationEngine() {
            this->notificationObservable = NotificationService::getInstance()->getObservable();
            notificationObservable->addObserver(this);
        }
        NotificationEngine(NotificationObservable *observable){
            this->notificationObservable = observable;
        }

        void addNotificationStrategy(INotificationStrategy *ns) {
            this->notifcationStratgies.push_back(ns);
        }

        void update() {
            string notificationContent = notificationObservable->getNotificationContent();
            for(const auto notificationStrategy: notifcationStratgies){
                notificationStrategy->sendNotification(notificationContent);
            } 
        }
};


int main() {

    NotificationService *notificationService = NotificationService::getInstance();

    Logger *logger = new Logger();
    NotificationEngine *notificationEngine = new NotificationEngine();
    
    notificationEngine->addNotificationStrategy(new EmailStrategy("xyz@gmail.com"));
    notificationEngine->addNotificationStrategy(new SMSStrategy("7845158692"));
    notificationEngine->addNotificationStrategy(new PopUpStrategy());

    //  ficationObservable->addObserver(notificationEngine);

    INotification *notification = new SimpleNotification("Your order has been shipped!!");
    notification = new TimeStampDecorator(notification);
    notification = new SignatureDecorator(notification, "Customer care");

    notificationService->sendNotification(notification);

    delete logger;
    delete notificationEngine;

    return 0;
}





















