#include <iostream>
#include "string"

#include "People/Positions/Admin.h"
#include "People/Person.h"
#include "People/Positions/Student.h"
#include "Rooms/Auditorium.h"
#include "Rooms/RoomTypes/ClassRoom.h"
#include "Rooms/RoomTypes/LectureRoom.h"
#include "Rooms/RoomTypes/DirectorCabinet.h"
#include "People/Positions/Director.h"
#include "People/Positions/LabEmployee.h"
#include "People/Positions/Professor.h"
#include "Rooms/RoomTypes/ProfessorCabinet.h"
#include "Rooms/RoomTypes/LabCabinet.h"
#include "Rooms/RoomTypes/ConferenceRoom.h"
#include "Guest.h"

using namespace std;

void listUsers(vector<Person*> people){
    int counter= 0;
    for (Person *person: people){
        if (counter%3 == 0 && counter != 0){
            cout << "\n";
        }
        if (counter%3 != 0){
            cout << " | ";
        }
        cout << person->position << " " << person->name << string(27 - person->name.length() - person->position.length(),' ')
        << " id: " << person->get_user_id()<< string(3 - to_string(person->get_user_id()).length(),' ');
        counter += 1;
    }
    cout << "\n";
    cout << "<------------------------------------------------------------------>\n";
}

void listRooms(vector<Auditorium*> allRooms){
    int counter= 0;
    cout << "Type and #           Owner                Floor\n\n";
    for (Auditorium *room: allRooms){
        if (counter%2 == 0 && counter != 0){
            cout << "\n";
        }
        if (counter%2 != 0){
            cout << " | ";
        }
        cout << room->name << "#" << room->get_room_number() << string(20 - room->name.length()- to_string(room->get_room_number()).length() , ' ');

        if(room->get_spec_access_target() == ""){
            cout << "Public Room" << string(14, ' ');
        }
        else if (room->get_spec_access_target().length() < 3){
            cout << "Owner id:"<<room->get_spec_access_target()<< string(16 - room->get_spec_access_target().length(), ' ');
        }
        else {
            cout << "Owner: "<<room->get_spec_access_target()
            << string(18 - room->get_spec_access_target().length(), ' ');
        }
        cout << room->floor;
        counter += 1;
    }
    cout << "\n";
    cout << "<------------------------------------------------------------------>\n";
}

int getInteger(){
    int error;
    int id;
    do
    {
        error = 0;
        cin >> id;
        if (cin.fail())
        {
            cout << "Please enter a valid integer" << endl;
            error = 1;
            cin.clear();
            cin.ignore(80, '\n');
        }
    }while(error == 1);
    return id;
}
void announce_drop_candidates(vector<Person*> people, vector<Student*> students){
    int error;

    do{
        error = 0;
        cout << "Choose a professor who will announce results (id):\n";
        int id = getInteger();
        for(Person* person: people){
            if(person->get_user_id() == id && person->position != "Professor"){
                error = 1;
            }
            if(person->get_user_id() == id && person->position == "Professor"){
                Professor professor(person->name);
                cout << "Professor's " << person->name << " id:"<< person->get_user_id() << " announcement:\n";
                professor.announce_drop_candidates(students);

            }
        }
        if (error == 1){
            cout << "Only professors can announce drop candidates.\n";
        }
    }while (error == 1);

}

Person* get_person(vector<Person*> allPeople, int id){
    for(Person *person : allPeople){
        if (person->get_user_id() == id){
            return person;
        }
    }
    return NULL;
}

