//
// Created by nikman on 05.03.2021.
//

#ifndef HOMEWORK2_LECTUREROOM_H
#define HOMEWORK2_LECTUREROOM_H


#include "../Auditorium.h"

class LectureRoom: public Auditorium {
public:
    LectureRoom(): Auditorium(){
        if (this->floor == 1){
            this->access_level_toEnter = -1;
        } else{
            this->access_level_toEnter = 1;
        }

        this->name = "Lecture Room";
        this->spec_access = false;
        this->spec_access_target = "";
    }
};


#endif //HOMEWORK2_LECTUREROOM_H
