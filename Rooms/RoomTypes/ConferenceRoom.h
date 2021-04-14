//
// Created by nikman on 06.03.2021.
//

#ifndef HOMEWORK2_CONFERENCEROOM_H
#define HOMEWORK2_CONFERENCEROOM_H


#include "../Auditorium.h"

class ConferenceRoom: public Auditorium {
public:
    ConferenceRoom():Auditorium(){
        if (this->floor == 1){
            this->access_level_toEnter = -1;
        } else{
            this->access_level_toEnter = 2;
        }
        this->name = "Conference Room";
        this->spec_access = false;
        this->spec_access_target = "";
    }
};


#endif //HOMEWORK2_CONFERENCEROOM_H
