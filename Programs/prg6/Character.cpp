#include <iostream>

using namespace std;

#include "Character.h"

Character::Character(HeroType _type, const string & _name, double _health, double attckSt)
: type(_type), name(_name), health(_health), attackStrength(attckSt) {}

HeroType Character::getType() const {
    return type;
}

const string & Character::getName() const {
    return name;
}

int Character::getHealth() const {
    return static_cast <int > (health); //must return int 
}

void Character::setHealth(double h) {
    health = h;
}

void Character::damage(double d) {
    health = health - d;
}

bool Character::isAlive() const {
    if (health > 0) {
        return true;
    }
    return false;
}

