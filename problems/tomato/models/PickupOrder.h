#ifndef PICKUP_ORDER_H
#define PICKUP_ORDER_H

#include<bits/stdc++.h>
#include "Order.h"
using namespace std;

class PickupOrder: public Order {
    private:
        string restaurantAddress;
    public:
        PickupOrder(){
            restaurantAddress = "";
        }

        string getType() const override {
            return "Pickup";
        }

        void setRestaurantAddress(string &add){
            restaurantAddress = add;
        }

        string getRestaurantAddress() const {
            return restaurantAddress;
        }
};

#endif

