#ifndef _CAR_
#define _CAR_
#include <iostream>
#include <cstring>
#include "Reservation.hpp"

class Car {

    unsigned id;
    char type[51];
    unsigned year;
    Reservation* reservations;
    size_t resCount;

    void deleteCar() {

        delete[] reservations;

    }

    void copyCar(const Car& other) {

        this->id = other.id;
        strcpy(this->type, other.type);
        this->year = other.year;
        this->resCount = other.resCount;
        reservations = new Reservation[resCount];

        for (size_t i = 0; i < resCount; i++) {

            this->reservations[i] = other.reservations[i];

        }

    }

    void copyCarMove(Car&& other) {

        this->id = other.id;
        strcpy(this->type, other.type);
        this->year = other.year;
        this->reservations = other.reservations;
        this->resCount = other.resCount;

        other.id = 0;
        strcpy(other.type, "");
        other.year = 0;
        other.reservations = nullptr;
        other.resCount = 0;

    }

public:

    Car(const unsigned id = 0, const char* type = "", const unsigned year = 0);
    Car(const Car&);
    Car(Car&&);
    ~Car();

    Car& operator=(const Car&);
    Car& operator=(Car&&);

    void addReservation(const Reservation&);

    friend std::ostream& operator<<(std::ostream&, const Car&);
    friend std::istream& operator>>(std::istream&, Car&);

};

Car::Car(const unsigned id, const char* type, const unsigned year) {

    this->id = id;
    strcpy(this->type, type);
    this->year = year;
    this->resCount = 0;
    this->reservations = nullptr;
    
}

Car::Car(const Car& other) {

    copyCar(other);
    
}

Car::Car(Car&& other) {

    copyCarMove((Car&&)other);
    
}

Car::~Car() {

    deleteCar();
    
}

Car& Car::operator=(const Car& other) {

    if (this != &other) {

        deleteCar();
        copyCar(other);

    }

    return *this;
    
}

Car& Car::operator=(Car&& other) {

    if (this != &other) {

        deleteCar();
        copyCarMove((Car&&)other);

    }

    return *this;
    
}

void Car::addReservation(const Reservation& res) {

    for (size_t i = 0; i < resCount; i++) {

        if (reservations[i].overlaps(res)) throw std::exception();

    }

    Reservation* temp = new Reservation[resCount + 1];
    for (size_t i = 0; i < resCount; i++) {

        temp[i] = reservations[i];

    }

    temp[resCount] = res;
    deleteCar();
    reservations = temp;
    resCount++;
    
}

std::istream& operator>>(std::istream& is, Car& obj) {

    unsigned id, year;
    char type[51] = "";
    is >> id >> type >> year;

    obj = Car{id, type, year};

    is >> obj.resCount;
    obj.reservations = new Reservation[obj.resCount];

    for (size_t i = 0; i < obj.resCount; i++) {

        is >> obj.reservations[i];

    }

    return is;
    
}

std::ostream& operator<<(std::ostream& os, const Car& obj) {

    os << obj.id << ' ' << obj.type << ' ' << obj.year << ' ' << obj.resCount << ' ';

    for (size_t i = 0; i < obj.resCount; i++) {

        os << obj.reservations[i] << ' ';

    }

    return os;
    
}

#endif