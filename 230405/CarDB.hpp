#ifndef __CARDB_H__
#define __CARDB_H__
#include <iostream>
#include <fstream>
#include <string>
#include "Reservation.hpp"
#include "Car.hpp"

class CarDB {

    std::string filename;

public:

    CarDB(const std::string& filename = "");

    void add(const Car&);
    Car& search(const unsigned id) const;
    void reserve(const unsigned id) const;

};

#endif // __CARDB_H__