//
// Created by nikman on 06.03.2021.
//

#ifndef HOMEWORK2_LABCABINET_H
#define HOMEWORK2_LABCABINET_H


#include "../Auditorium.h"

class LabCabinet: public Auditorium {
public:
    LabCabinet(std::string spec):Auditorium(){
        this->access_level_toEnter = 1;
        this->name = "Lab Cabinet";
        this->spec_access = true;
        this->spec_access_target = spec;
    }
};


#endif //HOMEWORK2_LABCABINET_H
