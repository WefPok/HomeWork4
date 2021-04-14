//
// Created by nikman on 19.03.2021.
//

#ifndef HOMEWORK2_GUEST_H
#define HOMEWORK2_GUEST_H


class Guest: public Person {
public:
    Guest (std::string name): Person(name){
        this->access_level = -1;
        position = "Guest";
    }
};


#endif //HOMEWORK2_GUEST_H
