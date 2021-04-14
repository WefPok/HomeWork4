//
// Created by nikman on 06.03.2021.
//

#ifndef HOMEWORK2_PROFESSOR_H
#define HOMEWORK2_PROFESSOR_H


#include "../Person.h"
#include "Student.h"

class Professor: public Person {
public:
    Professor (std::string name): Person(name){
        this->access_level = 2;
        position = "Professor";
    }
    void announce_drop_candidates(std::vector<Student*> people);
};


#endif //HOMEWORK2_PROFESSOR_H
