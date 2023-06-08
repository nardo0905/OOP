#ifndef __PICKUPTRUCK_H__
#define __PICKUPTRUCK_H__
#include "Car.hpp"
#include "Truck.hpp"
#include <fstream>

class PickupTruck : public Car, public Truck {

private:

    std::vector<char*> schedule; // podobno na car, i tuk ima vektor s dinamichni char masivi, koito sa nizove, toest -> golqma chetvorka

    void deletePickupTruck(); // triem
    void copyPickupTruck(const PickupTruck&); // kopirame

    bool exists(const char*); // proverqvam dali daden task sushtestvuva veche v schedule

public:

    PickupTruck(const char*, const unsigned, const size_t, const unsigned);
    // golqma chetvorka bez default konstruktor, kato v car
    PickupTruck(const PickupTruck&);
    ~PickupTruck();
    PickupTruck& operator=(const PickupTruck&);

    void setSchedule(const char*); // dobavq nov task v schedule
    const char* getNextTask(); // vrushta nai-gorniq task i go maha ot schedule

    unsigned getMaxRange() const;
    const std::vector<char*>& getScheduleList() const;

    Vehicle* clone() const; // klonirame
    void write(std::ofstream&) const; // pishem na fail

    friend std::ostream& operator<<(std::ostream&, const PickupTruck&);

};

void PickupTruck::deletePickupTruck() {

    for (char* s : schedule) {

        delete[] s; // kakto v car, triem dinamichni char masivi!

    }

}

void PickupTruck::copyPickupTruck(const PickupTruck& other) {

    for (char* s : other.schedule) {

        // kakto v car, za da nqma spodelena pamet, pravim nova char* koqto e s duljinata na neshtoto koeto iskame da kopirame i neq slagame vuv vektora
        char* newSched = new char[strlen(s) + 1];
        strcpy(newSched, s);
        this->schedule.push_back(newSched);

    }
    
}

bool PickupTruck::exists(const char* sched) {

    // ako daden task sushtestvuva v schedule vurni true inache false
    // btw tozi for se naricha for-each i e mn udoben za vektor
    for (char* s : schedule) {

        if (!strcmp(sched, s)) return true;

    }

    return false;

}

PickupTruck::PickupTruck(const char* model, const unsigned range, const size_t seats, const unsigned load) : 
Vehicle(model, range), Car(model, range, seats), Truck(model, range, load) {}

PickupTruck::PickupTruck(const PickupTruck& other) :
Vehicle(other.getModel(), other.getRange()), Car(other.getModel(), other.getRange(), other.getSeats()), Truck(other.getModel(), other.getRange(), other.getLoadCapacity()) {

    copyPickupTruck(other);

}

PickupTruck::~PickupTruck() {

    deletePickupTruck();

}

PickupTruck& PickupTruck::operator=(const PickupTruck& other) {

    if (this != &other) {

        deletePickupTruck();
        copyPickupTruck(other);

    }

    return *this;

}

void PickupTruck::setSchedule(const char* sched) {

    if (exists(sched)) throw "Task already exists!";

    // pak kato v car kogato dobavqme nov char* go pravim taka
    char* newSched = new char[strlen(sched) + 1];
    strcpy(newSched, sched);
    schedule.push_back(newSched);

}

const char* PickupTruck::getNextTask() {

    char* toBeRemoved = new char[strlen(schedule.back()) + 1];
    strcpy(toBeRemoved, schedule.back());
    schedule.pop_back();
    // namirame niza koito trqbva da mahnem, slagame go v temporary char* promenliva, vrushtame neq i sled tova mahame originala ot vektora

    return toBeRemoved;

}

unsigned PickupTruck::getMaxRange() const {

    return getRange() - (50 * passengers.size()) - (3 * getCurrentLoad());

}

const std::vector<char*>& PickupTruck::getScheduleList() const {

    return schedule;

}

Vehicle* PickupTruck::clone() const {

    // kloooningggg
    return new PickupTruck{*this};

}

void PickupTruck::write(std::ofstream& os) const {

    os << "Model: " << getModel() << ", Range: " << getRange() << ", Seats: " << getSeats() << ", Loading capacity: " << getLoadCapacity() << std::endl;

}

std::ostream& operator<<(std::ostream& os, const PickupTruck& obj) {

    os << "Model: " << obj.getModel() << ", Range: " << obj.getRange() << ", Seats: " << obj.getSeats() << ", Loading capacity: " << obj.getLoadCapacity();

    return os;

}

#endif // __PICKUPTRUCK_H__