#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using namespace std;

class Vehicle{
    protected: 
    string plateNumber;
    

    public:

    Vehicle(string plate); 
    string getPlateNumber(); 
    virtual string getType()=0; 
    virtual~Vehicle(); 

};

class Car : public Vehicle {
     
    public:
    Car(string plate);
    
    string getType(); 
};

class Motorcycle : public Vehicle {
    
    public:
    Motorcycle(string plate);

    string getType(); 

};

class Truck : public Vehicle {
    
    public:
    Truck(string plate);

    string getType(); 

};

#endif
