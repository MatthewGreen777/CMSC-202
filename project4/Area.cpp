#include "Area.h"

Area::Area(int ID, string name, string description, int north, int east, int south, int west) {
    m_ID = ID;
    m_name = name;
    m_desc = description;
    m_direction[0] = north;
    m_direction[1] = east;
    m_direction[2] = south;
    m_direction[3] = west;
}

string Area::GetName() {
    return m_name;
}

int Area::GetID() {
    return m_ID;
}

string Area::GetDesc() {
    return m_desc;
}

int Area::CheckDirection(char myDirection) {
    direction compass;
    if ((myDirection == 'N') || (myDirection == 'n')) {
        compass = n;
    } else if ((myDirection == 'E') || (myDirection == 'e')) {
        compass = e;
    } else if ((myDirection == 'S') || (myDirection == 's')) {
        compass = s;
        return m_direction[compass];
    } else if ((myDirection == 'W') || (myDirection == 'w')) {
        compass = w;
    } else {
        return -1;
    }
    return m_direction[compass];
}

void Area::PrintArea() {
    cout << "Room: " << GetName() << endl;
    cout << "Description: " << GetDesc() << endl;
    cout << "Possible Exits: ";
    // checks each direction if it is an exit
    if (CheckDirection('N') != -1) {
        cout << "N";
    }
    if (CheckDirection('E') != -1) {
        cout << "E";
    }
    if (CheckDirection('S') != -1) {
        cout << "S";
    }
    if (CheckDirection('W') != -1) {
        cout << "W";
    }
    cout << endl;
}