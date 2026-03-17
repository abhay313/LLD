#include<bits/stdc++.h>
using namespace std;

class DiscountStrategy {
    public:
        virtual ~DiscountStrategy() {}
        virtual double calculate(double baseAmount) = 0;
};

class FlatDiscountStrategy: public DiscountStrategy {
    private:
        double amount;
    public:
        FlatDiscountStrategy(double amt){
            this->amount = amt;
        }
        double calculate(double baseAmount) override {
            return min(baseAmount, amount);
        }
};

class PercentDiscountStrategy: public DiscountStrategy {
    private:
        double percent;
    public:
        PercentDiscountStrategy(double pct){
            this->percent = pct;
        }
        double calculate(double baseAmount) override {
            return (percent / 100.0) * baseAmount;
        }
};

class PercentCapStrategy: public DiscountStrategy {
    private:
        double percent;
        double cap;
    public:
        PercentCapStrategy(double pct, double capVal){
            this->percent = pct;
            this->cap = capVal;
        }

        double calculate(double baseAmount) override {
            double dis = (percent / 100.0) * baseAmount;
            return min(dis, cap);
        }
};

enum StrategyType {
    FLAT,
    PERCENT,
    PERCENT_WITH_CAP
};

class DiscountStrategyManager {
    private:
        static DiscountStrategyManager *instance;
        DiscountStrategyManager() {}
        DiscountStrategyManager(const DiscountStrategyManager&) = delete;
        DiscountStrategyManager &operaator(const DiscountStrategyManager&) = delete;
    public:
        static DiscountStrategyManager* getInstance(){
            if(!instance){
                instance = new DiscountStrategyManager();
            }
            return instance;
        }

        DiscountStrategy* getStrategy(StrategyType type, double param1, double param2 = 0.0)const {
            if(type == StrategyType::FLAT){
                return new FlatDiscountStrategy(param1);
            }
            if(type == StrategyType::PERCENT){
                return new PercentDiscountStrategy(param1);
            }
            if(type == StrategyType::PERCENT_WITH_CAP){
                return new PercentCapStrategy(param1, param2);
            }
            return nullptr;
        }
};

DiscountStrategyManager* DiscountStrategyManager::instance = nullptr;

class Product {
    private:
        string name;
        string category;
        double price;
    public:
        Product(string n, string c, double p) {
            this->name = n;
            this->category = c;
            this->price = p;
        }

        string getName(){
            return name;
        }

        string getCategory() const {
            return category;
        }

        double getPrice(){
            return price;
        }
};

class CartItem {
    private:
        Product* product;
        int quantity;
    public:
        CartItem(Product *p, int q){
            product = p;
            quantity = q;
        }

        double itemTotal(){
            return product->getPrice() * quantity;
        }

        const Product* getProduct(){
            return product;
        }
};

class Cart {
    private:
        vector<CartItem*> items;
        double originalTotal;
        double currentTotal;
        bool loyaltyMember;
        string paymentBank;
    public:
        Cart() {
            originalTotal = 0.0;
            currentTotal = 0.0;
            loyaltyMember = false;
            paymentBank = "";
        }

        void addProduct(Product *prod, int qty = 1){
            CartItem *item = new CartItem(prod, qty);
            items.push_back(item);
            originalTotal += item->itemTotal();
            currentTotal += item->itemTotal();
        }

        double getOriginalTotal(){
            return originalTotal;
        }

        double getCurrentTotal() {
            return currentTotal;
        }

        void applyDiscount(double d) {
            currentTotal -= d;
            if(currentTotal < 0){
                currentTotal = 0;
            }
        }

        void setLoyalityMember(bool member){
            loyaltyMember = member;
        }

        bool isLoyalityMemmber(){
            return loyaltyMember;
        }

        void setPaymentBank(string bank){
            paymentBank = bank;
        }

        string getPaymentBank(){
            return paymentBank;
        }

        vector<CartItem*> getItems(){
            return items;
        }
};

class Coupon {
    private:
        Coupon *next;
    public:
        Coupon(){
            next = nullptr;
        }

        virtual ~Coupon(){
            if(next){
                delete next;
            }
        }

        void setNext(Coupon *nxt){
            next = nxt;
        }

        Coupon *getNext(){
            return next;
        }

        void applyDiscount(Cart *cart){
            if(isApplicable(cart)){
                double discount = getDiscount(cart);
                cart->applyDiscount(discount);
                cout << name() << " applied: " << discount << endl;
                if(!isCombinable()){
                    return;
                }
            }
            if(next){
                next->applyDiscount(cart);
            }
        }

        virtual bool isApplicable(Cart *cart) = 0;
        virtual double getDiscount(Cart *cart) = 0;
        virtual bool isCombinable(){
            return true;
        }
        virtual string name() = 0;
};

class SeasonalOffer: public Coupon {
    private:
        double percent;
        string category;
        DiscountStrategy *strat;
    public:
        SeasonalOffer(double pct, string cat){
            percent = pct;
            category = cat;
            strat = DiscountStrategyManager::getInstance()->getStrategy(StrategyType::PERCENT, percent);
        }

        ~SeasonalOffer(){
            delete strat;
        }

        bool isApplicable(Cart *cart) override {
            for(CartItem *item: cart->getItems()){
                if(item->getProduct()->getCategory() == category){
                    return true;
                }
            }
            return false;
        }

