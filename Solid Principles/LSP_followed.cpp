#include<bits/stdc++.h>
using namespace std;

class DepositOnlyAccount {
    public:
        virtual void deposit(double amount) = 0;
};

class WithdrawableAccount: public DepositOnlyAccount {
    public:
        virtual void withdraw(double amount) = 0;
};

class SavingAccount: public WithdrawableAccount {
    private:
        double balance;
    public:
        SavingAccount(){
            balance = 0;
        }

        void deposit(double amount){
            balance += amount;
            cout << "Deposited SA: " << amount << " new balance: " << balance << endl;
        }
        
        void withdraw(double amount){
            if(balance >= amount){
                balance -= amount;
                cout << "Withdrawn SA: " << amount << " new balance: " << balance << endl;
            }else{
                cout << "Cannot withdrawn, insufficient balance: " << endl;
            }
        }
};

class CurrentAccount: public WithdrawableAccount {
    private:
        double balance;
    public:
        CurrentAccount(){
            balance = 0;
        }

        void deposit(double amount){
            balance += amount;
            cout << "Deposited CA: " << amount << " new balance: " << balance << endl;
        }
        
        void withdraw(double amount){
            if(balance >= amount){
                balance -= amount;
                cout << "Withdrawn CA: " << amount << " new balance: " << balance << endl;
            }else{
                cout << "Cannot withdrawn, insufficient balance: " << endl;
            }
        }
};

class FixedAccount: public DepositOnlyAccount {
    private:
        double balance;
    public:
        FixedAccount(){
            balance = 0;
        }

        void deposit(double amount){
            balance += amount;
            cout << "Deposited FA: " << amount << " new balance: " << balance << endl;
        }
        
        void withdraw(double amount){
            if(balance >= amount){
                balance -= amount;
                cout << "Withdrawn FA: " << amount << " new balance: " << balance << endl;
            }else{
                cout << "Cannot withdrawn, insufficient balance: " << endl;
            }
        }
};

class BankClient {
    private:
        vector<WithdrawableAccount*> withdrawableAccount;
        vector<DepositOnlyAccount*> depositOnlyAccount;
    public:
        BankClient(vector<WithdrawableAccount*> withdrawableAccount, vector<DepositOnlyAccount*> depositOnlyAccount){
            this->withdrawableAccount = withdrawableAccount;
            this->depositOnlyAccount = depositOnlyAccount;
        }

        void ProcessTransaction(){
            for(auto acc: withdrawableAccount){
                acc->deposit(100);
                acc->withdraw(10);
            }
            for(auto acc: depositOnlyAccount){
                acc->deposit(1000);
                // acc->withdraw(10);
            }
            
        }
};

int main(){
    vector<WithdrawableAccount*> w;
    
    w.push_back(new SavingAccount());
    w.push_back(new CurrentAccount());

    vector<DepositOnlyAccount*> d;
    d.push_back(new FixedAccount());

    BankClient *client = new BankClient(w, d);
    client->ProcessTransaction();
    return 0;
}
