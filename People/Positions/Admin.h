//
// Created by nikman on 05.03.2021.
//

#include "string"

#ifndef HOMEWORK2_ADMIN_H
#define HOMEWORK2_ADMIN_H

#include "../Person.h"

class Admin: public Person {
public:
    void grant_access(Person *person, Auditorium *room);
    void revoke_access(Person *person, Auditorium *room);
    Admin(std::string name): Person(name){
        access_level = 99;
        position = "Admin";
    }
};


#endif //HOMEWORK2_ADMIN_H
