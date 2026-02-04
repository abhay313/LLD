#include<bits/stdc++.h> 
using namespace std;

class Burger {
    public: 
        virtual void prepare() = 0;
     //   virtual ~Burger() = 0;
};

class BasicBurger: public Burger {
    public: 
        void prepare() override{
            cout << "Basic Burger..." << endl;
        }
};
class StandardBurger: public Burger {
    public: 
        void prepare() override{ 
            cout << "Standard Burger..." << endl;
        }
};
class PremiumBurger: public Burger {
    public: 
        void prepare() override{
            cout << "Premium Burger..." << endl;
        }
};

// Simple factory
class BurgerFactory {
    public:
        Burger *createBurger(string &type){
            if(type == "basic"){
                return new BasicBurger();
            }else if(type == "standard"){
                return new StandardBurger();
            }else if(type == "premium"){
                return new PremiumBurger();
            }else {
                cout << "Invalid type " << endl;
                return nullptr;
            }
        }
};

int main(){
    string myBurger = "premium";
    BurgerFactory *simpleFactory = new BurgerFactory();
    Burger *burger = simpleFactory->createBurger(myBurger);

    burger->prepare();
    return 0;
}



