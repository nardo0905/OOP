#ifndef __TRUCK_H__
#define __TRUCK_H__
#include "Vehicle.hpp"
#include <fstream>

class Truck : virtual public Vehicle {

protected:

    unsigned loadCapacity;
    unsigned currentLoad;

public:

    Truck(const char*, const unsigned, const unsigned);
    // tuk nqma golqma chetvorka, shtoto nqma dinamichna pamet

    void load(const unsigned); // slagame kg v kamiona
    void unload(const unsigned); // mahame ot kamiona

    unsigned getMaxRange() const;
    unsigned getLoadCapacity() const;
    unsigned getCurrentLoad() const;

    Vehicle* clone() const; // klonirane
    void write(std::ofstream&) const; // sushtoto kato v car

    friend std::ostream& operator<<(std::ostream&, const Truck&); // <<
    // katgo cqlo v tozi klas nqma nishto osobeno

};

Truck::Truck(const char* model, const unsigned range, const unsigned loadCapacity) : Vehicle(model, range), loadCapacity(loadCapacity) {}

void Truck::load(const unsigned kg) {

    if (currentLoad + kg > loadCapacity) throw "Not enough capacity in truck!";

    currentLoad += kg;

}

void Truck::unload(const unsigned kg) {

    if (currentLoad - kg < 0) throw "Doesn't have that much load!";

    currentLoad -= kg;

}

unsigned Truck::getMaxRange() const {

    return getRange() - currentLoad;

}

unsigned Truck::getLoadCapacity() const {

    return loadCapacity;

}

unsigned Truck::getCurrentLoad() const {

    return currentLoad;

}

Vehicle* Truck::clone() const {

    return new Truck{*this};

}

void Truck::write(std::ofstream& os) const {

    os << "Model: " << getModel() << ", Range: " << getRange() << ", Loading capacity: " << getLoadCapacity() << std::endl;

}

std::ostream& operator<<(std::ostream& os, const Truck& obj) {

    os << "Model: " << obj.getModel() << ", Range: " << obj.getRange() << ", Loading capacity: " << obj.getLoadCapacity();

    return os;

}

#endif // __TRUCK_H__