#include <iostream>

using namespace std;

#include "Elf.h"

Elf::Elf(const string &name, double hlth, double attckStrgh, const string & famName)
: Character(ELF, name, hlth, attckStrgh), familyName(famName) {}

void Elf::attack(Character &opponent) {
    
    double d = (this-> health / MAX_HEALTH) * this -> attackStrength;

    if (opponent.getType() != ELF) {
        cout << "Elf " << this -> name << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
        cout << opponent.getName() << " takes " << d << " damage." << endl;
        opponent.damage(d);
    }
    else {
        Elf &opp = dynamic_cast<Elf &> (opponent);

        if (opp.familyName != this-> familyName) {
            cout << "Elf " << this -> name << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
            cout << opponent.getName() << " takes " << d << " damage." << endl;
            opponent.damage(d);
        }
        else {
            cout << "Elf " << this-> name << " does not attack Elf " << opponent.getName() << "." << endl;
            cout << "They are both members of the " << this-> familyName << " family." << endl;
        }
    }
}