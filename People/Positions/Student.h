//
// Created by nikman on 05.03.2021.
//

#ifndef HOMEWORK2_STUDENT_H
#define HOMEWORK2_STUDENT_H


#include <iostream>
#include "../Person.h"

class Student: public Person {
public:
    int grade_for_final;
    Student (std::string name): Person(name){
        this->access_level = 0;
        position = "Student";
        grade_for_final = 5;
    }

    void write_final();
    int get_final_grade();
};


#endif //HOMEWORK2_STUDENT_H
