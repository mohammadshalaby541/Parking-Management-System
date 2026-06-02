#include <iostream>
#include "parkinglot.h"

using namespace std;

ParkingLot ::ParkingLot(int car, int motorcycle, int truck, double rate) : vehicleQueue(car + motorcycle + truck) {

    carSlots = car;
    motorcycleSlots = motorcycle;
    truckSlots = truck;
    hourlyRate = rate;

}

void ParkingLot::parkVehicle(Vehicle* v){
    
    if(vehicleQueue.full()){
        cout<<"Parking is Full!"<<endl;
        delete v; 
        return;
    }

    
    if(v->getType() == "Car"){
        if(carSlots == 0){
            cout<<"No Car slots available!"<<endl;
            delete v;
            return;
        }
    }
    else if(v->getType() == "Motorcycle"){
        if(motorcycleSlots == 0){
            cout<<"No Motorcycle slots available!"<<endl;
            delete v;
            return;
        }
    }
    else if(v->getType() == "Truck"){
        if(truckSlots == 0){
            cout<<"No Truck slots available!"<<endl;
            delete v;
            return;
        }
    }
     
    int count = vehicleQueue.showSize();
    QueueArr<Vehicle*> tempQueue(count + 1); 

    bool duplicate = false;

    for(int i=0; i<count; i++){
        Vehicle* temp = vehicleQueue.Front(); 
        vehicleQueue.dequeue();

        if(temp->getPlateNumber() == v->getPlateNumber()){ 
            duplicate = true; 
        }
        tempQueue.enqueue(temp); 
    }

    for(int i=0; i<count; i++){
        vehicleQueue.enqueue(tempQueue.Front()); 
        tempQueue.dequeue();
    }

    if(duplicate){
        cout<<"Duplicate vehicle!"<<endl;
        delete v;
        return;
    }
    
    if(v->getType() == "Car") carSlots--;
    else if(v->getType() == "Motorcycle") motorcycleSlots--;
    else if(v->getType() == "Truck") truckSlots--;

    vehicleQueue.enqueue(v); 
    entryTimes[v->getPlateNumber()] = time(0);
    logger.log(v->getPlateNumber(), v->getType(), "PARKED");
    cout<< v->getType() << " vehicle parked successfully."<<endl;
}

void ParkingLot :: exitVehicle(){

        if(vehicleQueue.empty()){
            cout<< "No Vehicles to remove!"<<endl;  
            return;
        }

        Vehicle* v = vehicleQueue.Front(); 
        vehicleQueue.dequeue();
        
        if(v->getType() =="Car") 
        carSlots++;

        else if (v->getType() == "Motorcycle")
        motorcycleSlots++;

        else if (v->getType() == "Truck")
        truckSlots++;

        cout<< v->getType() << "  with the following plate :"<< v->getPlateNumber() << "  exited."<<endl;

        double fee = calculateFee(v->getPlateNumber());
        cout << "Fee charged: $" << fee << endl;
        logger.log(v->getPlateNumber(), v->getType(), "EXITED");
        entryTimes.erase(v->getPlateNumber());

        delete v;

    }

void ParkingLot :: displayStatus(){

        cout<< "\n==========Parking Status==========\n";
        cout<< "Car slots available: " << carSlots <<endl;
        cout<< "Motorcycle slots available: " << motorcycleSlots <<endl;
        cout<< "Truck slots available: " << truckSlots <<endl;
        cout<< "Total Parked Vehicles: " << vehicleQueue.showSize() <<endl;

    }


double ParkingLot::calculateFee(const string& plate){
    if(entryTimes.find(plate) == entryTimes.end()) return 0.0;
    time_t now = time(0);
    double seconds = difftime(now, entryTimes[plate]);
    double hours = seconds / 3600.0;
    if(hours < 1.0) hours = 1.0; // minimum 1 hour charge
    return hours * hourlyRate;
}

void ParkingLot::searchVehicle(const string& plate){
    int count = vehicleQueue.showSize();
    QueueArr<Vehicle*> temp(count + 1);
    bool found = false;

    for(int i = 0; i < count; i++){
        Vehicle* v = vehicleQueue.Front();
        vehicleQueue.dequeue();
        if(v->getPlateNumber() == plate){
            cout << "Found: " << v->getType()
                 << " | Plate: " << v->getPlateNumber() << endl;
            found = true;
        }
        temp.enqueue(v);
    }
    for(int i = 0; i < count; i++){
        vehicleQueue.enqueue(temp.Front());
        temp.dequeue();
    }
    if(!found) cout << "No vehicle with plate " << plate << " found." << endl;
}

void ParkingLot::printHistory(){
    logger.printHistory();
}

void ParkingLot::saveState(const string& filename){
    ofstream file(filename);
    if(!file.is_open()){
        cout << "Could not save state." << endl;
        return;
    }
    // save slot counts
    file << carSlots << "," << motorcycleSlots << "," << truckSlots << "\n";

    // save each parked vehicle
    int count = vehicleQueue.showSize();
    QueueArr<Vehicle*> temp(count + 1);

    for(int i = 0; i < count; i++){
        Vehicle* v = vehicleQueue.Front();
        vehicleQueue.dequeue();
        file << v->getType() << "," << v->getPlateNumber() << "\n";
        temp.enqueue(v);
    }
    for(int i = 0; i < count; i++){
        vehicleQueue.enqueue(temp.Front());
        temp.dequeue();
    }
    file.close();
    logger.saveToFile("log.csv");
    cout << "State saved to " << filename << endl;
}

void ParkingLot::loadState(const string& filename){
    ifstream file(filename);
    if(!file.is_open()){
        cout << "No saved state found, starting fresh." << endl;
        return;
    }
    string line;
    
    if(getline(file, line)){
        int c, m, t;
        sscanf(line.c_str(), "%d,%d,%d", &c, &m, &t);
        carSlots = c;
        motorcycleSlots = m;
        truckSlots = t;
    }
    
    while(getline(file, line)){
        string type = line.substr(0, line.find(','));
        string plate = line.substr(line.find(',') + 1);
        Vehicle* v = nullptr;
        if(type == "Car")        v = new Car(plate);
        else if(type == "Motorcycle") v = new Motorcycle(plate);
        else if(type == "Truck") v = new Truck(plate);
        if(v){
            vehicleQueue.enqueue(v);
            entryTimes[plate] = time(0); 
        }
    }
    file.close();
    cout << "State loaded from " << filename << endl;
}
