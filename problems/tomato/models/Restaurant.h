#ifndef RESTAURANT_H
#define RESTAURANT_H

#include<bits/stdc++.h>
#include "MenuItem.h"
using namespace std;

class Restaurant {
    private:
        static int nextRestaurantId;
        int restaurantId;
        string name;
        string location;
        vector<MenuItem> menu;
    public:
        Restaurant(const string &name, const string &location){
            this->name = name;
            this->location = location;
            this->restaurantId = ++nextRestaurantId;
        }

        ~Restaurant(){
            cout << "Destorying restaurant: " << name  << " and clearing its menu "<< endl;
            menu.clear();
        }

        string getName(){
            return name;
        }

        void setName(const string &n){
            name = n;
        }

        string getLocation(){
            return location;
        }

        void setLocation(const string &loc){
            location = loc;
        }

        void addMenuItem(const MenuItem &item){
            menu.push_back(item);
        }

        const vector<MenuItem> getMenu() const{
            return menu;
        }
    
    };
int Restaurant::nextRestaurantId = 0;
#endif


