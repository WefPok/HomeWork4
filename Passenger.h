
#ifndef HW4_NoskovNikita_PASSENGER_H
#define HW4_NoskovNikita_PASSENGER_H
#include <string>
#include <utility>

using namespace std;

class Passenger {
public:
    explicit Passenger(string name);
    string getName();
private:
    string name;
};

#endif