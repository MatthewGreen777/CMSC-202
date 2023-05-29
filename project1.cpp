/********************************************************************
 * File: project1.cpp
 * Author: Matthew Green
 * E-mail: mgreen11@.umbc.edu
 *********************************************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function Prototypes
int checkHash(string hashtag[], string message); //function to check if the hashtag matches
bool emptyHash(string file); // function to check if the hashtag file is empty
bool emptyMessage(string file); // function to check if the message file is empty
bool reRun(); // function to ask user if they want to rerun program
void clearBuffer(); // function to clear the cin buffer
void fileReader(); // function to open and read from file
void fileReader2(string array[]);
void results(string hashtags[], string messages[], int tracker[], int numMessage);

// Constants
const int HASHTAGS = 20;

int main() {
    cout << "Welcome to the Hashtag Analyzer" << endl;
    cout << "You will choose a file of hashtages to search for" << endl;
    cout << "Then you will choose a file to search for the hashtags" << endl;
    do {
        fileReader();
    } while (reRun());
    cout << "Thank you for using the hashtag analyzer!" << endl;
}

int checkHash(string hashtag[], string message) {
    int location = -1;

    for (int i = 0; i < HASHTAGS; i++) {
        if (message.find(hashtag[i]) != string::npos) {
            location = i;
        }
    }

    return location;
}

bool emptyHash(string file) {
    string word = " ";
    int length = 0;
    bool empty;
    ifstream openFile(file);
    while (openFile >> word) {
        if (word.at(0) != '#') {
            length = 0;
        } else {
            for (int i = 0; i < int(word.length()); i++) {
                if (word[i] != ' ') {
                    length++;
                } 
            }

        }
    }
    openFile.close();
    if (length == 0) {
        empty = true;
    } else {
        empty = false;
    }
    return empty;
}

bool emptyMessage(string file) {
    string hashtag = " ";
    string message = " ";
    int length = 0;
    bool empty;
    ifstream openFile(file);
    while (openFile >> hashtag >> message) {
        for (int i = 0; i < int(message.length()); i++) {
            if (message[i] != ' ') {
                length++;
            } 
        }
    }

    openFile.close();
    if (length == 0) {
        empty = true;
    } else {
        empty = false;
    }
    return empty;
}

bool reRun() {
    string yesOrNo = " ";
    bool reRun = true;
    bool gate = true;
    cout << "Would you like to analyze another file?" << endl;
    while (gate) {
        cin >> yesOrNo;
        for (int i = 0; i < int(yesOrNo.length()); i++) {
            yesOrNo.at(i) = towlower(yesOrNo.at(i));
        }
        if ((yesOrNo == "y") || (yesOrNo == "yes")) {
            reRun = true;
            gate = false;
            cin.ignore(256, '\n');
        } else if ((yesOrNo == "n") || (yesOrNo == "no")) {
            reRun = false;
            gate = false;
        } else {
            cout << "Please enter Y or N" << endl;
            clearBuffer();
        }
    }
    return reRun;
}

void clearBuffer() {
    cin.clear();
    cin.ignore(256, '\n');
}

void fileReader() {
    string fileName = " ";
    string hashtag = " ";
    string hashtags[HASHTAGS] = {};
    int numHash = 0;
    cout << "Please enter the file with the hashtags you would like to use:" << endl;
    cin >> fileName;
    ifstream openFile(fileName);

    do {
        if (!(openFile.is_open()) || emptyHash(fileName)) {
            cout << "This file does not exist, is empty, or does not contain only hashtags" << endl;
        } else {
            cout << "Your file was imported!" << endl;
            while ((openFile>> hashtag) && (numHash < HASHTAGS)) {
                hashtags[numHash] = hashtag;
                numHash++;
            }

            cout << numHash << " hashtags loaded" << endl;
            fileReader2(hashtags);
        }
        openFile.close();
    } while(openFile.is_open());

    for (int i = 0; i < numHash; i++) {
        hashtags[i] = " ";
    }
}

void fileReader2(string hashtags[]) {
    string fileName = " ";
    string hashtag = " ";
    string message = " ";
    string totalMessage = " ";
    string messages[HASHTAGS] = {};
    string messageMatch[HASHTAGS] = {};
    int numMessage = 0;
    int numMessageMatch = 0;
    int tracker[HASHTAGS] = {};

    cout << "Please enter the file with the messages you would like to parse:" << endl;
    cin >> fileName;
    ifstream openFile(fileName);

    do {
        if (!(openFile.is_open()) || emptyMessage(fileName)) {
            cout << "This file does not exist or is empty" << endl;
        } else {
            cout << "Your file was imported!" << endl;
            while ((getline(openFile, hashtag)) && (getline(openFile, message))) {
                totalMessage = hashtag + " " + message;
                messages[numMessage] = totalMessage;
                numMessage++;
            }

            cout << numMessage << " messages loaded" << endl;

            for (int i = 0; i <= numMessage; i++) {
                int location = checkHash(hashtags, messages[i]);
                if (location >= 0) {
                    messageMatch[numMessageMatch] = messages[i];
                    tracker[location] = tracker[location] + 1;
                    numMessageMatch++;
                }
            }
            
            results(hashtags, messageMatch, tracker, numMessageMatch);
        }
        openFile.close();
    } while (openFile.is_open());
    for (int i =0; i < numMessage; i++) {
        messages[i] = " ";
        messageMatch[i] = " ";
        tracker[i] = 0;
    }
}

void results(string hashtags[], string messagesMatch[], int tracker[], int numMessageMatch) {
    cout << "Messges with matching hashtags:" << endl;
    for (int i = 0; i < numMessageMatch; i++) {
        cout << (i+1) << ". " << messagesMatch[i] << endl;
    }
        cout << endl << endl << endl;
    for (int i = 0; i < HASHTAGS; i++) {
        cout << (i+1) << ". " << hashtags[i] << " " << tracker[i] << endl;
    }
}