#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <ctime>

// constants
const int MAX_STAT = 10; //Maximum of any player stat
const int START_STAT = 1; //Starting value of all stats
const int NUM_STATS = 3; //Number of stats for game (speed, agility, jump)

// class - do not add any functions to project 2
class Player{
 public:
  // Name: Player() - Default Constructor
  // Desc: Used to build a new Player
  // Preconditions - Requires default values
  // Postconditions - Creates new Player (with default name of "Beannie" with 1 speed/agility/jump
  Player();
  // Name: Player(name) - Overloaded constructor
  // Desc - Used to build a new Player
  // Preconditions - Requires name
  // Postconditions - Creates a new Player (with passed name and 1 speed/agility/jump)
  // May not be used in the project explicitly but please implement
  Player(std::string name);
  // Name: GetName()
  // Desc - Getter for Player name
  // Preconditions - Player exists
  // Postconditions - Returns the name of the Player
  std::string GetName();
  // Name: SetName(string)
  // Desc - Allows the user to change the name of the Player
  // Preconditions - Player exists
  // Postconditions - Sets name of Player
  void SetName(std::string name);
  // Name: GetSpeed
  // Desc - Gets the speed from this player
  // Preconditions - Player has a speed assigned
  // Postconditions - Returns the speed of the player
  int GetSpeed();
  // Name: GetAgility
  // Desc - Gets the agility from this player
  // Preconditions - Player has a agility assigned
  // Postconditions - Returns the agility of the player
  int GetAgility();
  // Name: GetJump
  // Desc - Gets the jump from this player
  // Preconditions - Player has a jump assigned
  // Postconditions - Returns the jump of the player
  int GetJump();
  // Name: GetRaces
  // Desc - Gets the total number of races the player has run
  // Preconditions - Player has a races assigned
  // Postconditions - Returns the total number of races run
  int GetRaces();
  // Name: GetFalls
  // Desc - Gets the total number of falls for the player
  // Preconditions - None
  // Postconditions - Returns the total falls for the player
  int GetFalls();
  // Name: SetRaces
  // Desc - Sets the total number of races the player has run
  // Preconditions - None
  // Postconditions - Sets total number of races run
  void SetRaces(int races);
  // Name: SetFalls
  // Desc - Sets the total number of falls for the player
  // Preconditions - None
  // Postconditions - Sets the total falls for the player
  void SetFalls(int falls);
  // Name: DisplayStatus
  // Desc - Displays the player names and their stats
  // Precondition - None
  // Postconditions - Displays the player information
  void DisplayStatus();
  // Name: IncreaseStat
  // Desc - Asks the user for a stat to increase (speed, agility, or jump) up to a max of 10
  // Precondition - Called after winning a race
  // Postconditions - Increases one stat by one point (max 10)
  void IncreaseStat();
  // Name: GetStat
  // Desc - Returns the value of a stat at a specific location (0 = speed, 1 = agility, 2 = jump)
  // Precondition - None
  // Postconditions - Returns the integer value of a specific stat
  int GetStat(int stat);
  // Name: IncreaseWins
  // Desc - Increases the number of wins by 1
  // Precondition - None
  // Postconditions - Increases the number of wins by 1
  void IncreaseWins();
private:
  std::string m_name; //Name of Player
  int m_stat[3]; //Stats of player: 0 = speed, 1 = agility, 2 = jump
  int m_races; //Starts at 0
  int m_wins; //Starts at 0
  int m_falls; //Starts at 0
};

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
    short input = -1;
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

//Constants
const int NUM_RACERS = 4; //Default number of players (1 human and 3 computer)
const int DEFAULT_LENGTH = 4; //Default starting length of a race
const int MAX_LENGTH = 100; //Maximum length of a race
const std::string OBSTACLE_TYPE[3] = {"speed", "agility", "jump"}; //Word descriptions of the three types of obstacles

