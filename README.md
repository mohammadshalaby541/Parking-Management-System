# 🚗 Parking Management System (C++)

A console-based Parking Management System implemented in C++ using Object-Oriented Programming (OOP), Data Structures, File Handling, and Templates.

This project simulates a real parking lot where different vehicle types can be parked, searched, removed, and charged parking fees. The system also supports saving/loading parking data and maintaining a history log.

---

## 📌 Features

### Vehicle Management

* Park vehicles
* Remove vehicles
* Search vehicles by plate number
* Prevent duplicate vehicle entries

### Supported Vehicle Types

* Car
* Motorcycle
* Truck

### Parking Lot Operations

* Track available parking slots
* Display current parking status
* Vehicle-specific slot allocation

### Fee Calculation

* Calculates parking fees based on parking duration
* Configurable hourly rate
* Minimum charge of 1 hour

### Logging System

* Records all vehicle entries and exits
* Stores timestamps
* Displays parking history
* Exports logs to CSV format

### Data Persistence

* Save parking lot state to file
* Load previous parking state on startup
* Restore parked vehicles after restarting the program

---

## 🛠️ Concepts Used

This project demonstrates:

* Object-Oriented Programming (OOP)

  * Inheritance
  * Polymorphism
  * Abstract Classes
  * Virtual Functions

* Data Structures

  * Custom Queue Implementation
  * Circular Queue
  * Maps (STL)

* Templates

  * Generic Queue Class

* File Handling

  * Reading from files
  * Writing to files

* Dynamic Memory Allocation

* Exception Handling

* Time and Date Management

---

## 📂 Project Structure

```text
Parking-Management-System/
│
├── main.cpp
│
├── Vehicle.h
├── Vehicle.cpp
│
├── Queue.h
│
├── ParkingLot.h
├── ParkingLot.cpp
│
├── Logger.h
├── Logger.cpp
│
├── parking_state.txt
├── log.csv
│
└── README.md
```

---

## 🚀 Compilation

Using g++:

```bash
g++ main.cpp ParkingLot.cpp Vehicle.cpp Logger.cpp -o parking_system
```

---

## ▶️ Running the Program

### Windows

```bash
parking_system.exe
```

### Linux / macOS

```bash
./parking_system
```

---

## 📋 Menu Options

```text
1. Park Vehicle
2. Remove Vehicle
3. Display Status
4. Search by Plate
5. View History
6. Save & Exit
7. Exit Without Saving
```

---

## 💡 Example Usage

```text
Enter Plate:
ABC123

Choose Vehicle Type:
1. Car
2. Motorcycle
3. Truck

Car vehicle parked successfully.
```

---

## 💾 Generated Files

### parking_state.txt

Stores:

* Remaining parking slots
* Currently parked vehicles

Example:

```text
5,3,2
Car,ABC123
Truck,XYZ789
```

### log.csv

Stores parking history:

```csv
Timestamp,Action,VehicleType,PlateNumber
```

Example:

```csv
Mon Jun 1 10:00:00 2026,PARKED,Car,ABC123
Mon Jun 1 12:00:00 2026,EXITED,Car,ABC123
```

---

## 🔧 Future Improvements

Possible future enhancements:

* Vehicle exit by plate number
* Priority parking
* Multiple parking levels
* Reservation system
* Revenue reports
* Database integration (SQLite/MySQL)
* Graphical User Interface (GUI)
* Admin authentication

---

## 👨‍💻 Author

**Mohammad Shalaby**

First-Year Computer Engineering Student

---

## 🎯 Learning Outcomes

Through this project I practiced:

* C++ Programming
* Object-Oriented Design
* Data Structures & Algorithms
* File Handling
* Software Design Principles
* Git & GitHub Workflow

This project combines OOP, custom data structures, file persistence, logging, and real-world system design concepts, making it a solid portfolio project for internship applications.
