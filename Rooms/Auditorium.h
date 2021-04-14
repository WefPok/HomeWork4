//
// Created by nikman on 05.03.2021.
//
#include "string"
#include "vector"
#ifndef HOMEWORK2_AUDITORIUM_H
#define HOMEWORK2_AUDITORIUM_H


class Auditorium {
private:
    int _room_number;

    bool emergency = false;
protected:
    bool spec_access;
    std::string spec_access_target;
    int access_level_toEnter;
public:

    int floor;
    std::string name;

    Auditorium(){
        static int currNumb = 0;
        floor = currNumb%4+1;
        _room_number = currNumb++;
        registered_rooms.push_back(this);
    }

    void trigger_emergency();
    bool get_emergency_status();
    std::string get_color_access();
    int get_room_number();
    int get_access_level ();
    bool get_spec_access();
    std::string get_spec_access_target();
    static std::vector<Auditorium*> registered_rooms;
};


#endif //HOMEWORK2_AUDITORIUM_H
