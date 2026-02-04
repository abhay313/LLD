#include<bits/stdc++.h>
using namespace std;

class Character {
    public:
        virtual string getAbilities() const = 0;
        virtual ~Character() {}
};

class Mario: public Character {
    public:
        string getAbilities() const override{
            return "Mario";
        }
};

// inheritance and composition (has-a relationship with is-a relationship both)
class CharacterDecorator: public Character {
    protected:
        Character *character;
    public:
        CharacterDecorator(Character *ch){
            this->character = ch;
        }
    
};

class HeightUp: public CharacterDecorator {
    public:
        HeightUp(Character *c): CharacterDecorator(c) {}
        string getAbilities() const override {
           return character->getAbilities() + " with HeightUp";
        }
};

class GunPower: public CharacterDecorator {
    public:
        GunPower(Character *c): CharacterDecorator(c) {}
        string getAbilities() const override {
            return character->getAbilities() + " with Gun";
        }
};

class StarPower: public CharacterDecorator {
    public:
        StarPower(Character *c): CharacterDecorator(c){}
        string getAbilities() const override {
            return character->getAbilities() + " with Star Power";
        }

        ~StarPower(){
            cout << "Destorying power" << endl;
        }
};


int main() {

    Character *mario = new Mario();
    cout << "Basic: " << mario->getAbilities() << endl;
    
    mario = new HeightUp(mario);
    cout << "Height: " << mario->getAbilities() << endl;
    
    mario = new GunPower(mario);
    cout << "Gun: " << mario->getAbilities() << endl;
    
    mario = new StarPower(mario);
    cout << "Star: " << mario->getAbilities() << endl;

    delete mario;

    return 0;
}
