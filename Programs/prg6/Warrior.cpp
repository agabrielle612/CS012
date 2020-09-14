#include <iostream>

using namespace std;

#include "Warrior.h"

Warrior::Warrior(const string &name, double hlth, double attckStrgh, const string & allg)
:Character( WARRIOR, name, hlth, attckStrgh), allegiance(allg) {}

void Warrior::attack(Character &opponent) {
    
    double d = (this-> health / MAX_HEALTH) * this -> attackStrength;

    if (opponent.getType() != WARRIOR) {
        cout << "Warrior " << this-> name << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
        cout << opponent.getName() << " takes " << d << " damage." << endl;
        opponent.damage(d);
    }
    else {
        Warrior &opp = dynamic_cast<Warrior &> (opponent);

        if (this-> allegiance != opp.allegiance) {
            cout << "Warrior " << this-> name << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
            cout << opponent.getName() << " takes " << d << " damage." << endl;
            opponent.damage(d);
        }
        else {
            cout << "Warrior " << this-> name << " does not attack Warrior " << opponent.getName() << "." << endl;
            cout << "They share an allegiance with " << this -> allegiance << "." << endl;
        }

    }

}
