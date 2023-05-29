#include "Entity.h"

// not used
Entity::Entity() {

}
// not used
Entity::Entity(string name, int health) {
    SetName(name);
    SetHealth(health);
}

Entity::~Entity() {

}

//Accessor
string Entity::GetName() {
    return m_name;
}

// Accessor
int Entity::GetHealth() {
    return m_health;
}

// Mutator
void Entity::SetName(string name) {
    m_name = name;
}

//Mutator
void Entity::SetHealth(int health) {
    m_health = health;
}

// Overloaded operator
ostream& operator<<(ostream &output, Entity &E) {
    output << "Entity name: " << E.GetName() << "\nEntity Health: " << E.GetHealth();
    return output;
}