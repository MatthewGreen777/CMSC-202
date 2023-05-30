#include "Processor.h"

Processor::Processor(string filename) {
    m_fileName = filename;
}

Processor::~Processor() {
    for (unsigned long int i = 0; i < m_processes.size(); i++) {
        delete m_processes.at(i);
        m_processes.at(i) = nullptr;
    }    
    
    for (unsigned int i = 0; i < m_threads.size(); i++) {
        while (m_threads.at(i)->GetSize() > 0) {
            m_threads.at(i)->Pop();
        }
    }

    for (unsigned long int i = 0; i < m_threads.size(); i++) {
        delete m_threads.at(i);
        m_threads.at(i) = nullptr;
    }
}

void Processor::InitializeProcessor() {
    DisplayTitle();
    if (LoadProcesses(m_fileName)) {
        //DisplayProcesses();
        PopulateThreads();
        MainMenu();
    }
    cout << "Thank you trying UMBC Processor!" << endl;
}

bool Processor::LoadProcesses(string filename) {
    bool read = false;
    string name = " ";
    string id = " ";
    string call_id = " ";
    string duration = " ";
    ifstream open(filename);
    while (getline(open, name, DELIMITER)) {
        getline(open, id, DELIMITER);
        getline(open, call_id, DELIMITER);
        getline(open, duration, '\n');
        Process *newProcess = new Process(name, stoi(id), stoi(call_id), stoi(duration));
        AddThread(newProcess);
        m_processes.push_back(newProcess);

        read = true;
    }
    open.close();
    return read;
}

void Processor::AddThread(Process* p) {
    if (m_threads.size() < NUM_THREADS) {
        Lstack<Process*> *newThread = new Lstack<Process*>();
        newThread->Push(p);
        m_threads.push_back(newThread);
    }
}

int Processor::GetProcessCalled(int id) {
    int location = -1;
    for (unsigned int i = 0; i < m_processes.size(); i++) {
        if (id == m_processes.at(i)->m_id) {
            location = i;
        }
    }
    return location;
}

void Processor::PopulateThreads() {
    int one = 0;
    int two = 0;
    for (unsigned int i = 0; i < m_threads.size(); i++) {
        one = m_threads.at(i)->At(0)->m_call;
        two = one;
        while (two != -1) {
            one = GetProcessCalled(one);
            m_threads.at(i)->Push(m_processes.at(one));
            one = m_threads.at(i)->Top()->m_call;
            two = one;
        }   
    }
}

void Processor::MainMenu() {
    int choice = 0;
    bool loop = true;
    while (loop) {
        cout << "Choose an option" << endl;
        cout << "1. Display THreads" << endl;
        cout << "2. Start Thread" << endl;
        cout << "3. Quit" << endl;
        cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(256, '\n');
            choice = 0;
        }
        switch (choice) {
            case 1:
                DisplayThread();
                break;
            case 2:
                StartThreads();
                break;
            case 3:
                cout << "Thank you for trying UMBC Processor!" << endl;
                loop = false;
                break;
            default:
                cout << "Please enter a valid option" << endl;
            break;
        }
    }
}

void Processor::DisplayProcesses() {
    for (unsigned long int i = 0; i < m_processes.size(); i++) {
        cout << m_processes.at(i)->m_name << "|" << m_processes.at(i)->m_id << "|" << m_processes.at(i)->m_call << "|" << m_processes.at(i)->m_duration << endl;
    }
}

void Processor::ListThreads() {
    for (unsigned long int i = 0; i < m_threads.size(); i++) {
        cout << (i+1) << ". Thread " << (i+1) << "(" << m_threads.at(i)->GetSize() << " processes)" << endl;
    }
}

int Processor::ChooseThread() {
    unsigned long int choice = 0;
    cout << "What thread would you to view?" << endl;
    ListThreads();
    do {
        cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(256, '\n');
            choice = 0;
        }
        if ((choice <= 0) || (choice > m_threads.size())) {
            cout << "Choose a valid thread" << endl;
        }
    } while ((choice <= 0) || (choice > m_threads.size()));
    return choice-1;
}

void Processor::DisplayThread() {
    int thread = ChooseThread();
    for (int i = 0; i < m_threads.at(thread)->GetSize(); i++) {
        cout << m_threads.at(thread)->At(i)->m_name << "|" << m_threads.at(thread)->At(i)->m_id << "|" << m_threads.at(thread)->At(i)->m_call << "|" << m_threads.at(thread)->At(i)->m_duration << endl;
    }
}

void Processor::StartThreads() {
    int time = 0;
    for (unsigned int i = 0; i < m_threads.size(); i++) {
        while (m_threads.at(i)->GetSize() > 0) {
            time = time + m_threads.at(i)->Top()->m_duration;
            m_threads.at(i)->Pop();
        }
        cout << "Thread " << (i+1) << " took " << time << " milliseconds to complete" << endl;
        time = 0;
    }
}

void Processor::DisplayTitle() {
    cout << "Welcome to UMBC Processor!" << endl;
}