#include "Marine.h"

Marine::Marine() {

}

Marine::Marine(string name, int health) {
    SetName(name);
    SetHealth(health);
}

Marine::~Marine() {

}

int Marine::SpecialAttack() {
    int specialAttack = (rand() % 8) + 1;
    cout << GetName() << " spins up and doing GATLING DAMAGE!" << endl;
    cout << GetName() << " delas " << specialAttack << " poiints of damage" << endl;
    return specialAttack;
}