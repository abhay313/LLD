#include<bits/stdc++.h>
using namespace std;

/*
Decouples abstraction from its implementation so that both can vary independently

Abstraction: High level Deisgn (Car)
Implementations: Low level Design (Engine)

Use case:

1. TV (LCD, LED etc) vs Remote(Normal, Screentouch)
2. GUI (textbox, dropdown) vs OS (Windows, MacOS)
*/



class Engine {
    public:
        virtual void start() = 0;
        virtual ~Engine() {}
};

class PetrolEngine: public Engine {
    public:
        void start() override {
            cout << "Petrol Engine started" << endl;
        }
};

class DieselEngine: public Engine {
    public:
        void start() override {
            cout << "Diesel Engine started" << endl;
        }
};

class ElectricEngine: public Engine {
    public:
        void start() override {
            cout << "Electric Engine started" << endl;
        }
};

class Car {
    protected:
        Engine *engine;
    public:
        Car(Engine *e){
            engine = e;
        }

        virtual void drive() = 0;
};

class Sedan: public Car {
    public:
        Sedan(Engine *e): Car(e) {}

        void drive() override{
            engine->start();
            cout << "Driving Sedan" << endl;
        }
};

class SUV: public Car {
    public:
        SUV(Engine *e): Car(e) {}

        void drive() override {
            engine->start();
            cout << "Driving SUV" << endl;
        }
};

int main() {

    Engine *petrolE = new PetrolEngine();
    Engine *dieselE = new DieselEngine();
    Engine *electricE = new ElectricEngine();

    Car *sedan = new Sedan(petrolE);
    Car *suv = new SUV(electricE);
    Car *mysuv = new SUV(dieselE);

    sedan->drive();
    suv->drive();
    mysuv->drive();

    delete sedan;
    delete suv;
    delete mysuv;

    return 0;
}