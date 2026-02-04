#include<bits/stdc++.h>
using namespace std;


class Product {
    public: 
        string name;
        double price;
    
        Product(string name, double price){
            this->name = name;
            this->price = price;
        }
};


class ShoppingCart {
    private: 
        vector<Product*> products;
    
    public:
        void addProduct(Product *p){
            products.push_back(p);
        }

        const vector<Product*>& getProducts(){
            return products;
        }

        double calculateTotal(){
            double total = 0;
            for(auto p: products){
                total += p->price;
            }
            return total;
        }
};

class ShoppingCartPrinter {
    private:
        ShoppingCart *cart;
    
    public:
        ShoppingCartPrinter(ShoppingCart *cart){
            this->cart = cart;
        }

        void printInvoice(){
            cout << "Prinitng Invoice" << endl;
            for(auto p: cart->getProducts()){
                cout << p-> name << " " << p->price << endl;
            }
            cout << "Total price: " << cart->calculateTotal() << endl;
        }
};

class Persistance {
    private:
        ShoppingCart* cart;

    public:
        virtual void save(ShoppingCart *cart) = 0;
};

class SQLPersistance: public Persistance{
    public:
        void save(ShoppingCart *cart) override{
            cout << "SQL Save" << endl;
        }
};

class MongoDBPersistance: public Persistance{
    public:
        void save(ShoppingCart *cart) override{
            cout << "MongoDB Save" << endl;
        }
};
class FilePersistance: public Persistance{
    public:
        void save(ShoppingCart *cart) override{
            cout << "File Save" << endl;
        }
};

int main(){
    ShoppingCart *cart = new ShoppingCart();
    cart->addProduct(new Product("Laptop", 500));
    cart->addProduct(new Product("Mouse", 100));

    ShoppingCartPrinter *printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    Persistance *sqlDB = new SQLPersistance();
    Persistance *mongoDB = new MongoDBPersistance();

    sqlDB->save(cart);
    mongoDB->save(cart);

    return 0;
}