#include "Race.h"

Race::Race() {

}

void Race::StartRace() {
    int trackLength = 0;
    int choice = 0;

    m_track.ResetLocation();
    std::cout << "How long would you like the race" << std::endl;

    while ((trackLength <= 0) || (trackLength > MAX_LENGTH)) {
        std::cin >> trackLength;
        if (trackLength <= 0) {
            std::cout << "Enter a postivie integer" << std:: endl;
            std::cin.clear();
            std::cin.ignore(256,'\n');
        } else if (trackLength > MAX_LENGTH) {
            std::cout << "Track is to long, enter a shorter length" << std::endl;
            std::cin.clear();
            std::cin.ignore(256,'\n');
        }
    }

    m_myPlayer.SetRaces(m_myPlayer.GetRaces());
    m_track.SetLength(trackLength);
    m_track.PopulateObstacles();

    while(m_track.CheckWin() == -1) {
        choice = RaceOptions();
        if (choice == 1) {
            m_track.GetStatus();
        } else {
            ProgressRace(choice);
        }
    }

    if (m_track.CheckWin() == 0) {
        std::cout << "You won the race" << std::endl;
        m_myPlayer.IncreaseWins();
        m_myPlayer.IncreaseStat();
    } else {
        std::cout << "Player " << m_track.CheckWin() << " won the race!" << std::endl;
    }
}

void Race::GetRacerInfo() {
    std::string name = " ";

    std::cout << "What is your racer's name?" << std::endl;
    std::getline(std::cin, name);

    m_myPlayer.SetName(name);
}

void Race::ProgressRace(int x) {
    int obstacleDifficulty = 1 + (rand() % 100);
    int characterSkill = BASE_SKILL + (5 * m_myPlayer.GetStat(x-1));
    std::cout << m_myPlayer.GetStat(x-1) << std::endl;

    std::cout << "You are trying to progress the race!" << std::endl;

    if (characterSkill >= obstacleDifficulty) {
        std::cout << "You made it throguh the " << m_track.ConvertObstacle(m_track.GetObstacle(0)) << " obstacle!" << std::endl;
        m_track.IncrementLocation(0);
    } else {
        std::cout << "You fell!" <<  std::endl;
        m_myPlayer.SetFalls(m_myPlayer.GetFalls() + 1);
    }

    ProgressComputer(obstacleDifficulty);
}

bool Race::MainMenu() {
    int choice = -1;
    bool reRun;
    bool gate = true;

    std::cout << "What would you like to do?" << std::endl;
    std::cout << "1. Start New Race" << std::endl;
    std::cout << "2. View Racer History" << std::endl;
    std::cout << "3. Quit" << std::endl;

    while (gate) {
        std::cin >> choice;
        if (choice == 1) {
            StartRace();
            gate = false;
            reRun = true;
        } else if (choice == 2) {
            m_myPlayer.DisplayStatus();
            gate = false;
            reRun = true;
        } else if (choice == 3) {
            std::cout << "Thank you for playing UMBC Race!";
            gate = false;
            reRun = false;
        } else {
            std::cout << "Choose one of the options" << std::endl;
            std::cin.clear();
            std::cin.ignore(256,'\n');
        }
    }

    return reRun;
}

int Race::RaceOptions() {
    int choice = 0;

    std::cout << "What would you like to do?" << std::endl;
    std::cout << "1. Get Race Status" << std::endl;
    std::cout << "2. Try to Sprint (Speed)" << std::endl;
    std::cout << "3. Try to Dodge (Agility)" << std::endl;
    std::cout << "4. Try to Jump (Jump)" << std::endl;

    while ((choice <= 0) || (choice > 4)) {
        std::cin >> choice;
        if ((choice <= 0) || (choice > 3)) {
            std::cout << "Pick one of the options" << std::endl;
            std::cin.clear();
            std::cin.ignore(256,'\n');
        }
    }
    return choice;
}

void Race::ManageGame() {
    RaceTitle();
    GetRacerInfo();
    while (MainMenu());
}

void Race::ProgressComputer(int obstacleDifficulty) {
    int computerSkill = 0; 
    for (int i = 1; i < NUM_RACERS; i++) {
        computerSkill = COMP_MIN + (rand() % (COMP_MAX - COMP_MIN + 1));
        if (computerSkill >= obstacleDifficulty) {
            std::cout << "Player " << i << " made it through the " << m_track.ConvertObstacle(m_track.GetObstacle(i)) << " obstacle!" << std::endl;
            m_track.IncrementLocation(i);
        } else {
            std::cout << "Player " << i << " fell!" << std::endl;
        }
    }
}