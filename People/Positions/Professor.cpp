//
// Created by nikman on 06.03.2021.
//

#include "Professor.h"
#include "Student.h"

void Professor::announce_drop_candidates(std::vector<Student*> people) {
    int counter = 0;
    for (int i = 0; i < people.size(); i++){
        counter += 1;
        if (people[i]->get_final_grade() <= 2){
            std::cout << "Student " << people[i]->name << " id:"<< people[i]->get_user_id()
            << " is a drop candidate with grade: " << people[i]->get_final_grade() << "\n";
        }
    }
    if (counter == 0) {
        std::cout<< "No drop candidates!";
    }
}
