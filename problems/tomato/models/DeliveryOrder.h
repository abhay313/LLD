#ifndef DELIVERY_ORDER_H
#define DELIVERY_ORDER_H

#include<bits/stdc++.h>
#include "Order.h"
using namespace std;

class DeliveryOrder: public Order {
    private:
        string userAddress;
    public:
        DeliveryOrder(){
            userAddress = "";
        }

        string getType() const override {
            return "Delivery";
        }

        void setAddress(string &add){
            userAddress = add;
        }

        string getAddress() const {
            return userAddress;
        }
};

#endif

