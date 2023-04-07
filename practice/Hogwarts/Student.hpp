#ifndef _STUDENT_
#define _STUDENT_
#include <iostream>
#include <cstring>
#include "Power.hpp"

class Student {

    char* name;
    char* house;
    Power const* power;
    int health;

public:

    Student(const char* name = "", const char* house = "", const int health = 0);
    ~Student();

    void setPower(const Power*);

};

Student::Student(const char* name, const char* house, const int health) {

    this->name = new char[strlen(name) + 1];
    strcpy(this->name , name);
    this->house = new char[strlen(house) + 1];
    strcpy(this->house, house);
    this->health = health;
    
}

Student::~Student() {

    delete[] name;
    delete[] house;
    
}

void Student::setPower(const Power* pow) {

    this->power = pow;
    
}

#endif