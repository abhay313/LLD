#ifndef CREDIT_CARD_STRATEGY_H
#define CREDIT_CARD_STRATEGY_H

#include<bits/stdc++.h>
#include "PaymentStrategy.h"
using namespace std;

class CreditCardStrategy: public PaymentStrategy
{
private:
    string cardNumber;
public:
    CreditCardStrategy(string &cardNumber){
        this->cardNumber = cardNumber;
    }

    void pay(double amount){
        cout << "Payment done of amount: " << amount << " by Credit card: " << cardNumber << endl;
    }
};

#endif