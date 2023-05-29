#include "Terran.h"

Terran::Terran() {

}

Terran::Terran(string name, int health) {
 SetName(name);
 SetHealth(health);
}

Terran::~Terran() {

}

int Terran::Attack() {
    int attackDamage = (rand() % 6) + 1;
    cout << GetName() << " attacks, dealing " << attackDamage << " damage" << endl;
    return attackDamage;
}

int Terran::SpecialAttack() {
    cout << " Terran has no special attack" << endl;
    return 0;
}