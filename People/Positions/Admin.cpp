//
// Created by nikman on 05.03.2021.
//

#include <iostream>
#include "string"

#include "Admin.h"

void Admin::grant_access(Person *person, Auditorium *room) {

    std::vector<Auditorium> specificRooms = person->additional_rooms;
    if (person->access_level >= room->get_access_level()) {
        std::cout << "User " << person->name << " id:"<< person->get_user_id()
        << " already has access to room "<< room->name << " #" << room->get_room_number() << "\n";
        return;
    }
    for (auto & additional_room : person->additional_rooms) {
        if (additional_room.get_room_number() == room->get_room_number() ){
            std::cout << "User " << person->name << " id:"<< person->get_user_id()
            << " already has access to room "<< room->name << " #" << room->get_room_number() << "\n";
            return;
        }
    }

    person->additional_rooms.push_back(*room);
    std::cout<<"Granted special access to room " << room->name << " #" << room->get_room_number()
    << " to user " << person->name << " id:"<< person->get_user_id() << "\n";
}

void Admin::revoke_access(Person *person, Auditorium *room) {
    std::vector<Auditorium> specificRooms = person->additional_rooms;
    for (int i = 0; i < specificRooms.size(); i++) {
        if (specificRooms[i].get_room_number() == room->get_room_number()) {
            person->additional_rooms.erase(person->additional_rooms.begin() + i);
            std::cout<<"Revoked special access to room " << room->name << " #" << room->get_room_number()
                     << " from user " << person->name << " id:"<< person->get_user_id() << "\n";
            return;
        }
    }
    std::cout << " User " << person->name << " id:"<< person->get_user_id()
    <<" had no special access to " << room->name << " #" << room->get_room_number() << "\n";
}
