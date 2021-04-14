//
// Created by nikman on 06.03.2021.
//

#ifndef HOMEWORK2_LABEMPLOYEE_H
#define HOMEWORK2_LABEMPLOYEE_H


#include "../Person.h"

class LabEmployee: public Person {
public:
    LabEmployee(std::string name): Person(name){
        this->access_level = 1;
        position = "Lab Employee";
    }
};


#endif //HOMEWORK2_LABEMPLOYEE_H
