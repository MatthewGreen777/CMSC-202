#include "Mutalisk.h"

Mutalisk::Mutalisk() {

}

Mutalisk::Mutalisk(string name, int health) {
    SetName(name);
    SetHealth(health);
}

int Mutalisk::SpecialAttack() {
    int specialAttack = 4;
    cout << GetName() << " blasts you with their attack!" << endl;
    cout << GetName() << " deals " << specialAttack << " points of damage" << endl;
    return specialAttack;
}