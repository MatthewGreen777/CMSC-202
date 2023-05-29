#include "MusicPlayer.h"

MusicPlayer::MusicPlayer() {
   Playlist *m_playList = new Playlist();
   m_playLists.push_back(m_playList);
   chosenPlayList = 0;
}

MusicPlayer::~MusicPlayer() {
    for (unsigned int i = 0; i < m_songCatalog.size(); i++) {
        delete m_songCatalog.at(i);
        m_songCatalog.at(i) = nullptr;
    }

    for (unsigned int i = 0; i < m_playLists.size(); i++) {
        delete m_playLists.at(i);
        m_playLists.at(i) = nullptr;
    }
}

void MusicPlayer::LoadCatalog(std::string filename) {
    std::string title  = " ";
    std::string artist = " ";
    std::string year = " ";
    std::string rank = " ";

    std::ifstream open(filename);

    while(std::getline(open, title, DELIMITER)) {
        std::getline(open, artist, DELIMITER);
        std::getline(open, year, DELIMITER);
        std::getline(open, rank, '\n');

        Song *newSong = new Song(title, artist, std::stoi(year), std::stoi(rank));
        m_songCatalog.push_back(newSong);
    }
    std::cout << m_songCatalog.size() << std::endl;
}

void MusicPlayer::MainMenu() {
    int choice = 0;
    
    while (choice != 7) {
        std::cout << "What would you like to do?" << std::endl;
        std::cout << "1. Create New Playlist" << std::endl;
        std::cout << "2. Choose Playlist to edit" << std:: endl;
        std::cout << "3. Display Songs by Year" << std::endl;
        std::cout << "4. Add Song" << std::endl;
        std::cout << "5. Display Playlist" << std::endl;
        std::cout << "6. Play Song" << std::endl;
        std::cout << "7. Quit" << std::endl;
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(256, '\n');
            choice = 0;
        }

        switch (choice) {
            case 1:
                CreatePlaylist();
                break;
            case 2:
                ChoosePlaylist();
                break;
            case 3:
                DisplaySongs();
                break;
            case 4:
                AddSong();
                break;
            case 5:
                DisplayPlaylist();
                break;
            case 6:
                PlaySong();
                break;
            case 7:
                std::cout << "Thank you for using the UMBC Music Player" << std::endl;
                break;
            default:
            std::cout << "Choose a number between 1 and 5" << std::endl;
            break;
        }
    }
}

void MusicPlayer::DisplaySongs() {
    int year = 0;
    while ((year < LOW_YEAR) || (year > HIGH_YEAR)) {
        std::cout << "Which year would you like to display? (2010-2021)" << std::endl;
        std::cin >> year;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(256, '\n');
            year = 0;
        }
    }
    std::cout << "*****" << year << "*****" << std::endl;
    for (unsigned int i = 0; i < m_songCatalog.size(); i++) {
        if (m_songCatalog.at(i)->GetYear() == year) {
            std::cout << i+1 << ". " << *m_songCatalog.at(i) << std::endl;
        }
    }
}

void MusicPlayer::AddSong() {
    int song = 0;
    DisplaySongs();
    while((song <= 0) || (song > 1200)) {
        std::cout << "Enter the number of the song you would like to add (1-1200):" << std::endl;
        std::cin >> song;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(256, '\n');
            song = 0;
        }
    }
    m_playLists.at(chosenPlayList)->AddSong(m_songCatalog.at(song-1)->GetTitle(), m_songCatalog.at(song-1)->GetArtist(), m_songCatalog.at(song-1)->GetYear(), m_songCatalog.at(song-1)->GetRank());
}

void MusicPlayer::DisplayPlaylist() {
    if (m_playLists.at(chosenPlayList)->Size() <= 0) {
        std::cout << "Playlist is empty" << std::endl;
    } else {
        for (int i = 0; i < m_playLists.at(chosenPlayList)->Size(); i++) {
            std::cout << i+1 << ". " << *m_playLists.at(chosenPlayList)->GetPlaylistDetails(i) << std::endl;
        }
    }
}

void MusicPlayer::PlaySong() {
    int choice = 0;    
    if (m_playLists.at(chosenPlayList)->Size() <= 0) {
        std::cout << "Playlist is empty" << std::endl;
    } else {
        while ((choice <= 0) || (choice > m_playLists.at(chosenPlayList)->Size())) {
            std::cout << "Your Playlist" << std:: endl;
            DisplayPlaylist();
            std::cout << "Which song would you like to play?" << std::endl;
            std::cin >> choice;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(256,'\n');
                choice = 0;
            }
        }
        std::cout << "Played: " << *m_playLists.at(chosenPlayList)->GetPlaylistDetails(choice-1) << std::endl;
        m_playLists.at(chosenPlayList)->PlayAt(choice);
    }
}

void MusicPlayer::CreatePlaylist() {
    std::string yesOrNo;
    std::string playlistName = "playlist" + m_playLists.size();
    bool gate = true;
    std::cout << "Do you want to create a new playlist: Y or N" << std::endl;
    while (gate) {
        std::cin >> yesOrNo;
        for (int i = 0; i < int(yesOrNo.length()); i++) {
            yesOrNo.at(i) = towlower(yesOrNo.at(i));
        }
        if ((yesOrNo == "y") || (yesOrNo == "yes")) {
            Playlist *playlistName = new Playlist();
            m_playLists.push_back(playlistName);
            gate = false;
            std::cin.ignore(256, '\n');
        } else if ((yesOrNo == "n") || (yesOrNo == "no")) {
            gate = false;
        } else {
            std::cout << "Please enter Y or N" << std::endl;    
            std::cin.clear();
            std::cin.ignore(256, '\n');
        }
    }
}

void MusicPlayer::ChoosePlaylist() {
    if (m_playLists.size() <= 1) {
        std::cout << "There is only one playlist" << std::endl;
        chosenPlayList = 0;
    } else {
        std::cout <<"There are " << m_playLists.size() << " playlists" << std::endl;
        std::cout << "Which playlist would you like to choose?" << std::endl;
        do {
            std::cin >> chosenPlayList;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(256, '\n');
                chosenPlayList = -1;
            } else {
                chosenPlayList = chosenPlayList - 1;
            }
        } while ((chosenPlayList < 0) || (chosenPlayList > m_playLists.size()));
    }
    std::cout << "Editing playlist " << chosenPlayList + 1 << std::endl;
}