// class - do not add any functions to project 2
class Track{
 public:
  // Name: Track() - Default Constructor
  // Desc: Used to build a new Track with default length 4
  // Sets track so that all players start in position 0
  // Preconditions - Requires default values
  // Postconditions - Creates new Track with a default length 4 and each m_track = 0
  Track();
  // Name: SetLength
  // Desc - Sets the length of the track
  // Preconditions - Requires length
  // Postconditions - Sets the length of the track
  void SetLength(int length);
  // Name: PopulatsObstacles()
  // Desc - For each length of track, assigns random type of obstacle (speed, agility, jump)
  //        Uses integers (0 = speed, 1 = agility, 2 = jump)
  // Preconditions - Track exists
  // Postconditions - Populates m_obstacle with random number between 0 and 2
  void PopulateObstacles();
  // Name: GetStatus()
  // Desc - Returns the status of race
  // Preconditions - Track exists
  // Postconditions - Outputs where each racer is in track and the type of obstacle
  void GetStatus();
  // Name: CheckWin()
  // Desc - Checks to see if the race is over by comparing each racer's
  //        location to the length of the track.
  //        Returns number of player who wins race (always starts at 0 first)
  // Preconditions - Track exists
  // Postconditions - Returns integer location of winner (0 is human). Always returns human in case of tie!
  int CheckWin();
  // Name: GetObstacle
  // Desc - Returns the integer of the obstacle at a specific location
  // Preconditions - Track exists
  // Postconditions - Returns 0 for speed, 1 for agility, and 2 for jump
  int GetObstacle(int location);
  // Name: IncrementLocation
  // Desc - Increments the m_track value for a specific player the human player
  //        is always in position 0
  // Preconditions - Race starts with everyone having a 0
  // Postconditions - Increases the integer value for a specific player
  void IncrementLocation(int player);
  // Name: ResetLocation
  // Desc - Before each race, resets the starting location for all players back to 0
  // Preconditions - Track exists
  // Postconditions - All players has a starting location of 0 in the m_track
  void ResetLocation();
  // Name: ConvertObstacle
  // Desc - Returns the string name of the obstacle using the OBSTACLE_TYPE
  //        array for a specific player
  // Preconditions - Player exists in m_track
  // Postconditions - Pulls the location from m_track for a provided player
  //                  then returns the obstacle at that location
  std::string ConvertObstacle(int player);
private:
  int m_track[NUM_RACERS]; //Location of each racer on track
  int m_length; //Length of track
  int m_obstacle[MAX_LENGTH]; //Type of obstacle in part of track (0=speed, 1=agility, 2=jump)
};

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
        if (m_track[0] == m_length ) {
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

//Constants (no additional constants allowed - use local constants if needed)
const int COMP_MAX = 100; //Maximum number for a computer based player (used to randomly choose a number between 40 - 100 to see if succesfully get passed obstacle)
const int COMP_MIN = 40; //Minimum number for computer based player (used to randomly choose a number between 40 - 100 to see if succesfully get passed obstacle)
const int BASE_SKILL = 50; //Player's base chance of getting through obstacle
const int BASE_DIFFICULTY = 100; //Max value of the difficulty of an obstacle. At 100, this would be a random number between 1 and 100.

//No additional functions allowed

class Race{
public:
  // Name: Race() Default Constructor
  // Desc - Instantiates an object of type Race. Does nothing.
  // Preconditions - None
  // Postconditions - None
  Race(); //Default Constructor
  // Name: StartRace()
  // 1. Resets length of race
  // 2. Increments the number of races for the player
  // 3. Sets up track (user chooses length of track) and populates obstacles
  // 4. Calls RaceOptions and calls GetStatus or calls ProgressRace (passes the user's choice)
  // 5. Checks to see if someone won (their location exceeds the length of the race)
  // 6. Displays the winner of race. If human player wins, increases a stat and increases wins 
  // Preconditions - Race conditions set up
  // Postconditions - Race completed
  void StartRace();
  // Name: GetRacerInfo()
  // Desc - Gets the racer's name and populates the racer's name
  // Preconditions - Populates m_name in Racer
  // Postconditions - m_name is populated
  void GetRacerInfo();
  // Name: ProgressRace()
  // Desc - Does the following:
  // 1. Deals with the human player first.
  // 2. Randomly assigns (1 - 100) difficlty to all obstacles (regardless of location,
  //    all players have the same level difficulty for each round)
  // 3. Compares the BASE_SKILL + (5 * stat) to the obstacle difficulty to see if successfully
  //    navigated. Indicates if successful and increments location. If not successful,
  //    falls and increments falls
  // 4. Calls ProgressComputer to deal with computer
  // Preconditions - Player in race
  // Postconditions - Each racer either progresses to the next obstacle, or falls
  void ProgressRace(int);
  // Name: MainMenu()
  // Desc - Displays and manages menu
  // Preconditions - None
  // Postconditions - Returns number including exit
  bool MainMenu();
  // Name: RaceOptions()
  // Desc - Displays the race menu (display status, choose speed, choose agility, or choose jump)
  // Preconditions - None
  // Postconditions - Returns integer of user choice (status = 1, speed = 2, agility = 3, jump = 4)
  int RaceOptions();
  // Name: ManageGame
  // Desc - Calls RaceTitle, then calls GetRacerInfo. Continually calls MainMenu
  //        until the user chooses quit then it thanks the user and quits
  // Preconditions - Game instantiated
  // Postconditions - Calls RaceTitle, then calls GetRacerInfo. Continually calls MainMenu
  //                  until the user chooses quit then it thanks the user and quits
  void ManageGame();
  // Name: ProgressComputer
  // Desc - Iterates over each computer player (players 2, 3, and 4) to see if they
  //        successfully navigate through an obstacle. Indicates if they make it or fall.
  //        Compares a random number between COMP_MIN and COMP_MAX to the obstacle difficulty
  //        to see if they are successful
  // Preconditions - obstacleDifficulty is already calculated and passed to this function
  // Postconditions - For each computer player, they either make it and increment their
  //                  location or fall and remain on the same obstacle
  void ProgressComputer(int obstacleDifficulty);
  // Name: RaceTitle()
  // Desc - Title for Race (Do not edit)
  // Preconditions - None
  // Postconditions - None
  void RaceTitle(){
    std::cout << "*****************************************************************" << std::endl;
    std::cout << "U   U   M   M   BBB   CCCC   RRR     AA    CCCC   EEEE   RRR     " << std::endl;
    std::cout << "U   U   MM MM   B  B  C      R  R   A  A   C      E      R  R    " << std::endl;
    std::cout << "U   U   M M M   BBBB  C      RRR    AAAA   C      EEEE   RRR     " << std::endl;
    std::cout << "U   U   M   M   B  B  C      R R    A  A   C      E      R R     " << std::endl;
    std::cout << "UUUUU   M   M   BBB   CCCC   R  R   A  A   CCCC   EEEE   R  R    " << std::endl;
    std::cout << "*****************************************************************" << std::endl;
  }
private:
  Player m_myPlayer; //Player information for game
  Track m_track; //Track for race
};

Race::Race() {

}

void Race::StartRace() {
    int trackLength = 0;
    int choice = 0;
    int win = 0;
    
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

    while((win = m_track.CheckWin()) == -1) {
        choice = RaceOptions();
        if (choice == 1) {
            m_track.GetStatus();
        } else {
            ProgressRace(choice);
        }
    }

    if (win == 0) {
        std::cout << "You won the race" << std::endl;
        m_myPlayer.IncreaseWins();
        m_myPlayer.IncreaseStat();
    } else {
        std::cout << "Player " << win << " won the race!" << std::endl;
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

    std::cout << "You are trying to progress the race!" << std::endl;

    if (characterSkill >= obstacleDifficulty) {
        std::cout << "You made it throguh the ";
        std::cout << m_track.ConvertObstacle(m_track.GetObstacle(0));
        std::cout << " obstacle!" << std::endl;
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
            std::cout << "Player " << i << " made it through the " << m_track.ConvertObstacle(i) << " obstacle!" << std::endl;
            m_track.IncrementLocation(i);
        } else {
            std::cout << "Player " << i << " fell!" << std::endl;
        }
    }
}

int main () {
  srand(time(NULL)); //Seeds the random number generator (Do NOT seed again)
  Race newRace; //Creates a new instance of the game
  newRace.ManageGame(); //Starts the game
  return 0;
}