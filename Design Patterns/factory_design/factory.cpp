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

class BasicWheatBurger: public Burger {
    public: 
        void prepare() override{
            cout << "Basic Wheat Burger..." << endl;
        }
};
class StandardWheatBurger: public Burger {
    public: 
        void prepare() override{ 
            cout << "Standard Wheat Burger..." << endl;
        }
};
class PremiumWheatBurger: public Burger {
    public: 
        void prepare() override{
            cout << "Premium Wheat Burger..." << endl;
        }
};

class BurgerFactory {
    public:
        virtual Burger* createBurger(string &type) = 0;
};

class KingBurger: public BurgerFactory {
    public:
        Burger* createBurger(string &type){
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

class SinghBurger: public BurgerFactory {
    public:
        Burger* createBurger(string &type){
            if(type == "basicWheat"){
                return new BasicWheatBurger();
            }else if(type == "standardWheat"){
                return new StandardWheatBurger();
            }else if(type == "premiumWheat"){
                return new PremiumBurger();
            }else {
                cout << "Invalid type " << endl;
                return nullptr;
            }
        }
};

int main(){
    string typek = "premium";
    BurgerFactory *factoryK = new KingBurger();
    Burger *burgerK = factoryK->createBurger(typek);
    burgerK->prepare();
    
    string typeS = "standardWheat";
    BurgerFactory *factoryS = new SinghBurger();
    Burger *burgerS = factoryS->createBurger(typeS);
    burgerS->prepare();

    return 0;
}