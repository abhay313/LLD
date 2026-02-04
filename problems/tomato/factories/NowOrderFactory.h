#ifndef NOW_ORDER_FACTORY_H
#define NOW_ORDER_FACTORY_H

#include<bits/stdc++.h>
#include "OrderFactory.h"
#include "../models/DeliveryOrder.h"
#include "../models/PickupOrder.h"
#include "../utils/TimeUtils.h"

using namespace std;

class NowOrderFactory: public OrderFactory {
    public:
        Order* createOrder(User* user, Cart *cart, Restaurant *restaurant, const vector<MenuItem> &menuItems,
             PaymentStrategy *paymentStrategy, const string &orderType) override{
                
                Order *order = nullptr;
                if(orderType == "Delivery"){
                    auto deliveryOrder = new DeliveryOrder();
                    string address = user->getAddress();
                    deliveryOrder->setAddress(address);
                    order = deliveryOrder;
                }else{
                    auto pickupOrder = new PickupOrder();
                    string restaurantAddress = restaurant->getLocation();
                    pickupOrder->setRestaurantAddress(restaurantAddress);
                    order = pickupOrder;
                }

                order->setUser(user);
                order->setRestaurant(restaurant);
                order->setItems(menuItems);
                order->setPaymentStrategy(paymentStrategy);
                order->setTotal(cart->getTotalCost());
                order->setScheduled(TimeUtils::getCurrentTime());
                return order;
             }
};

#endif