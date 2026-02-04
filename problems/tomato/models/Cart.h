#ifndef CART_H
#define CART_H

#include<bits/stdc++.h>
#include "../models/MenuItem.h"
#include "../models/Restaurant.h"
using namespace std;

class Cart
{
private:
    Restaurant* restaurant;
    vector<MenuItem> items;
public:
    Cart(){
        restaurant = nullptr;
    }

    void addItem(const MenuItem &item){
        if(!restaurant){
            cerr << "Cart: set a restaurant before adding items" << endl;
            return;
        }

        items.push_back(item);
    }
    
    double getTotalCost(){
        double total = 0;
        for(auto &i: items){
            total += i.getPrice();
        }
        return total;
    }

    bool isEmpty(){
        return (!restaurant || items.empty());
    }

    void clear(){
        items.clear();
        restaurant = nullptr;
    }

    void setRestaurant(Restaurant *r){
        restaurant = r;
    }

    Restaurant* getRestaurant() const{
        return restaurant;
    }

    const vector<MenuItem> getItems() const{
        return items;
    }
};


#endif