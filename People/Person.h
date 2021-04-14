//
// Created by nikman on 05.03.2021.
//

#include "string"
#include "vector"
#include "../Rooms/Auditorium.h"

#ifndef HOMEWORK2_HUMAN_H
#define HOMEWORK2_HUMAN_H


class Person {
private:
    int _id;
public:
    std::string name;
    std::string position;
    int access_level;
    std::vector<Auditorium> additional_rooms;

    void enter_room(Auditorium *room);
    int get_user_id();

    Person (std::string name){
        this->name = name;
        static int id = 0;
        _id = id++;
    }
};


#endif //HOMEWORK2_HUMAN_H
