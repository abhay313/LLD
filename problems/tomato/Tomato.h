#ifndef TOMATO_APP_H
#define TOMATO_APP_H

#include <vector>
#include <string>
#include "models/User.h"
#include "models/Restaurant.h"
#include "models/Cart.h"
#include "managers/RestaurantManager.h"
#include "managers/OrderManager.h"
#include "strategies/PaymentStrategy.h"
#include "strategies/UpiPaymentStrategy.h"
#include "factories/NowOrderFactory.h"
#include "factories/ScheduledOrderFactory.h"
#include "services/NotificationService.h"
#include "utils/TimeUtils.h"
using namespace std;

class TomatoApp {
    public:
        TomatoApp(){
            initializeRestaurants();
        }
        void initializeRestaurants() {
            Restaurant *r1 = new Restaurant("Bikaner", "Delhi");
            r1->addMenuItem(MenuItem("p1", "samosa", 40));
            r1->addMenuItem(MenuItem("p2", "Chole bhature", 110));

            Restaurant *r2 = new Restaurant("Haldiram", "Delhi");
            r1->addMenuItem(MenuItem("p1", "Namkeed", 410));
            r1->addMenuItem(MenuItem("p2", "Poha", 100));

            RestaurantManager *restaurantManager = RestaurantManager::getInstance();
            restaurantManager->addRestaurant(r1);
            restaurantManager->addRestaurant(r2);
        }
        vector<Restaurant*> searchRestaurants(const string &location){
            return RestaurantManager::getInstance()->searchByLocation(location);
        }

        void setRestaurant(User *user, Restaurant *restaurant){
            Cart *cart = user->getCart();
            cart->setRestaurant(restaurant);
        }

        void addToCart(User *user, const string &itemCode){
            Restaurant *restaurant = user->getCart()->getRestaurant();
            if(!restaurant){
                cout << "select restaurant first..." << endl;
                return;
            }

            for(const auto &item: restaurant->getMenu()){
                if(itemCode == item.getCode()){
                    user->getCart()->addItem(item);
                    break;
                }
            }
        }

        Order *checkoutNow(User *user, const string& orderType, PaymentStrategy *paymentStrategy){
            return checkout(user, orderType, paymentStrategy, new NowOrderFactory());
        }

        Order* checkoutScheduled(User* user, const string& orderType, PaymentStrategy* paymentStrategy, const string& scheduleTime) {
            return checkout(user, orderType, paymentStrategy, new ScheduledOrderFactory(scheduleTime));
        }

        Order* checkout(User *user, const string &orderType, PaymentStrategy *paymentStrategy, OrderFactory *orderFactory){
            if(user->getCart()->isEmpty()){
                return nullptr;
            }

            Cart *userCart = user->getCart();
            Restaurant* orderedRestaurant = userCart->getRestaurant();
            vector<MenuItem> itemsOrdered = userCart->getItems();
            double totalCost = userCart->getTotalCost();

            Order* order = orderFactory->createOrder(user, userCart, orderedRestaurant, itemsOrdered, paymentStrategy, orderType);
            OrderManager::getInstance()->addOrder(order);
            return order;
        }

        void payForOrder(User* user, Order* order) {
            bool isPaymentSuccess = order->processPayment();

            // clear user cart if payment is successful.
            if(isPaymentSuccess) {
                NotificationService* notification = new NotificationService();
                notification->notify(order);
                user->getCart()->clear();
            }  
        }

        void printUserCart(User* user) {
            cout << "Items in cart:" << endl;
            cout << "------------------------------------" << endl;
            for (const auto& item : user->getCart()->getItems()) {
                cout << item.getCode() << " : " << item.getName() << " : ₹" << item.getPrice() << endl;
            }
            cout << "------------------------------------" << endl;
            cout << "Grand total : ₹" << user->getCart()->getTotalCost() << endl;
        }
};

#endif