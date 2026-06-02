#include <iostream>
#include "ParkingLot.h"

using namespace std;

int main(){
    ParkingLot lot(6, 3, 2, 5.0);
    lot.loadState("parking_state.txt"); 

    int choice; 
    int type; 
    string plate;  

    do { 
         cout << "Choose (1-7)" << endl
     << "1. Park" << endl
     << "2. Remove" << endl
     << "3. Status" << endl
     << "4. Search by Plate" << endl
     << "5. View History" << endl
     << "6. Save & Exit" << endl
     << "7. Exit without saving" << endl;
      
        cin>> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input, please enter a number (1-7)" << endl;
            continue;
        } 
    

    if(choice==1){ 
        cout<<"Enter Plate:" <<endl;
        cin>> plate; 

        cout<< "Choose (1-3)" <<endl << "1.Car" << endl << "2.Motorcycle" << endl << "3.Truck" << endl;  
        cin>> type;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input, please enter a number (1-3)" << endl;
            continue;
        }

        Vehicle*v = nullptr; 
        if(type == 1){

            v = new Car(plate); 
        }

        else if(type == 2){

            v = new Motorcycle(plate); 
        
        }

        else if(type == 3){

            v = new Truck(plate); 
        }
        else {
            cout<< "invalid vehicle type."<<endl; 
        
        continue; 
        }

        lot.parkVehicle(v);
    
    }

    else if(choice == 2){

        lot.exitVehicle(); 
    }

    else if(choice == 3){

        lot.displayStatus(); 
    }
    else if(choice == 4){

    string searchPlate;

    cout << "Enter plate to search: ";
    cin >> searchPlate;

    lot.searchVehicle(searchPlate);
    }
 
    else if(choice == 5){

    lot.printHistory();
    }
    else if(choice == 6){

    lot.saveState("parking_state.txt");
    break; 
    }

}
    while(choice != 6 && choice != 7);

    return 0;
}