        double getDiscount(Cart *cart) override {
            double subTotal = 0.0;
            for(CartItem *item: cart->getItems()){
                if(item->getProduct()->getCategory() == category){
                    subTotal += item->itemTotal();
                }
            }
            return strat->calculate(subTotal);
        }

        bool isCombinable() override {
            return true;
        }

        string name() override {
            return "Seasonal offer " + to_string((int)percent) + "% off " + category;
        }
};

class LoyalityDiscount: public Coupon {
    private:
        double percent;
        DiscountStrategy *strat;
    public:
        LoyalityDiscount(double pct){
            percent = pct;
            strat = DiscountStrategyManager::getInstance()->getStrategy(StrategyType::PERCENT, percent);
        }

        ~LoyalityDiscount(){
            delete strat;
        }

        bool isApplicable(Cart *cart) override {
            return cart->isLoyalityMemmber();
        }

        double getDiscount(Cart *cart) override {
            return strat->calculate(cart->getCurrentTotal());
        }

        string name() override {
            return "Loyality Discount " + to_string((int)percent) + "% off ";
        } 
};

class BulkPurchaseDiscount: public Coupon {
    private:
        double thresold;
        double flatOff;
        DiscountStrategy *strat;
    public:
        BulkPurchaseDiscount(double thr, double off){
            thresold = thr;
            flatOff = off;
            strat = DiscountStrategyManager::getInstance()->getStrategy(StrategyType::FLAT, flatOff);
        }

        ~BulkPurchaseDiscount(){
            delete strat;
        }

        bool isApplicable(Cart *cart) override {
            return cart->getOriginalTotal() >= thresold;
        }

        double getDiscount(Cart *cart) override {
            return strat->calculate(cart->getCurrentTotal());
        }

        string name() override {
            return "Bulk purchase " + to_string((int)flatOff) + "% off over ";
        } 
};

class BankingCoupon : public Coupon {
private:
    string bank;
    double minSpend;
    double percent;
    double offCap;
    DiscountStrategy* strat;
public:
    BankingCoupon(const string& b, double ms, double percent, double offCap) {
        bank = b;
        minSpend = ms;
        this->percent = percent;
        this->offCap = percent;
        strat = DiscountStrategyManager::getInstance()->getStrategy(StrategyType::PERCENT_WITH_CAP, percent, offCap);
    }
    ~BankingCoupon() {
        delete strat;
    }
    bool isApplicable(Cart* cart) override {
        return cart->getPaymentBank() == bank
            && cart->getOriginalTotal() >= minSpend;
    }
    double getDiscount(Cart* cart) override {
        return strat->calculate(cart->getCurrentTotal());
    }
    string name() override {
        return bank + " Bank Rs " + to_string((int)percent) + " off upto " + to_string((int) offCap);
    }
};

class CouponManager {
    private:
        static CouponManager *instance;
        Coupon *head;
        mutable mutex mtx;
        CouponManager() {
            head = nullptr;
        }
    public:
        static CouponManager* getInstance() {
            if(!instance){
                instance = new CouponManager();
            }
            return instance; 
        }

        void registerCoupon(Coupon *coupon){
            lock_guard<mutex> lock(mtx);
            if(!head) {
                head = coupon;
            }else{
                Coupon *curr = head;
                while(curr->getNext()){
                    curr = curr -> getNext();
                }
                curr->setNext(coupon);
            }
        }

        vector<string> getApplicable(Cart *cart) const {
            lock_guard<mutex> lock(mtx);
            vector<string> res;
            Coupon *curr = head;
            while(curr){
                if(curr->isApplicable(cart)){
                    res.push_back(curr->name());
                }
                curr = curr->getNext();
            }
            return res;
        }

        double applyAll(Cart *cart){
            lock_guard<mutex> lock(mtx);
            if(head){
                head->applyDiscount(cart);
            }
            return cart->getCurrentTotal(); 
        }
};

CouponManager* CouponManager::instance = nullptr; 

int main() {

    CouponManager* mgr = CouponManager::getInstance();
    mgr->registerCoupon(new SeasonalOffer(10, "Clothing"));
    mgr->registerCoupon(new LoyalityDiscount(5));
    mgr->registerCoupon(new BulkPurchaseDiscount(1000, 100));
    mgr->registerCoupon(new BankingCoupon("ABC", 2000, 15, 500));

    Product* p1 = new Product("Winter Jacket", "Clothing", 1000);
    Product* p2 = new Product("Smartphone", "Electronics", 20000);
    Product* p3 = new Product("Jeans", "Clothing", 1000);
    Product* p4 = new Product("Headphones", "Electronics", 2000);

    Cart* cart = new Cart();
    cart->addProduct(p1, 1);
    cart->addProduct(p2, 1);
    cart->addProduct(p3, 2);
    cart->addProduct(p4, 1);
    cart->setLoyalityMember(true);
    cart->setPaymentBank("ABC");

    cout << "Original Cart Total: " << cart->getOriginalTotal() << " Rs" << endl;



    vector<string> applicable = mgr->getApplicable(cart);
    cout << "Applicable Coupons:" << endl;
    for (string name : applicable) {
        cout << " - " << name << endl;
    }

    double finalTotal = mgr->applyAll(cart);
    cout << "Final Cart Total after discounts: " << finalTotal << " Rs" << endl;

    // Cleanup code
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete cart;

    return 0;
}







