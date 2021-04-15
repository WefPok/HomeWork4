
#ifndef HW4_NoskovNikita_CAR_H
#define HW4_NoskovNikita_CAR_H

#include <string>
#include <utility>
#include <iostream>
#include "Passenger.h"

using namespace std;

class Car {
public:
    int carType;

    enum Colors {
        YELLOW = 1,
        BLACK,
        WHITE,
        GRAY,
        RED,
        PINK
    };

    enum CarType {
        Economy = 1,
        Comfort,
        ComfortPlus,
        Business
    };

    Car(string model, string number, Colors color, CarType carType, string current_coordinates);
    Car();

    string getModel();
    string getCarType();
    string getNumber();
    string getColor();
    string getCurrentCoordinates() { return current_coordinates; }
private:
    string model;
    string number;
    int color;
    string current_coordinates;
};

class EconomyCar: public Car {
public:
    EconomyCar(string model, string number, Colors color, string current_coordinates)
            :Car(move(model), move(number), color, Car::Economy, move(current_coordinates)){}
};

class ComfortCar: public Car {
public:
    int freeBottleOfwater = 0;

    ComfortCar(string model, string number, Colors color, string current_coordinates)
            :Car(move(model), move(number), color, Car::Comfort, move(current_coordinates)){}

    void BuyBottlesOfWater(int count) { freeBottleOfwater = freeBottleOfwater + count; }

    bool takeBottleOfWater(Passenger passenger) {
        if(freeBottleOfwater > 0) {
            freeBottleOfwater--;
            cout << "Driver give bottle of water to the passenger!" << endl;
        } else {
            cout << "Bottles of water ran out!" << endl;
        }
    }
};

class ComfortPlusCar: public Car {
public:
    int freeBottleOfwater = 0;
    ComfortPlusCar(string model, string number, Colors color, string current_coordinates)
            :Car(move(model), move(number), color, Car::ComfortPlus, move(current_coordinates)){}
    void BuyBottlesOfWater(int count) { freeBottleOfwater = freeBottleOfwater + count; }

    bool takeBottleOfWater(Passenger passenger) {
        if(freeBottleOfwater > 0) {
            freeBottleOfwater--;
            cout << "Driver give bottle of water to the passenger!" << endl;
        } else {
            cout << "Bottles of water ran out!" << endl;
        }
    }
};

class BusinessCar: public Car {
public:
    BusinessCar(string model, string number, Colors color, string current_coordinates)
            :Car(move(model), move(number), color, Car::Business, move(current_coordinates)){}

    void parkRightInFrontOfTheEntrance(Passenger passenger) {

    }
};

#endif