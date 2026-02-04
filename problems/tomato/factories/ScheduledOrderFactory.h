#ifndef SCHEDULED_ORDER_FACTORY_H
#define SCHEDULED_ORDER_FACTORY_H

#include "OrderFactory.h"
#include "../models/DeliveryOrder.h"
#include "../models/PickupOrder.h"
#include "../utils/TimeUtils.h"
using namespace std;

class ScheduledOrderFactory : public OrderFactory {
private:
    string scheduleTime;
public:
    ScheduledOrderFactory(string scheduleTime) {
        this->scheduleTime = scheduleTime;
    }

    Order* createOrder(User* user, Cart* cart, Restaurant* restaurant, const vector<MenuItem>& menuItems,
                        PaymentStrategy* paymentStrategy, const string& orderType) override {
        Order* order = nullptr;

        if(orderType == "Delivery") {
            auto deliveryOrder = new DeliveryOrder();
            string address = user->getAddress();
            deliveryOrder->setAddress(address);
            order = deliveryOrder;
        } 
        else {
            auto pickupOrder = new PickupOrder();
            string restaurantAddress = restaurant->getLocation();
            pickupOrder->setRestaurantAddress(restaurantAddress);
        }
        order->setUser(user);
        order->setRestaurant(restaurant);
        order->setItems(menuItems);
        order->setPaymentStrategy(paymentStrategy);
        order->setScheduled(scheduleTime);
        order->setTotal(cart->getTotalCost());
        return order;
    }
};

#endif // SCHEDULED_ORDER_FACTORY_H