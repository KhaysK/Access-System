#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

enum Levels {
    // Levels of access
    NO_LEVEL,
    GREEN,
    YELLOW,
    PERSONAL,
    RED
};

class Card{
public:
    Levels accessLevel;
    bool hasCabinet = false;
    int cabinet = -1484;

    // Here I have created list of rooms in the university
    vector<pair<int, Levels>> rooms {make_pair(105,GREEN), make_pair(106,GREEN), make_pair(107,GREEN),
                                     make_pair(108,GREEN),make_pair(313,NO_LEVEL),make_pair(314,NO_LEVEL),
                                     make_pair(317,NO_LEVEL),make_pair(312,NO_LEVEL),make_pair(404,YELLOW),
                                     make_pair(405,YELLOW),make_pair(406,YELLOW),make_pair(407,YELLOW),
                                     make_pair(400,PERSONAL),make_pair(401,PERSONAL),make_pair(402,PERSONAL),
                                     make_pair(403,PERSONAL),make_pair(408,PERSONAL), make_pair(409,PERSONAL)};

    Card(Levels level){
        // Constructor for student, lab employee and admin
        accessLevel = level;
    }

    Card(Levels level, int cabinet){
        // Constructor for professor and director
        accessLevel = level;
        hasCabinet = true;
        this->cabinet = cabinet;
    }
};


class User{
public:
    Card accessCard;
    string name,citizenship;
    string position;
        
    User(string name, string position , string citizenship, Levels card) :
            accessCard(card){
                // Constructor for student, lab employee and admin
        this->citizenship = move(citizenship);
        this->name = move(name);
        this->position = move(position);
    }
        
    User(string name, string position,string citizenship,int cabinet, Levels card) :
            accessCard(card,cabinet){
               // Constructor for professor and director
        this->citizenship = move(citizenship);
        this->name = move(name);
        this->position = move(position);
    }

    void getInfo(){
        // This method return all information about user
        // if user director or professor also returns their cabinet

        cout << endl <<  "User has been successfully found!"<< endl << endl;
        cout << "Name: "<< name << endl;
        cout << "User type: "<< position << endl;
        cout << "Citizenship: "<< citizenship << endl;
        cout << "Level: ";
        if(accessCard.accessLevel == NO_LEVEL) cout << "No Level" << endl;
        else if(accessCard.accessLevel == GREEN) cout << "Green" << endl;
        else if(accessCard.accessLevel == YELLOW) cout << "Yellow" << endl;
        else if(accessCard.accessLevel == RED) cout << "Red" << endl;
        if(accessCard.hasCabinet)
            cout << "Personal cabinet: " << accessCard.cabinet << endl;
        cout << "Rooms available: [ ";
        for(pair<int, Levels> room : accessCard.rooms){
            if(room.second <= accessCard.accessLevel)
                cout << room.first << ", ";
        }
        cout << "] " << endl;
    }
    void openRoom(int roomNo){
        // This method goes trough array of rooms and checks does user has access to given room
        // and prints appropriate massage

        for(pair<int, Levels> room : accessCard.rooms){
            if((room.first == roomNo && accessCard.accessLevel >= room.second) || roomNo == accessCard.cabinet ) {
                cout << "The room is open, welcome!" << endl;
                return;
            }
            else if (room.first == roomNo && accessCard.accessLevel < room.second) {
                cout << "You don't have access to this room!" << endl;
                return;
            }
        }
        cout << "Room does not exist!" << endl;
    }
    void setLevel(Levels level){
        // This method set given level to user through which the method was called
        accessCard.accessLevel = level;
        cout << "Level has been assigned!" << endl;
    }

    void setRoom(int roomNo){
        // This method set given room to user through which the method was called
        if(accessCard.hasCabinet){
            accessCard.cabinet = roomNo;
            cout << "Room has been assigned!" << endl;
        } else cout << "This user can not have personal room!" << endl;

    }
};

                                                                                    // Here below I have created classes for different
                                                                                    // users and appropriate constructors
class Student: public User{
public:
    Student(string name,string citizenship, Levels card = NO_LEVEL) :
    User(move(name),"Student",move(citizenship),card){
    }
};

class Lab_employee: public User{
public:
    Lab_employee(string name,string citizenship, Levels card = GREEN) :
    User(move(name),"Lab employee",move(citizenship),card){
    }
};

class Professor: public User{
public:
    Professor(string name, string citizenship, int cabinet, Levels card = YELLOW) :
              User(move(name),"Professor",move(citizenship),move(cabinet),card){
    }

};

