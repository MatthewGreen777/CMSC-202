#include "Game.h"

Game::Game() {
    m_curArea = START_AREA;
    m_numRests = NUM_RESTS;
    m_numSpecial = NUM_SPECIAL;
    m_wins = START_WINS;
    m_filename = FILE_NAME;
    m_curZerg = nullptr;
    m_myTerran = nullptr;
}

Game::Game(string filename) {
    m_curArea = START_AREA;
    m_numRests = NUM_RESTS;
    m_numSpecial = NUM_SPECIAL;
    m_wins = START_WINS;
    m_filename = filename;
    m_curZerg = nullptr;
    m_myTerran = nullptr;
}

Game::~Game() {
    delete m_myTerran;
    delete m_curZerg;
    for (unsigned int  i = 0; i < m_myMap.size(); i++) {
        delete m_myMap.at(i);
    }
}

void Game::LoadMap() {
    string ID = " ";
    string name = " ";
    string description = " ";
    string north = " ";
    string east = " ";
    string south = " ";
    string west = " ";
    ifstream open(m_filename);
    while (getline(open, ID, DELIMITER)) {
        getline(open, name, DELIMITER);
        getline(open, description, DELIMITER);
        getline(open, north, DELIMITER);
        getline(open, east, DELIMITER);
        getline(open, south, DELIMITER);
        getline(open, west, '\n');

        Area *newArea = new Area(stoi(ID), name, description, stoi(north), stoi(east), stoi(south), stoi(west));
        m_myMap.push_back(newArea);
    }
    open.close();
}

void Game::TerranCreation() {
    string name = " ";
    int choice = 0;
    bool loop = true;

    cout << "Enter a name for you character:" << endl;
    cin >> name;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(256, '\n');
        name = "Dixon";
    }

    cout << endl << endl;
    cout << name <<  ": Select a class" << endl;
    cout << "1. Marine" << endl;
    cout << "2. Ghost" << endl;
    cout << "3. Battlecruiser" << endl;
    cout << "4. No Class" << endl;


    while (loop) {
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(256, '\n');
            choice = 0;
        }

        switch (choice) {
        case 1:
            m_myTerran = new Marine(name, MARINE_HEALTH);
            loop = false;
            break;
        case 2:
            m_myTerran = new Ghost(name, GHOST_HEALTH);
            loop = false;
            break;
        case 3:
            m_myTerran = new Battlecruiser(name, BATTLECRUISER_HEALTH);
            loop = false;
            break;
        case 4:
            m_myTerran = new Terran(name, TERRAN_HEALTH);
            loop = false;
            break;
        default:
            cout << "Choose one of the options" << endl;
        break;
        }
    }
}

void Game::StartGame() {
    LoadMap();
    cout << "Welcom to UMBC Starcraft!" <<  endl;
    TerranCreation();
    m_myMap.at(m_curArea)->PrintArea();
    Action();

}

void Game::Action() {
    int choice = 0;
    bool loop = true;
    RandomZerg();
        while (loop && (m_myTerran->GetHealth() > 0)) {
        cout << "What would you like to do?" << endl;
        cout << "1. Look" << endl;
        cout << "2. Move" << endl;
        cout << "3. Attack Zerg" << endl;
        cout << "4. Rest" << endl;
        cout << "5. Check Stats" << endl;
        cout << "6. Quit" << endl;
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(256, '\n');
            choice = 0;
        }
        switch (choice) {
            case 1:
                m_myMap.at(m_curArea)->PrintArea();
                break;
            case 2:
                Move();
                break;
            case 3:
                Attack();
                break;
            case 4: 
                Rest();
                break;
            case 5:
                Stats();
                break;
            case 6:
                cout << "Thank you for playing" << endl;
                loop = false;
                break;
            default:
                cout << "Chosee one of the options" << endl;
            break;
        }

        if (m_myTerran->GetHealth() <= 0) {
            cout << "GAME OVER" << endl;
            cout << "Thank you for playing" << endl;
            loop = false;
        }
    }

    cout << "\nYou won " << m_wins << " fights" << endl;
}

