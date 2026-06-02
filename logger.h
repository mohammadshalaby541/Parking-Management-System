#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <vector>
#include <ctime>
using namespace std;

struct LogEntry {
    string plateNumber;
    string vehicleType;
    string action;      
    string timestamp;
};

class Logger {
    private:
    vector<LogEntry> history;

    public:
    void log(string plate, string type, string action);
    void printHistory();
    void saveToFile(const string& filename);
};

#endif