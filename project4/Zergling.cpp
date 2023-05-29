#include "Zergling.h"

Zergling::Zergling() {

}

Zergling::Zergling(string name, int health) {
    SetName(name);
    SetHealth(health);
}

int Zergling::SpecialAttack() {
    int specialAttack = 1;
    cout << GetName() << " scratches at you ferociously!" << endl;
    cout << GetName() << " deals " << specialAttack << " points of damage" << endl;
    return specialAttack;
}