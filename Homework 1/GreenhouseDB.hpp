#ifndef __GREENHOUSEDB_H__
#define __GREENHOUSEDB_H__
#include <iostream>
#include <fstream>
#include "Plant.hpp"
#include "PlantsBook.hpp"
#include "PotRow.hpp"
#include "Greenhouse.hpp"

class GreenhouseDB {

private:

    char dbName[129];
    Greenhouse greenhouse;

public:

    GreenhouseDB(const Greenhouse&, const char* dbName = "");

    void update();

};

GreenhouseDB::GreenhouseDB(const Greenhouse& greenhouse, const char* dbName) {

    strcpy(this->dbName, dbName);
    this->greenhouse = greenhouse;
    update();

}

void GreenhouseDB::update() {

    std::ofstream fout(dbName);
    if (!fout) throw "File not found!";
    fout << this->greenhouse;
    fout.close();

}

#endif // __GREENHOUSEDB_H__