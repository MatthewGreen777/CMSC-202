#include "Playlist.h"

Playlist::Playlist() {
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
}

Playlist::~Playlist() {
    Song *curr = m_head;
    while (curr != nullptr) {
        m_head = curr;
        curr = curr->GetNext();
        delete m_head;
    }
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
}

void Playlist::AddSong(std::string title, std::string artist, int year, int rank) {
    m_size++;
    Song *newSong = new Song(title, artist, year, rank);
    Song *current = m_head;
    if (m_head == nullptr) {
        m_head = newSong;
    } else {
        while (current->GetNext() != nullptr) {
            current = current->GetNext();
        }
        current->SetNext(newSong);
    }
}

Song* Playlist::GetPlaylistDetails(int location) {
    Song *temp = m_head;
    for (int i = 0; i < location; i++) {
        temp = temp->GetNext();
    }
    return temp;
}

int Playlist::Size() {
    return m_size;
}

void Playlist::PlayAt(int location) {
    Song *temp = m_head;
    Song *temp2 = nullptr;
    if (temp->GetNext() == nullptr) {
        delete temp;
        m_size--;
    } else if (location == 1) {
        m_head = temp->GetNext();
        delete temp;
        m_size--;
    } else {
        for (int i = 1; i < location; i++) {
            temp2 = temp;
            temp = temp->GetNext();
        }
        temp2->SetNext(temp->GetNext()); 
        delete temp;
        m_size--;
    }
}