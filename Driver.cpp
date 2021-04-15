
#include "Driver.h"

string Driver::getName() {
    return this->name;
}

bool Driver::getStatus() {
    return this->status;
}

void Driver::setStatus(bool status) {
    this->status = status;
}
