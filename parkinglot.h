#ifndef ParkingLot_H
#define ParkingLot_H

#include "queue.h" 
#include "vehicle.h" 
#include "Logger.h"
#include <map>
#include <ctime>
#include <fstream>

class ParkingLot{
    private:
    QueueArr<Vehicle*> vehicleQueue; 
    Logger logger;
    map<string, time_t> entryTimes;   
    double hourlyRate;                 

    int carSlots; 
    int motorcycleSlots; 
    int truckSlots; 

    public:
    ParkingLot(int car, int motorcycle, int truck, double rate = 5.0); 

    void parkVehicle(Vehicle*v); 
    void exitVehicle(); 
    void displayStatus(); 
    void searchVehicle(const string& plate);
    double calculateFee(const string& plate);
    void printHistory();
    void saveState(const string& filename);
    void loadState(const string& filename);


};

#endif
