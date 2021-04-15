
#ifndef HW4_NoskovNikita_DRIVER_H
#define HW4_NoskovNikita_DRIVER_H

#include <string>
#include <utility>
#include "Car.h"

using namespace std;

class Driver {
public:
    Car car;
    explicit Driver(string name, Car car) {
        this->name = move(name);
        this->car = move(car);
    }
    string getName();
    bool getStatus();
    void setStatus(bool status);
private:
    string name;
    bool status =  false;
};


#endif
