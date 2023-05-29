#include "Song.h"

Song::Song() {
    SetTitle("New Title");
    SetArtist("New Artist");
    SetYear(0);
    SetRank(0);
    m_next = nullptr;
}

Song::Song(std::string title, std::string artist, int year, int rank) {
    SetTitle(title);
    SetArtist(artist);
    SetYear(year);
    SetRank(rank);
    m_next = nullptr;
}

std::string Song::GetTitle() {
    return m_title;
}

std::string Song::GetArtist() {
    return m_artist;
}

int Song::GetYear() {
    return m_year;
}

int Song::GetRank() {
    return m_rank;
}

void Song::SetTitle(std::string title) {
    m_title = title;
}

void Song::SetArtist(std::string artist) {
    m_artist = artist;
}

void Song::SetYear(int year) {
    m_year = year;
}

void Song::SetRank(int rank) {
    m_rank = rank;
}

Song* Song::GetNext() {
    return m_next;
}

void Song::SetNext(Song* nextSong) {
    m_next = nextSong;
}