#include "Battlecruiser.h"

Battlecruiser::Battlecruiser() {

}

Battlecruiser::Battlecruiser(string name, int health) {
    SetName(name);
    SetHealth(health);
}

Battlecruiser::~Battlecruiser() {

}

int Battlecruiser::SpecialAttack() {
    int specialAttack = (rand() % 12) + 3;
    cout << GetName() << " uses the Yomato Cannon!" << endl;
    cout << GetName() << " delas " << specialAttack << " poiints of damage" << endl;
    return specialAttack;
}