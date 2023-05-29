#include "Track.h"

Track::Track() {
    m_length = 4;
    for (int i = 0; i < NUM_RACERS; i++){
        m_track[i] = 0;
    }
}

void Track::SetLength(int length) {
    m_length = length;
}

void Track::PopulateObstacles() {
    for (int i = 0; i < m_length; i++) {
        m_obstacle[i] = rand() % 3;
    }
}

void Track::GetStatus() {
    for (int i = 0; i < NUM_RACERS; i++) {
        if (i == 0) {
            std::cout << "You are on a " << ConvertObstacle(i);
            std::cout << " obstacle (obstacle " << m_track[i] + 1;
            std::cout << " of " << m_length << ")" << std::endl;
        } else {
            std::cout << "Player " << (i) << " is on a ";
            std::cout << ConvertObstacle(i);
            std::cout << " obstacle in (obstacle " << m_track[i] + 1;
            std::cout << " of " << m_length << ")" << std::endl;
        }
    }
}

int Track::CheckWin() {
    int winner = -1;

    for (int i = 0; i < NUM_RACERS; i++) {
        if (m_track[0] == m_length) {
            winner = 0;
        } else if (m_track[i] == m_length) {
            winner = i;
        }
    }

    return winner;
}

int Track::GetObstacle(int location) {
    return m_obstacle[location];
}

void Track::IncrementLocation(int player) {
    m_track[player] = m_track[player] + 1;
}

void Track::ResetLocation() {
    for (int i = 0; i < NUM_RACERS; i++) {
        m_track[i] = 0;
    }
}

std::string Track::ConvertObstacle(int player) {
    return OBSTACLE_TYPE[m_obstacle[m_track[player]]];
}