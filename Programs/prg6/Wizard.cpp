#include <iostream>

using namespace std;

#include "Wizard.h"

Wizard::Wizard(const string &name, double hlth, double attckStrgh, int rnk)
: Character(WIZARD, name, hlth, attckStrgh), rank(rnk) {}

void Wizard::attack(Character &opponent) {
    double d = this -> attackStrength;

    if (opponent.getType() == WIZARD) {
        Wizard &opp = dynamic_cast<Wizard &> (opponent);
        d = this -> attackStrength * ( static_cast <double> (this-> rank) / opp.rank);
    }

    cout << "Wizard " << this-> name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
    cout << opponent.getName() << " takes " << d << " damage." << endl;
    opponent.damage(d);
    
}