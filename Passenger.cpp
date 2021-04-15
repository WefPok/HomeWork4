
#include "Passenger.h"

Passenger::Passenger(string name) {
    this->name = move(name);
}

string Passenger::getName() {
    return name;
}