class Director: public User{
public:
    Director(string name, string citizenship, int cabinet,Levels card = YELLOW) :
            User(move(name),"Director",move(citizenship),move(cabinet),card){
    }

};

class Admin: public User{
public:
    string password;
    Admin(string name, string password,string citizenship, Levels card = RED) :
            User(move(name),"Admin",move(citizenship),card){
        this->password = move(password);
    }
};



//-------------------------------------------------------MAIN_FUNCTION-------------------------------------------------------------

int main() {
    vector<User> InnopolisStuff;
    vector<Admin> Admins;
    string name, position, citizenship, password;
    int code = 10, cabinet, roomNum;
    bool isFound = false;


                                                                                            // Here I created different users and added them into the arrays
#pragma region Creating_users
    Director director("Tormasov Alexandr Gennadievich","Russia",400);
    InnopolisStuff.push_back(director);
    Admin firstAdmin("Voronov Alexandr Mikhailovich", "123456789qwerty", "Russia");
    Admin secondAdmin("Ismailov Akhmed Bagandovich","dagestan1332", "Turkey");
    Admins.push_back(firstAdmin);
    Admins.push_back(secondAdmin);
    Professor firstProfessor("Zuev Eugeni Mikhailovich","Russia", 401);
    Professor secondProfessor("Ivan Konyukhov Vladimirovich", "Russia", 402);
    Professor thirdProfessor("Manuel Mazzara","Italy", 403);
    Professor fourthProfessor("Adil Khan", "Pakistan" ,408);
    InnopolisStuff.push_back(firstProfessor);
    InnopolisStuff.push_back(secondProfessor);
    InnopolisStuff.push_back(thirdProfessor);
    InnopolisStuff.push_back(fourthProfessor);
    Lab_employee firstLabEmployee("Kholmatova Zamira Karimovna", "Uzbekistan");
    Lab_employee secondLabEmployee("Smirnov Oleg Dmitrievich", "Russia");
    Lab_employee thirdLabEmployee("Igorev Alexey Gennadievich", "Russia");
    Lab_employee fourthLabEmployee("Ergasheva Shokhista Muradovna", "Kazakhstan");
    Lab_employee fifthLabEmployee("Delgado Imre","Brazil");
    Lab_employee sixthLabEmployee("Shikulin Alexey Andreevich","Russia");
    Lab_employee seventhLabEmployee("Ivanov Mike Bogdanovich","Russia");
    Lab_employee eighthLabEmployee("Fayzrakhmanov Timur Rustamovich","Russia");
    InnopolisStuff.push_back(firstLabEmployee);
    InnopolisStuff.push_back(secondLabEmployee);
    InnopolisStuff.push_back(thirdLabEmployee);
    InnopolisStuff.push_back(fourthLabEmployee);
    InnopolisStuff.push_back(fifthLabEmployee);
    InnopolisStuff.push_back(sixthLabEmployee);
    InnopolisStuff.push_back(seventhLabEmployee);
    InnopolisStuff.push_back(eighthLabEmployee);
    Student firstStudent("Kuklina Anastasiia Andreevna","Russia");
    Student secondStudent("Murashko Artem Igorevich","Russia");
    Student thirdStudent("Platonov Nikolay Alexeevich","Russia");
    Student fourthStudent("Gia Trong Nguyen","Thailand");
    Student fifthStudent("Magzumov Davlatkhodzha Muradovich","Uzbekistan");
    Student sixthStudent("Kuzyakhmetov Eugene Mikhailovich", "Russia");
    Student seventhStudent("Totanji Jaffar Akhmed", "Syria");
    Student eighthStudent("Chernitsa Artem Igorevich", "Russia");
    Student ninthStudent("Tolmachev Anton Antonovich", "Russia");
    Student tenthStudent("Artemeva Alyona Dmitrievna", "Russia");
    Student eleventhStudent("Khaysadykov Khabib Jamaludinovich", "Russia");
    Student twelfthStudent("Khalilov Vagif Ruslanovich", "Azerbaijan");
    Student thirteenthStudent("Vagin Andrey Grigorievich", "Russia");
    Student fourteenthStudent("Alentev Igor Alexeevich", "Russia");
    Student fifteenthStudent("Kozikov Vladislav Bogdanovich","Russia");
    Student sixteenthStudent("Sidorskaya Margarita Anatolievna", "Russia");
    InnopolisStuff.push_back(firstStudent);
    InnopolisStuff.push_back(secondStudent);
    InnopolisStuff.push_back(thirdStudent);
    InnopolisStuff.push_back(fourthStudent);
    InnopolisStuff.push_back(fifthStudent);
    InnopolisStuff.push_back(sixthStudent);
    InnopolisStuff.push_back(seventhStudent);
    InnopolisStuff.push_back(eighthStudent);
    InnopolisStuff.push_back(ninthStudent);
    InnopolisStuff.push_back(tenthStudent);
    InnopolisStuff.push_back(eleventhStudent);
    InnopolisStuff.push_back(twelfthStudent);
    InnopolisStuff.push_back(thirteenthStudent);
    InnopolisStuff.push_back(fourteenthStudent);
    InnopolisStuff.push_back(fifteenthStudent);
    InnopolisStuff.push_back(sixteenthStudent);
#pragma endregion Creating_users


    while (code != 0){
        isFound = false;
        cout << "Please enter which user you are:" << endl;
        getline(cin, position);

        transform(position.begin(), position.end(), position.begin(),
                  [](unsigned char c){ return tolower(c); });

        if (position == "student" || position == "lab employee" || position == "professor"
        || position == "director"){
            cout << "Please enter your name:" << endl;
            getline(cin, name);

            int UserID;
            string tmpPosition;
            for (int i = 0; i < InnopolisStuff.size(); ++i){
                tmpPosition = InnopolisStuff[i].position;
                transform(tmpPosition.begin(), tmpPosition.end(), tmpPosition.begin(),
                          [](unsigned char c){ return tolower(c); });                // This part print info about user
                if(name == InnopolisStuff[i].name && position == tmpPosition)  {    // it go through list and looking for
                    InnopolisStuff[i].getInfo();                                   // user with given name
                    UserID = i;
                    isFound = true;
                }
            }
            if(!isFound) {
                cout << "Could not find such user" << endl;
                continue;
            }


            while (true){
                cout << endl << "Chose the command:" << endl << endl;
                cout << "[1] Open room"<< endl;
                cout << "[2] Exit" << endl;
                cout << "[0] Close program" << endl;
                cin >> code;
                if(code == 1){                                         // This part reads command from terminal
                    cout << "Enter number of the room:";              // and perform it.
                    cin >> cabinet;
                    InnopolisStuff[UserID].openRoom(cabinet);
                } else if(code == 2) break;
                else if(code == 0) break;
                else cout << "Command are not recognized";
            }
        }

        else if(position == "admin"){
                                                                                     // This condition for admins here admin can create
                                                                                    // new user or set to exist user new level or room

            cout << "Please enter your password:" << endl;
            cin >> password;

            for (Admin admin: Admins){
                isFound = false;
                if(password == admin.password){
                    admin.getInfo();
                    while (true) {

                        cout << endl << "Chose the command:" << endl << endl;
                        cout << "[1] Add new user" << endl;
                        cout << "[2] Set level to user" << endl;
                        cout << "[3] Set room to user" << endl;
                        cout << "[4] Exit" << endl;
                        cout << "[0] Close program" << endl;

                        cin >> code;

                        if (code == 1) {
                                                                                                        // This condition ask for information about new user
                                                                                                       //and creates user of appropriate type

                            cout << endl << "Enter name of user:" << endl;
                            cin.ignore();
                            getline(cin , name);
                            cout << "Enter citizenship of user:" << endl;
                            getline(cin, citizenship);
                            cout << "Enter position of the user:" << endl;
                            getline(cin ,position);

                            transform(position.begin(), position.end(), position.begin(),
                                      [](unsigned char c) { return tolower(c); });

                            if (position == "student") {
                                Student newStudent(name,citizenship);
                                InnopolisStuff.push_back(newStudent);
                            } else if (position == "lab employee") {
                                Lab_employee newLabEmployee(name,citizenship);
                                InnopolisStuff.push_back(newLabEmployee);
                            } else if (position == "professor") {
                                while (true) {
                                    cout << "Enter cabinet number for professor" << endl;
                                    cin >> cabinet;

                                    isFound == false;
                                    for(pair<int, Levels> room : InnopolisStuff[0].accessCard.rooms){
                                        if(room.first == cabinet){
                                            isFound = true;
                                            break;
                                        }
                                    }
                                    if (!isFound)
                                    {
                                        cout << "No such room in the University"<< endl;
                                        continue;
                                    }

                                    bool isBusy = false;
                                    for (User user: InnopolisStuff) {
                                        if (user.accessCard.cabinet == cabinet) {
                                            cout << "Cabinet is busy, chose another cabinet" << endl;
                                            isBusy = true;
                                            break;
                                        }
                                    }
                                    if (isBusy) continue;

                                    Professor newProfessor(name, citizenship, cabinet);
                                    InnopolisStuff.push_back(newProfessor);
                                    break;
                                }
                            } else if (position == "director") {
                                while (true) {
                                    cout << "Enter cabinet number for director" << endl;
                                    cin >> cabinet;

                                    isFound == false;
                                    for(pair<int, Levels> room : InnopolisStuff[0].accessCard.rooms){
                                        if(room.first == cabinet){
                                            isFound = true;
                                            break;
                                        }
                                    }
                                    if (!isFound)
                                    {
                                        cout << "No such room in the University"<< endl;
                                        continue;
                                    }

                                    bool isBusy = false;
                                    for (User user: InnopolisStuff) {
                                        if (user.accessCard.cabinet == cabinet) {
                                            cout << "Cabinet is busy, chose another cabinet" << endl;
                                            isBusy = true;
                                            break;
                                        }
                                    }
                                    if (isBusy) continue;

                                    Director newDirector(name, citizenship, cabinet);
                                    InnopolisStuff.push_back(newDirector);
                                    break;
                                }
                            } else if (position == "admin") {
                                cout << "Enter password for new admin" << endl;
                                cin >> password;
                                Admin newAdmin(name, password, citizenship);
                                Admins.push_back(newAdmin);
                            }
                        }                                                                       // End of creating part

                        else if (code == 2) {

                                                                                               // This condition asks information about exist user
                                                                                              // searches this user in the array and sets new
                                                                                             // level to this user

                            cout << endl << "Enter name of user:" << endl;
                            cin.ignore();
                            getline(cin,name);
                            string level;
                            isFound = false;
                            for (int i = 0; i < InnopolisStuff.size(); ++i) {
                                if (name == InnopolisStuff[i].name) {
                                    isFound = true;
                                    InnopolisStuff[i].getInfo();
                                    while (true){
                                        cout << endl << "Enter what level to set:" << endl;
                                        cin >> level;
                                        transform(level.begin(), level.end(), level.begin(),
                                                  [](unsigned char c) {return tolower(c);});              // This part taking name of user
                                        if (level =="green")                                             // checks is user exist and print info
                                        {                                                               // then ask level and set this level to user
                                            InnopolisStuff[i].setLevel(GREEN);
                                            break;
                                        }
                                        else if (level == "yellow") {
                                            InnopolisStuff[i].setLevel(YELLOW);
                                            break;
                                        }
                                        else if (level == "red") {
                                            InnopolisStuff[i].setLevel(RED);
                                            break;
                                        }
                                        else if (level == "no level"){
                                            InnopolisStuff[i].setLevel(NO_LEVEL);
                                            break;
                                        }
                                        else cout << "Level are not recognized" << endl;
                                        continue;
                                    }
                                }
                            }
                            if(!isFound)
                                cout << "User does not exist" << endl;
                        }                                                                                 // End of level setting part

                        else if (code == 3){
                                                                                                    // This condition asks information about exist user
                                                                                                   // searches this user in the array and sets new
                                                                                                  // room to this user if it possible
                            
                            cout << endl << "Enter name of user:" << endl;
                            cin.ignore();
                            getline(cin , name);
                            isFound = false;
                            for (int i = 0; i < InnopolisStuff.size(); ++i) {
                                if (name == InnopolisStuff[i].name) {
                                    isFound = true;
                                    InnopolisStuff[i].getInfo();
                                    while (true) {
                                        cout << "Enter cabinet number for setting" << endl;
                                        cin >> cabinet;

                                        isFound == false;
                                        for (pair<int, Levels> room : InnopolisStuff[0].accessCard.rooms) {
                                            if (room.first == cabinet) {
                                                isFound = true;
                                                break;
                                            }
                                        }
                                        if (!isFound) {
                                            cout << "No such room in the University" << endl;
                                            continue;
                                        }
                                        bool isBusy = false;
                                        for (User user: InnopolisStuff) {
                                            if (user.accessCard.cabinet == cabinet) {
                                                cout << "Cabinet is busy, chose another cabinet" << endl;
                                                isBusy = true;
                                                break;
                                            }
                                        }
                                        if (isBusy) continue;
                                        InnopolisStuff[i].setRoom(cabinet);
                                        break;
                                    }
                                }
                            }

                        }                                                                                         // End of room setting part

                        else if (code == 4) break;
                        else if (code == 0) break;
                        else cout << "Command are not recognized" << endl;

                    }
                    isFound = true;
                }
            }
            if(!isFound)
                cout << "Password incorrect" << endl;
        }
    }

    cout << endl << endl << "Closing the program..." << endl;
    return 0;
}

