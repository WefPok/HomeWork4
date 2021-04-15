#include <iostream>
#include <ctime>
#include <chrono>

#include "PassengerGateway.h"
#include "MobileApp.h"
#include "Passenger.h"
#include "Car.h"
#include "DriverGateway.h"

using namespace std;

int getRandomNumber(int min, int max);

int main() {
    srand(time(0));

    MobileApp mobileapp("WEndexTaxi");
    PassengerGateway PassengerGateway(mobileapp);
    DriverGateway DriverGateway(mobileapp);
    Passenger passenger_Daniil("Nikita");
    ComfortCar TeslaModelX("Bentley ", "AC9890", Car::RED, "25/25");
    Driver driver_Nurdaulet("Arslan", TeslaModelX);

    PassengerGateway.login(passenger_Daniil);
    DriverGateway.login(driver_Nurdaulet);

    cout << "Bought water" << endl;
    TeslaModelX.BuyBottlesOfWater(10);

    cout << "\n<-----*********************************************************----->\n" << endl;

    cout << "Passenger wants to get order history!" << endl;
    PassengerGateway.showOrderHistory(passenger_Daniil);

    cout << "\n<-----*********************************************************----->\n" << endl;

    cout << "Driver wants to get order history!" << endl;
    DriverGateway.retrieveOrderHistory(driver_Nurdaulet);

    cout << "\n<-----*********************************************************----->\n" << endl;

    cout << "Driver update status!" << endl;
    DriverGateway.updateStatus(driver_Nurdaulet, true);
    cout << "Driver wants see car!" << endl;
    DriverGateway.displayCarInf(driver_Nurdaulet);

    cout << "\n<-----*********************************************************----->\n" << endl;

    cout << "Situation when there no orders" << endl;
    DriverGateway.dispAvOrders(driver_Nurdaulet);

    cout << "\n<-----*********************************************************----->\n" << endl;

    PassengerGateway.placeOrder(passenger_Daniil, "33/33", "100/100", PassengerGateway.getTime("33/33", "100/100"));
    cout << "Driver watch the list of orders!" << endl;
    DriverGateway.dispAvOrders(driver_Nurdaulet);

    cout << "\n<-----*********************************************************----->\n" << endl;

    int orderId;
    if (DriverGateway.getOrderNumber() == 1) {
        orderId = 0;
    } else {
        orderId = getRandomNumber(0 , DriverGateway.getOrderNumber());
    }

    if (orderId < 0) { orderId = 0; }

    DriverGateway.takeOrder(driver_Nurdaulet, passenger_Daniil, orderId);

    cout << "\n<-----*********************************************************----->\n" << endl;

    return 0;
}

int getRandomNumber(int min, int max){ return min + rand() % max; }