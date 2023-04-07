#ifndef _POWER_
#define _POWER_
#include <iostream>
#include <cstring>

class Power {

    char* name;
    double damage;

public:

    Power(const char* name = "", const double damage = 0);
    ~Power();

    bool operator<(const Power&);

};

Power::Power(const char* name, const double damage) {

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->damage = damage;
    
}

Power::~Power() {

    delete[] name;
    
}

bool Power::operator<(const Power& other) {

    return this->damage < other.damage;
    
}

#endif