//
// Created by nikman on 05.03.2021.
//
#include <ctime>
#include "Student.h"

void Student::write_final() {
    srand(time(0));
    this->grade_for_final = ((rand() + this->name.length()) % 5) + 1;
    std::cout<< this->name << " id:"<< this->get_user_id() << " got grade: " << this->grade_for_final <<"\n";
}

int Student::get_final_grade() {
    return this->grade_for_final;
}
