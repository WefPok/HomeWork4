//
// Created by nikman on 06.03.2021.
//

#ifndef HOMEWORK2_DIRECTOR_H
#define HOMEWORK2_DIRECTOR_H


#include "../Person.h"

class Director: public Person {
public:
    Director(std::string name): Person(name){
        this->access_level = 2;
        position = "Director";
    }
};


#endif //HOMEWORK2_DIRECTOR_H
