#include "Logger.h"
#include <iostream>
#include <fstream>
using namespace std;

void Logger::log(string plate, string type, string action){
    time_t now = time(0);
    string ts = string(ctime(&now));
    ts.pop_back(); 

    LogEntry entry;
    entry.plateNumber = plate;
    entry.vehicleType = type;
    entry.action = action;
    entry.timestamp = ts;

    history.push_back(entry);
}

void Logger::printHistory(){
    if(history.empty()){
        cout << "No history yet." << endl;
        return;
    }
    cout << "\n========== Parking History ==========\n";
    for(auto& e : history){
        cout << "[" << e.timestamp << "] "
             << e.action << " | "
             << e.vehicleType << " | Plate: "
             << e.plateNumber << endl;
    }
}

void Logger::saveToFile(const string& filename){
    ofstream file(filename);
    if(!file.is_open()){
        cout << "Could not open log file." << endl;
        return;
    }
    for(auto& e : history){
        file << e.timestamp << ","
             << e.action << ","
             << e.vehicleType << ","
             << e.plateNumber << "\n";
    }
    file.close();
    cout << "Log saved to " << filename << endl;
}