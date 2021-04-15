
#ifndef HW4_NoskovNikita_PASSENGERGATEWAY_H
#define HW4_NoskovNikita_PASSENGERGATEWAY_H
#include <string>
#include <vector>
#include "Passenger.h"
#include "MobileApp.h"

using namespace std;

class PassengerGateway {
public:
    MobileApp app;

    explicit PassengerGateway(MobileApp app) { this->app = app; }

    bool login(Passenger passenger);

    void choosePaymentMethod(Passenger passenger);

    void showOrderHistory(Passenger passenger);

    void placeOrder(Passenger passenger, string from, string to, string time);

    string getTime(string from, string to);
};


#endif
