//
// Created by nikman on 05.03.2021.
//

#include <iostream>
#include "Auditorium.h"


int Auditorium::get_room_number() {
    return this->_room_number;
}

bool Auditorium::get_spec_access() {
    return this->spec_access;
}

std::string Auditorium::get_spec_access_target() {
    return this->spec_access_target;
}

int Auditorium::get_access_level() {
    return this->access_level_toEnter;
}

std::string Auditorium::get_color_access() {
    switch (this->access_level_toEnter) {
        case -1:
            return "blue";
        case 0:
            return "no_level";
        case 1:
            return "green";
        case 2:
            return "yellow";
        case 3:
            return "red";
        default:
            return "no_level";
    }
}

//void Auditorium::trigger_emergency() {
//
//    if (emergency){
//        for(Auditorium* room : Auditorium::roomsList){
//            room->emergency = false;
//        }
//        std::cout << "Emergency mode off!\n";
//    }
//    else{
//        for(Auditorium* room : Auditorium::roomsList){
//            room->emergency = true;
//        }
//        std::cout << "Emergency mode on!\n";
//    }
//}

bool Auditorium::get_emergency_status() {
    return this->emergency;
}
