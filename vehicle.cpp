#include "Vehicle.h"
#include <iostream>

using namespace std;

Vehicle ::Vehicle(string plate) {
    plateNumber = plate;
}

string Vehicle::getPlateNumber(){
    return plateNumber;
}

Vehicle::~Vehicle(){}
//virtual destructor

Car::Car(string plate) : Vehicle(plate){}

string Car::getType(){
    return "Car";
    
}

Motorcycle::Motorcycle(string plate) : Vehicle(plate){}

string Motorcycle::getType(){
    return "Motorcycle";
    
}

Truck::Truck(string plate) : Vehicle(plate){}

string Truck::getType(){
    return "Truck";
    
}