Auditorium* get_room(vector<Auditorium*> allRooms, int id){
    for(Auditorium *room : allRooms){
        if (room->get_room_number() == id){
            return room;
        }
    }
    return NULL;
}
void act(vector<Person*> allPeople, vector<Auditorium*> allRooms, vector<Admin*> allAdmins){
    cout << "Enter personal id\n";
    int pid = getInteger();
    int rid;
    int rid1;
    int pid1;
    bool error;
    bool adm = false;
    int counter;

    if(get_person(allPeople, pid)->access_level == 99) {
        adm = true;
        error = false;
        do {
            cout << "Please enter admin network password";
            string password;
            cin >> password;
            if (password != "qwerty123"){
                cout << "incorrect password, try again";
                error = true;
            }
        }while(error);

    }
    cout<< "Choose operation:\n"
           "1 - Enter room\n"
           "2 - Grant access to room (admins only)\n"
           "3 - Revoke access to room (admins only)\n";

    int curr_op = getInteger();
    switch (curr_op) {
        case 1:
            cout << "Enter Room #\n";
            rid = getInteger();
            if (get_person(allPeople, pid) == NULL){
                cout << "Person with id:" << pid << " doesn't exist";
                return;
            }
            if (get_room(allRooms, rid) == NULL){
                cout << "Room with #:" << rid << " doesn't exist";
                return;
            }
            get_person(allPeople, pid)->enter_room(get_room(allRooms, rid));
            break;
        case 2:
            if (!adm){
                cout << "No permission. Session closed.";
                return;
            }
            cout << "Enter id of Person to grant access\n";
            pid1 = getInteger();
            cout << "Enter # of room to grant access\n";
            rid1 = getInteger();

            if (get_person(allPeople, pid1) == NULL){
                cout << "Person with id:" << pid1 << " doesn't exist";
                return;
            }
            if (get_room(allRooms, rid1) == NULL){
                cout << "Room with #:" << rid1 << " doesn't exist";
                return;
            }
            counter = 0;
            for(Admin *admin:allAdmins){
                if(admin->get_user_id() == pid){
                    break;
                }
                counter += 1;
            }
            allAdmins[counter]->grant_access(get_person(allPeople, pid1), get_room(allRooms, rid1));
            break;

        case 3:
            if (!adm){
                cout << "No permission. Session closed.";
                return;
            }
            cout << "Enter id of Person to revoke access\n";
            pid1 = getInteger();
            cout << "Enter # of room to revoke access\n";
            rid1 = getInteger();

            if (get_person(allPeople, pid1) == NULL){
                cout << "Person with id:" << pid1 << " doesn't exist";
                return;
            }
            if (get_room(allRooms, rid1) == NULL){
                cout << "Room with #:" << rid1 << " doesn't exist";
                return;
            }
            counter = 0;
            for(Admin *admin:allAdmins){
                if(admin->get_user_id() == pid){
                    break;
                }
                counter += 1;
            }
            allAdmins[counter]->revoke_access(get_person(allPeople, pid1), get_room(allRooms, rid1));
            break;
        default:
            break;
    }

}

void mainMenu(vector<Student*> students, vector<LabEmployee*> labEmployees,
              vector<Professor*> professors, vector<Admin*> admins, Director *director,
              vector<Person*> allPeople, vector<Auditorium*> allRooms){
    int curr_command;
    do{
        cout << "Enter a Command.\n"
                "1  - Choose Person to Act\n"
                "2  - Make Students Write Final\n"
                "3  - Announce drop candidates\n"
                "4  - List all users\n"
                "5  - List all rooms\n"
                "6 - Trigger emergency mode\n"
                "99 - Exit program\n"
                "Your input: \n";

        curr_command = getInteger();

        switch (curr_command) {
            case 1:
                act(allPeople, allRooms, admins);
                cout << "\n<------------------------------------------------------------------>\n";
                break;
            case 2:
                for (Student *student: students){
                    student->write_final();
                }
                cout << "\n<------------------------------------------------------------------>\n";
                break;
            case 3:
                announce_drop_candidates(allPeople, students);
                cout << "\n<------------------------------------------------------------------>\n";
                break;
            case 4:
                listUsers(allPeople);
                cout << "\n<------------------------------------------------------------------>\n";
                break;
            case 5:
                listRooms(allRooms);
                cout << "\n<------------------------------------------------------------------>\n";
                break;
            case 6:

                cout << "\n<------------------------------------------------------------------>\n";
                break;
            case 99:
                cout << "\n<------------------------------------------------------------------>\n";
                cout << "Closing...";
                break;
            default:
                cout << "Enter valid command\n";
        }
    }while (curr_command != 99);
}

