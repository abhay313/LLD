#ifndef ORDER_MANAGER_H
#define ORDER_MANAGER_H

#include<bits/stdc++.h>
#include "../models/Order.h"

using namespace std;

class OrderManager {
    private:
        vector<Order*> orders;
        static OrderManager *instance;

        OrderManager() {}
    
    public:
        static OrderManager* getInstance() {
            if(!instance){
                instance = new OrderManager();
            }
            return instance;
        }

        void addOrder(Order *order){
            orders.push_back(order);
        }

        void listOrders(){
            cout << "\n All Orders \n";
            for(auto &o: orders){
                cout << o->getType() <<  " for " << o->getUser()->getName()
                << " | Total: " << o->getTotal()
                << " | At: " << o->getScheduled() << endl;;
            }
        }

};

OrderManager* OrderManager::instance = nullptr;

#endif
