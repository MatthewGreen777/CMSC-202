#include "Zerg.h" 

Zerg::Zerg() {

}

Zerg::Zerg(string name, int health) {
    SetName(name);
    SetHealth(health);
}

int Zerg::Attack() {
    int attackDamage = 1;
    cout << GetName() << "deals " << attackDamage << " point of damage!" << endl;
    return attackDamage;
}

int Zerg::SpecialAttack() {
    return 0;
}