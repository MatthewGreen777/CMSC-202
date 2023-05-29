#include "Hydralisk.h"

Hydralisk::Hydralisk() {

}

Hydralisk::Hydralisk(string name, int health) {
    SetName(name);
    SetHealth(health);
}

int Hydralisk::SpecialAttack() {
    int specialAttack = 2;
    cout << GetName() << " sprays you with deadly acid!" << endl;
    cout << GetName() << " deals " << specialAttack << " points of damage" << endl;
    return specialAttack;
}