int main() {

    // <----------------------------\/----Creating Users----\/---------------------------->
    vector<Person*> allPeople;
    vector<Student*> students;
    vector<Guest*> guests;
    vector<LabEmployee*> labemployees;
    vector<Professor*> professors;
    vector<Admin*> admins;
    string names[20]={
            "Darren Dehner",
            "Nakia Napoli",
            "Nathan Nowak",
            "Katelin Kost",
            "Nelda Neighbors",
            "Joel Juarbe",
            "Anna Amorim",
            "Serita Souza",
            "Karie Kammerer",
            "Vern Vara",
            "Brandon Beyer",
            "Willa Whalen",
            "Bryant Burgoon",
            "Emile Ensign",
            "Shery Saylor",
            "Darin Dworkin",
            "Yer Yoshida",
            "Lala Lusk",
            "Suanne Schaal",
            "Laurine Lerman"
    };
    for (int i = 0; i < 16; ++i) {
        students.push_back(new Student(names[i]));
        allPeople.push_back(students[i]);
    }
    for (int i = 0; i < 4; ++i) {
        guests.push_back(new Guest("Guest" + to_string(i+1)));
        allPeople.push_back(guests[i]);
    }
    for (int i = 0; i < 8; ++i) {
        string name = "Lab Employee " + to_string(i+1);
        labemployees.push_back(new LabEmployee(name));
        allPeople.push_back(labemployees[i]);
    }
    for (int i = 0; i < 4; ++i) {
        professors.push_back(new Professor(names[i+16]));
        allPeople.push_back(professors[i]);
    }



    admins.push_back(new Admin("Admin 2"));
    allPeople.push_back(admins[0]);
    admins.push_back(new Admin("Admin 1"));
    allPeople.push_back(admins[1]);


    Director director("Chosen One");
    allPeople.push_back(&director);
    // <----------------------------/\----Creating Users----/\---------------------------->

    // <----------------------------\/----Creating Rooms----\/---------------------------->
    vector<ClassRoom*> classRooms;
    vector<LectureRoom*> lectureRooms;
    vector<ConferenceRoom*> conferenceRooms;
    vector<ProfessorCabinet*> professorCabinets;
    vector<LabCabinet*> labCabinets;
    DirectorCabinet directorCabinet("Chosen One");

    vector<Auditorium*> allRooms;

    for (int i = 0; i < 6; ++i) {
        classRooms.push_back(new ClassRoom());
        allRooms.push_back(classRooms[i]);
    }
    for (int i = 0; i < 3; ++i) {
        lectureRooms.push_back(new LectureRoom());
        allRooms.push_back(lectureRooms[i]);
    }
    for (int i = 0; i < 3; ++i) {
        conferenceRooms.push_back(new ConferenceRoom());
        allRooms.push_back(conferenceRooms[i]);
    }
    for (int i = 0; i < 4; ++i) {
        professorCabinets.push_back(new ProfessorCabinet(names[i+16]));
        allRooms.push_back(professorCabinets[i]);
    }
    for (int i = 0; i < 8; ++i) {
        labCabinets.push_back(new LabCabinet(to_string(16+i)));
        allRooms.push_back(labCabinets[i]);
    }
    allRooms.push_back(&directorCabinet);

    // <----------------------------/\----Creating rooms----/\---------------------------->

    // <-------------------------------\/----Main menu----\/------------------------------>

    listUsers(allPeople);
    listRooms(allRooms);
    Auditorium control;
    mainMenu(students, labemployees, professors, admins, &director,allPeople,allRooms);


    // <-------------------------------/\----Main menu----/\------------------------------->
}
