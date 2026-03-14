#include<bits/stdc++.h> 
using namespace std;

/*
Use Cases:
1. Logged
    INFO l-1
    DeBUG l-2
    Error l-3
2. Deisgn leave request
    employee
    team lead
    manager
    director
*/

class MoneyHandler {
    protected:
        MoneyHandler *nextHandler;
    public:
        MoneyHandler(){
            nextHandler = nullptr;
        }

        void setNextHandler(MoneyHandler *next){
            nextHandler = next;
        }

        virtual void dispense(int amount) = 0;

};

class ThousandHandler: public MoneyHandler {
    private:
        int numNotes;
    public:
        ThousandHandler(int n){
            numNotes = n;
        }

        void dispense(int amount) override {
            int notesNeeded = amount/1000;
            if(notesNeeded > numNotes){
                notesNeeded = numNotes;
                numNotes = 0;
            }else{
                numNotes -= notesNeeded;
            }

            if(notesNeeded > 0) {
                cout << "Dispensing notes needed: " << notesNeeded << " x 1000 notes" << endl;
            }

            int remainingAmount = amount - (notesNeeded * 1000);
            if(remainingAmount > 0){
                if(nextHandler != nullptr){
                    nextHandler->dispense(remainingAmount);
                }else{
                    cout << "Reamining amount of " << remainingAmount << " cannot be fulfilled" << endl;
                }
            }
        };
};
class FiveHundredHandler: public MoneyHandler {
    private:
        int numNotes;
    public:
        FiveHundredHandler(int n){
            numNotes = n;
        }

        void dispense(int amount) override {
            int notesNeeded = amount/500;
            if(notesNeeded > numNotes){
                notesNeeded = numNotes;
                numNotes = 0;
            }else{
                numNotes -= notesNeeded;
            }

            if(notesNeeded > 0) {
                cout << "Dispensing notes needed: " << notesNeeded << " x 500 notes" << endl;
            }

            int remainingAmount = amount - (notesNeeded * 500);
            if(remainingAmount > 0){
                if(nextHandler != nullptr){
                    nextHandler->dispense(remainingAmount);
                }else{
                    cout << "Reamining amount of " << remainingAmount << " cannot be fulfilled" << endl;
                }
            }
        };
};
class TwoHundredHandler: public MoneyHandler {
    private:
        int numNotes;
    public:
        TwoHundredHandler(int n){
            numNotes = n;
        }

        void dispense(int amount) override {
            int notesNeeded = amount/200;
            if(notesNeeded > numNotes){
                notesNeeded = numNotes;
                numNotes = 0;
            }else{
                numNotes -= notesNeeded;
            }

            if(notesNeeded > 0) {
                cout << "Dispensing notes needed: " << notesNeeded << " x 200 notes" << endl;
            }

            int remainingAmount = amount - (notesNeeded * 200);
            if(remainingAmount > 0){
                if(nextHandler != nullptr){
                    nextHandler->dispense(remainingAmount);
                }else{
                    cout << "Reamining amount of " << remainingAmount << " cannot be fulfilled" << endl;
                }
            }
        };
};
class HundredHandler: public MoneyHandler {
    private:
        int numNotes;
    public:
        HundredHandler(int n){
            numNotes = n;
        }

        void dispense(int amount) override {
            int notesNeeded = amount/100;
            if(notesNeeded > numNotes){
                notesNeeded = numNotes;
                numNotes = 0;
            }else{
                numNotes -= notesNeeded;
            }

            if(notesNeeded > 0) {
                cout << "Dispensing notes needed: " << notesNeeded << " x 100 notes" << endl;
            }

            int remainingAmount = amount - (notesNeeded * 100);
            if(remainingAmount > 0){
                if(nextHandler != nullptr){
                    nextHandler->dispense(remainingAmount);
                }else{
                    cout << "Reamining amount of " << remainingAmount << " cannot be fulfilled" << endl;
                }
            }
        };
};

int main() {
    MoneyHandler *thousandHandler = new ThousandHandler(3);
    MoneyHandler *fiveHundredHandler = new FiveHundredHandler(5);
    MoneyHandler *twoHundredHandler = new TwoHundredHandler(10);
    MoneyHandler *hundredHandler = new HundredHandler(20);

    thousandHandler->setNextHandler(fiveHundredHandler);
    fiveHundredHandler->setNextHandler(twoHundredHandler);
    twoHundredHandler->setNextHandler(hundredHandler);

    int amount = 5000;

    cout << "\nDispense amount: " << amount << endl;
    thousandHandler->dispense(amount);

    return 0;
}