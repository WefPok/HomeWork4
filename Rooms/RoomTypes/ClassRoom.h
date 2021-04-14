//
// Created by nikman on 05.03.2021.
//

#ifndef HOMEWORK2_CLASSROOM_H
#define HOMEWORK2_CLASSROOM_H

#include "../Auditorium.h"

class ClassRoom: public Auditorium {
public:
    ClassRoom(): Auditorium(){
        this->access_level_toEnter = 0;
        this->name = "Class Room";
        this->spec_access = false;
        this->spec_access_target = "";
    }
};


#endif //HOMEWORK2_CLASSROOM_H
