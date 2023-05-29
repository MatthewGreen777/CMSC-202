#include "Ghost.h"

Ghost::Ghost() {

}

Ghost::Ghost(string name, int health) {
    SetName(name);
    SetHealth(health);
}

Ghost::~Ghost() {

}

int Ghost::SpecialAttack() {
    int specialAttack = (rand() % 12) + 2;
    cout << GetName() << " performs a sneak attack!" << endl;
    cout << GetName() << " deals " << specialAttack << " points of damage" << endl;
    return specialAttack;
}