Entity* Game::RandomZerg() {
    int random = (rand() % 4) + 1;
    switch (random) {
        case 1:
            cout << "It is peaceful here" << endl;
            m_curZerg = nullptr;
            break;
        case 2:
            cout << "A small terrifying zergling waits here" << endl;
            m_curZerg = new Zergling("Zergling", ZERGLING_HEALTH);
            break;
        case 3:
            cout << "A large flying mutalisk hovers here" << endl;
            m_curZerg = new Mutalisk("Mutalisk", MUTALISK_HEALTH);
            break;
        case 4:
            cout << "A medium sized hydralisk slithers here waiting to cover you with acid" << endl;
            m_curZerg = new Hydralisk("Hydralisk", HYDRALISK_HEALTH);
            break;
    }
    return m_curZerg;
}

void Game::Rest() {
    if (m_curZerg != nullptr) {
        cout << "You cannot rest with a zerg in the area" << endl;
    } else if (m_numRests < 0) {
        cout << "You must have at least 1 one rest to rest" << endl;
    } else {
        m_myTerran->SetHealth(m_myTerran->GetHealth() + REST_HEAL);
        m_numSpecial = NUM_SPECIAL;
        m_numRests--;
    }
}

void Game::Move() {
    char direction = ' ';
    cout << "Which direction? (N E S W)" << endl;
    cin >> direction;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(256, '\n');
        direction = ' ';
    }
    if (m_myMap.at(m_curArea)->CheckDirection(direction) != -1) {
        if (m_curZerg != nullptr) {
            delete m_curZerg;
            m_curZerg = nullptr;
        }
        m_curArea = m_myMap.at(m_curArea)->CheckDirection(direction);
        m_myMap.at(m_curArea)->PrintArea();
        RandomZerg();
    } else {
        cout << "There is no exit in that direction" << endl;
    }
}

void Game::Attack() {
    int choice = 0;
    int damageDone = 0;
    int damageTaken = 0;
    if (m_curZerg == nullptr) {
        cout << "There is no Zerg to attack" << endl;
    } else {
        while ((m_myTerran->GetHealth() > 0) && (m_curZerg->GetHealth() > 0)) {
            cout << "1. Normal Attack" << endl;
            cout << "2. Special Attack" << endl;
            cin >> choice;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(256, '\n');
                choice = 0;
            }

            switch(choice) {
                case 1:
                    m_myTerran->SetHealth(m_myTerran->GetHealth() - m_curZerg->Attack());
                    m_curZerg->SetHealth(m_curZerg->GetHealth() - m_myTerran->Attack());
                    break;
                case 2:
                    if (m_numSpecial > 0) {
                        damageDone = m_myTerran->SpecialAttack();
                        damageTaken = m_curZerg->SpecialAttack();
                        m_myTerran->SetHealth(m_myTerran->GetHealth() - damageTaken);
                        m_curZerg->SetHealth(m_curZerg->GetHealth() - damageDone);
                        m_numSpecial--;
                    } else {
                        cout << "You are out of special attacks until you rest" << endl;
                    }
                    break;
                default:  
                    cout << "Choose one of the options" << endl;
                break;
            }
            if ((m_myTerran->GetHealth() > 0) && (m_curZerg->GetHealth() > 0)) {
                cout << m_myTerran->GetName() << "'s Health: " << m_myTerran->GetHealth() << endl;
                cout << m_curZerg->GetName() << "'s Health: " << m_curZerg->GetHealth() << endl;
            }
        }

        if (m_myTerran->GetHealth() > 0) {
            ProcessBattle(false, true);
        } else if ((m_myTerran->GetHealth() < 0) && (m_curZerg->GetHealth() < 0)) {
            ProcessBattle(false, false);
        } else if (m_myTerran->GetHealth() < 0) {
            ProcessBattle(true, false);
        }
        delete m_curZerg;
        m_curZerg = nullptr;
    }
}

void Game::Stats() {
    cout << "Name: " << m_myTerran->GetName() << endl;
    cout << "HP: " << m_myTerran->GetHealth() << endl;
    cout << "Rests: " << m_numRests << endl;
    cout << "Specials: " << m_numSpecial << endl;
    cout << "Wind: " << m_wins << endl;
}

void Game::ProcessBattle(bool zergAlive, bool alive) {
    int gainRest = (rand() % 100) + 1;

    if (alive) {
        cout << "You have defeated the " << m_curZerg->GetName() << endl;
        if (gainRest <= 10) {
            cout << "You gained a rest" << endl;
            m_numRests++;
        }
        m_wins++;
    } else if (zergAlive) {
        cout << "The " << m_curZerg->GetName() << " defeated you" << endl;
    } else if (!zergAlive && !alive) {
        cout << "You defeated each other at the same time" << endl;
        m_wins++;
    }
}