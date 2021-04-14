//
// Created by nikman on 06.03.2021.
//

#ifndef HOMEWORK2_DIRECTORCABINET_H
#define HOMEWORK2_DIRECTORCABINET_H


#include "../Auditorium.h"

class DirectorCabinet: public Auditorium {
public:
    DirectorCabinet(std::string spec): Auditorium(){
        this->access_level_toEnter = 2;
        this->name = "Director Cabinet";
        this->spec_access = true;
        this->spec_access_target = spec;
    }
};


#endif //HOMEWORK2_DIRECTORCABINET_H
