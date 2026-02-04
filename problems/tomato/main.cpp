#include<bits/stdc++.h>
#include "Tomato.h"
using namespace std;

int main(){
    TomatoApp *tomato = new TomatoApp();

    User *user = new User(101, "Abhay", "Delhi");
    cout << "User: " << user->getName() << " is active" << endl;

    vector<Restaurant*> restaurantList = tomato->searchRestaurants(user->getAddress());

    if(restaurantList.empty()){
        cout << "No restaurant found " << endl;
        return 0;
    }

    cout << "Found Restaurants:" << endl;
    for (auto restaurant : restaurantList) {
        cout << " - " << restaurant->getName() << endl;
    }

    tomato->setRestaurant(user, restaurantList[0]);
    tomato->addToCart(user, "p1");
    tomato->addToCart(user, "p2");

    tomato->printUserCart(user);

    Order *order = tomato->checkoutNow(user, "Delivery", new UpiPaymentStrategy("4332345345356"));
    tomato->payForOrder(user, order);

    delete user;
    delete tomato;

    return 0;
}