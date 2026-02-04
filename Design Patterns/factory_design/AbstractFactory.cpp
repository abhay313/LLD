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

class GarlicBread {
    public:
        virtual void prepare() = 0;
};

class BasicGarlicBread: public GarlicBread {
    public:
        void prepare() override {
            cout << "Basic Garlic Bread" << endl;
        }
};
class CheeseGarlicBread: public GarlicBread {
    public:
        void prepare() override {
            cout << "Cheese Garlic Bread" << endl;
        }
};

class BasicWheatGarlicBread: public GarlicBread {
    public:
        void prepare() override {
            cout << "Basic Wheat Garlic Bread" << endl;
        }
};
class CheeseWheatGarlicBread: public GarlicBread {
    public:
        void prepare() override {
            cout << "Cheese Wheat Garlic Bread" << endl;
        }
};

class MealFactory {
    public:
        virtual Burger* createBurger(string &type) = 0;
        virtual GarlicBread* createGarlicBread(string &type) = 0;
};

class KingBurger: public MealFactory {
    public:
        Burger* createBurger(string &type)override{
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

         GarlicBread* createGarlicBread(string &type)override{
            if(type == "basic"){
                return new BasicGarlicBread();
            }else if(type == "cheese"){
                return new CheeseGarlicBread();
            }else {
                cout << "Invalid type " << endl;
                return nullptr;
            }
        }
};

class SinghBurger: public MealFactory {
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

        GarlicBread* createGarlicBread(string &type)override{
            if(type == "basicWheat"){
                return new BasicWheatGarlicBread();
            }else if(type == "cheeseWheat"){
                return new CheeseWheatGarlicBread();
            }else {
                cout << "Invalid type " << endl;
                return nullptr;
            }
        }
};

int main(){
    string burgerType = "premiumWheat";
    string garlicType = "cheeseWheat";
    MealFactory *mealFactory = new SinghBurger();
    Burger *burgerK = mealFactory->createBurger(burgerType);
    burgerK->prepare();
    
    GarlicBread *garlicBread = mealFactory->createGarlicBread(garlicType);
    garlicBread->prepare();
    return 0;
}