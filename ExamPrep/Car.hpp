#ifndef __CAR_H__
#define __CAR_H__
#include "Vehicle.hpp"
#include <vector>
#include <iostream>
#include <fstream>

class Car : virtual public Vehicle { // nasledqva virtual zashtoto tuk imame diamanten problem. po natatuk pickuptruck nasledqva i car i truck

protected:
    
    size_t seats;
    std::vector<char*> passengers; // vektor ot char*, toest trqbva da imame golqma chetvorka

    void deleteCar(); // funkciq koqto iztriva dinamichanta pamet
    void copyCar(const Car&); // funkciq za kopirane

public:

    Car(const char*, const unsigned, const size_t);
    // golqma chetvorka
    Car(const Car&);
    ~Car();
    Car& operator=(const Car&);
    // <3

    void addPassenger(const char*); // dobavq pasajer po podadeno ime
    void removePassenger(const char*); // premahva pasajer po podadeno ime

    unsigned getMaxRange() const; // izchislqva max range tam to go pishe v uslovieto kak
    // getteri za chlen dannite
    size_t getSeats() const;
    const std::vector<char*>& getPassengerList() const;

    Vehicle* clone() const; // tozi clone koito sluji kato shte kopirame obekti po natatuk
    void write(std::ofstream&) const; // pishe na failov potok

    friend std::ostream& operator<<(std::ostream&, const Car&); // pishe na << potok

};

void Car::deleteCar() {

    for (char* p : passengers) {

        delete[] p; // triem vseki char* ot pasajeri, toest dinamichen char masiv, toest nizs

    }
    
}

void Car::copyCar(const Car& other) {

    this->seats = other.seats;
    for (char* p : other.passengers) {

        char* newP = new char[strlen(p) + 1]; // suzdavame nov char*, za da nqma spodelena pamet koeto e mnogo losho!
        strcpy(newP, p); // kopirame imeto
        passengers.push_back(newP); // slagame go v nashiq vektor

    }
    
}

Car::Car(const char* model, const unsigned range, const size_t seats) : Vehicle(model, range), seats(seats) {} // konstruktor

Car::Car(const Car& other) : Vehicle(other.getModel(), other.getRange()) { // kopi konstruktor

    copyCar(other);

}

Car::~Car() { // destruktor

    deleteCar();

}

Car& Car::operator=(const Car& other) { // operator =

    if (this != &other) {

        Vehicle::operator=(other);
        deleteCar();
        copyCar(other);

    }

    return *this;

}

void Car::addPassenger(const char* person) {

    if (passengers.size() == seats) throw "Not enough room!";

    // pravim sushtata shashma kato v copy, za da nqma spodelena pamet
    char* newPerson = new char[strlen(person) + 1];
    strcpy(newPerson, person);
    passengers.push_back(newPerson);

}

void Car::removePassenger(const char* person) {

    int index = 0;
    bool found = false;

    // proverqvame dali ima passengera, ako go nqma hvurlqme greshka
    for (char* p : passengers) {

        if (!strcmp(person, p)) { // strcmp vrushta 0 ako dvata niza sa ednakvi, zatova slagame !

            found = true;
            break;

        }
        index++;

    }

    if (!found) throw "Person not found!";

    passengers.erase(passengers.begin() + index); // taka se trie daden element ot vektor

}

unsigned Car::getMaxRange() const {

    return this->getRange() - (100 * passengers.size());

}

size_t Car::getSeats() const {

    return seats;

}

const std::vector<char*>& Car::getPassengerList() const {

    return passengers;

}

// Vehicle* Car::clone() const {

//     // taka klonirame obekt, zabeleji che tipa koito vrushtame e Vehicle* no pishem return new CAR
//     return new Car{*this};

// }

void Car::write(std::ofstream& os) const {

    // tuk priemame failov potok i zapisvame v nego informaciqta za obekta
    os << "Model: " << getModel() << ", Range: " << getRange() << ", Seats: " << getSeats() << std::endl;

}

std::ostream& operator<<(std::ostream& os, const Car& obj) {

    os << "Model: " << obj.getModel() << ", Range: " << obj.getRange() << ", Seats: " << obj.getSeats();

    return os;

}

#endif // __CAR_H__