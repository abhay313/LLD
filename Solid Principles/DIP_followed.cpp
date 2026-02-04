#include<bits/stdc++.h>
using namespace std;

class Database{
    public:
        virtual void save(string data) = 0;
};

class MySQLDatabase: public Database {
    public:
        void save(string data){
            cout << "In SQL DB: " << data << endl;
        }
};

class MongoDBDatabase: public Database {
    public:
        void save(string data){
            cout << "In MongoDB: " << data << endl;
        }
};

class UserService {
    private:
        Database *db;
    public:
        UserService(Database *database){
            this->db = database;
        }
        void storeUser(string user){
            db->save(user);
        }
};

int main(){
    MySQLDatabase mySQL;
    MongoDBDatabase mongoDB;

    UserService userService(&mySQL);
    userService.storeUser("Abhay");
    UserService userService2(&mongoDB);
    userService2.storeUser("Ajay");
    return 0;
}

