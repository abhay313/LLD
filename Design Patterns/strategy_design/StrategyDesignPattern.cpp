#include<bits/stdc++.h> 
using namespace std;


class WalkableRobot {
    public:
        virtual void walk() = 0;
        virtual ~WalkableRobot(){};
};

class NormalWalk: public WalkableRobot {
    public:
        void walk() override {
            cout << "Normally walking ..." << endl;
        }
};
class NoWalk: public WalkableRobot {
    public:
        void walk() override {
            cout << "No walking ..." << endl;
        }
};
class TalkableRobot {
    public:
        virtual void talk() = 0;
        virtual ~TalkableRobot(){};
};

class NormalTalk: public TalkableRobot {
    public:
        void talk() override {
            cout << "Normally talking ..." << endl;
        }
};
class NoTalk: public TalkableRobot {
    public:
        void talk() override {
            cout << "No talking ..." << endl;
        }
};

class FlyableRobot {
    public:
        virtual void fly() = 0;
        virtual ~FlyableRobot(){};
};

class NormalFly: public FlyableRobot {
    public:
        void fly() override {
            cout << "Normally flying ..." << endl;
        }
};
class NoFly: public FlyableRobot {
    public:
        void fly() override {
            cout << "No flying ..." << endl;
        }
};

class Robot {
    protected:
        WalkableRobot *walkBehaviour;
        TalkableRobot *talkBehaviour;
        FlyableRobot *flyBehaviour;
    public:
        Robot(WalkableRobot *w, TalkableRobot *t, FlyableRobot *f){
            this->walkBehaviour = w;
            this->talkBehaviour = t;
            this->flyBehaviour = f;
        }

        void walk(){
            walkBehaviour->walk();
        }

        void talk(){
            talkBehaviour->talk();
        }

        void fly(){
            flyBehaviour->fly();
        }

        virtual void projection() = 0;
};

class CompanionRobot: public Robot {
    public:
        CompanionRobot(WalkableRobot *w, TalkableRobot *t, FlyableRobot *f)
        :Robot(w, t, f){}

        void projection() override {
            cout << "Display friendly companion feature..." << endl;
        }
        
    };
    
class WorkerRobot: public Robot {
        public:
        WorkerRobot(WalkableRobot *w, TalkableRobot *t, FlyableRobot *f)
        : Robot(w, t, f){}
        
        void projection() override {
            cout << "Display Worker feature..." << endl;
        }
};

int main(){
    Robot *r1 = new CompanionRobot(new NormalWalk(), new NormalTalk(), new NoFly());
    r1->walk();
    r1->talk();
    r1->fly();
    r1->projection();
    
    cout << "------------------" << endl;

    Robot *r2 = new WorkerRobot(new NoWalk(), new NoTalk(), new NormalFly());
    r2->walk();
    r2->talk();
    r2->fly();
    r2->projection();
    return 0;
}

