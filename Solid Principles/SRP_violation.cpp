#include<bits/stdc++.h>
using namespace std;

// single responsibility principles

class Product {

    public:
        string name;
        double price;

        Product(string name, double price){
            this -> name = name;
            this -> price = price;
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

        // Responsibility - 1
        double calculateTotal(){
            double total = 0;
            for(auto p: products){
                total += p->price;
            }
            return total;
        }

        // Responsibilty - 2
        void printInvoice(){
            cout << "Prinitng Invoice" << endl;
            for(auto p: products){
                cout << p-> name << " " << p->price << endl;
            }
            cout << "Total price: " << calculateTotal() << endl;
        }

        // Responsibilty - 2
        void saveToDB(){
            cout << "Saving to database..." << endl;
        }
};

int main(){

    ShoppingCart *shoppingCart = new ShoppingCart();
    shoppingCart->addProduct(new Product("Laptop", 500));
    shoppingCart -> addProduct(new Product("Mouse", 50));

    shoppingCart->calculateTotal();
    shoppingCart->printInvoice();
    shoppingCart->saveToDB();
    return 0;
}