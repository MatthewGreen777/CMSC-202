#include "Player.h"

Player::Player() {
    m_name = "Beannie";
    m_races = 0;
    m_wins = 0;
    m_falls = 0;
    for (int i = 0; i <NUM_STATS; i++) {
        m_stat[i] = START_STAT;
    }
}

Player::Player(std::string name) {
    m_name = name;
    m_races = 0;
    m_wins = 0;
    m_falls = 0;
    for (int i = 0; i <NUM_STATS; i++) {
        m_stat[i] = START_STAT;
    }
}

std::string Player::GetName() {
    return m_name;
}

void Player::SetName(std::string name) {
    m_name = name;
}

int Player::GetSpeed() {
    return m_stat[0];
}

int Player::GetAgility() {
    return m_stat[1];
}

int Player::GetJump() {
    return m_stat[2];
}

int Player::GetRaces() {
    return m_races;
}

int Player::GetFalls() {
    return m_falls;
}

void Player::SetRaces(int races) {
    m_races = races + 1;
}

void Player::SetFalls(int falls) {
    m_falls = falls;
}

void Player::DisplayStatus() {
    std::cout << "****" << GetName() << "**********" << std::endl;
    std::cout << "Races: " << GetRaces() << std::endl;
    std::cout << "Wins: " << m_wins << std::endl;
    std::cout << "Falls: " << GetFalls() << std::endl << std::endl;
    std::cout << "Stats" << std::endl;
    std::cout << "Speed: " << GetStat(0) << std::endl;
    std::cout << "Agility: " << GetStat(1) << std::endl;
    std::cout <<"Jump: " << GetStat(2) << std::endl; 
}

void Player::IncreaseStat() {
    short input = 0;
    bool gate = true;

    std::cout <<"Which stat would you like to increase?" << std::endl;
    std::cout << "1. Speed" << std::endl;
    std::cout << "2. Agility" << std::endl;
    std::cout << "3. Jump" << std::endl;

    if ((m_stat[0] == MAX_STAT) && (m_stat[1] == MAX_STAT) && (m_stat[2] == MAX_STAT)) {
        std::cout << "All your stats are at the max" << std::endl;
    } else {
        while (gate) {
            std::cin >> input;
            if (((input - 1) < 0) || ((input - 1) > 2)) {
                std::cout << "Pick a number between 1 and 3" << std::endl;
                std::cin.clear();
                std::cin.ignore(256, '\n');
            } else if (m_stat[input - 1] >= MAX_STAT) {
                std::cout << "Stat is maxed out, pick a different one" << std::endl;
                std::cin.clear();
                std::cin.ignore(256, '\n');
            } else {
                m_stat[input - 1] = m_stat[input -1] + 1;
                gate = false;
            }
        }
    }
}

int Player::GetStat(int stat) {
    return m_stat[stat];
}

void Player::IncreaseWins() {
    m_wins++;
}