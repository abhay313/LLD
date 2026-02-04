#include<bits/stdc++.h> 
using namespace std;

// private constructor
// static instance

/*
use cases:
1. logging
2. database connection
3. confuguration manager

*/

class Singleton {
    private:
        static Singleton* instance;
        static mutex mtx;
        Singleton(){
            cout << " Singletion constructor called..." << endl;
        }
    public:
        static Singleton* getInstance(){
            if(instance == nullptr){
                lock_guard<mutex> lock(mtx);
                if(instance == nullptr){
                    instance = new Singleton();
                }
            }
            return instance;
        }
};

// instance intialization
Singleton* Singleton::instance = nullptr;
mutex Singleton::mtx;

int main(){
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    cout << (s1 == s2) << endl;

}

/*

Method-2 -> Eager intialization
locking is expensive can avoid some time by early intialization

Singleton* Singleton::instance = new Singleton()

Singleton* getInstace(){
return instance;
}

now no need lock and checking null ptr
but disadvantage is if not used in application its just waste of memory

*/