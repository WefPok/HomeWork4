//
// Created by nikman on 05.03.2021.
//
#include <iostream>
#include "string"

#include "Person.h"

void Person::enter_room(Auditorium* room) {

    if(room->get_emergency_status()){
        std::cout << "Room " << room->name << " #" << room->get_room_number() << " opened in emergency mode.\n";
        return;
    }
    if (this->access_level >= room->get_access_level() && !room->get_spec_access()){
        std::cout << "Room " << room->name << " #" << room->get_room_number() << " opened for "<< this->position << " " << this->name << " id:"<< this->_id << "\n";
        return;
    }
    if ((room->get_spec_access() && (room->get_spec_access_target() == this->position ||
    room->get_spec_access_target() == std::to_string(this->get_user_id())) || this->access_level == 99 ||
    this->name == room->get_spec_access_target())){
        std::cout << "Room " << room->name << " #" << room->get_room_number() << " opened for "<< this->position << " " << this->name << " id:"<< this->_id << "\n";
        return;
    }
    for (auto & additional_room : this->additional_rooms){
        if (additional_room.get_room_number() == room->get_room_number()) {

            std::cout << "Room " << room->name << " #" << room->get_room_number() << " opened for "<< this->position << " " << this->name << " id:"<< this->_id << "\n";
            return;
        }
    }
    std::cout<< this->position << " "<< this->name << " id:"<< this->_id << " has no permission to enter "<< room->name << " #" << room->get_room_number()<< ". Needed "
    << room->get_color_access() <<" access level or special access from admin\n";
}

int Person::get_user_id() {
    return this->_id;
}

