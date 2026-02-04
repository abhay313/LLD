#ifndef UPI_PAYMENT_STRATEGY_H
#define UPI_PAYMENT_STRATEGY_H

#include<bits/stdc++.h>
#include "PaymentStrategy.h"
using namespace std;

class UpiPaymentStrategy: public PaymentStrategy
{
private:
    string mobile;
public:
    UpiPaymentStrategy(const string &mob){
        mobile = mob;
    }
    void pay(double amount){
        cout << "Payment done of amount: " << amount << " by UPI: " << mobile << endl;
    }
};

#endif