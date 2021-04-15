
#ifndef HW4_NoskovNikita_DRIVERGATEWAY_H
#define HW4_NoskovNikita_DRIVERGATEWAY_H


#include "Driver.h"
#include "MobileApp.h"

class DriverGateway {
public:
    MobileApp app;

    vector<vector<string>> orders;

    explicit DriverGateway(MobileApp app) { this->app = app; }

    bool login(Driver driver);

    void retrieveOrderHistory(Driver driver);

    void updateStatus(Driver drive, bool status);

    void displayCarInf(Driver driver);

    void getOrders();

    void dispAvOrders(Driver driver);

    bool checkAuth(Driver driver);

    int getOrderNumber();

    void takeOrder(Driver driver, Passenger passenger, int orderId);
};

#endif