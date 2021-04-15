
#include "Car.h"

#include <utility>

Car::Car(string model, string number, Car::Colors color, Car::CarType carType, string current_coordinates) {
    this->model = std::move(model);
    this->number = std::move(number);
    this->color = color;
    this->carType = carType;
    this->current_coordinates = std::move(current_coordinates);
}

Car::Car() {}

string Car::getCarType() {
    switch (carType) {
        case 1: return "Economy";
        case 2: return "Comfort";
        case 3: return "Comfort Plus";
        case 4: return "Business";
    }
}

string Car::getModel() {
    return model;
}

string Car::getNumber() {
    return number;
}

string Car::getColor() {
    switch (color) {
        case 1: return "Yellow";
        case 2: return "Black";
        case 3: return "White";
        case 4: return "Gray";
        case 5: return "Red";
        case 6: return "Pink";
    }
}
