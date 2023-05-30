#include "Process.h"

Process::Process() {
    m_name = "test";
    m_id = -1;
    m_call = -1;
    m_duration = -1;
}

Process::Process(string name, int id, int call, int duration) {
    m_name = name;
    m_id = id;
    m_call = call;
    m_duration = duration;
}

ostream& operator<<(ostream& output, Process& p) {
    output << "Process " << p.m_name << "|" << p.m_id << "|" << p.m_call << "|" << p.m_duration << endl;
    return output;
}