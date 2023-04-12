#ifndef __POTROW_H__
#define __POTROW_H__
#include "Plant.hpp"
#include <iostream>
#include <cstring>

class PotRow {

private:

    Plant** plants;
    size_t count;

    void deletePotRow();
    void copy(const PotRow&);
    void copyMove(PotRow&&);

public:

    PotRow(const size_t count = 0);
    PotRow(const PotRow&);
    PotRow(PotRow&&);
    ~PotRow();

    PotRow& operator=(const PotRow&);
    PotRow& operator=(PotRow&&);

    void addPlant();

};

void PotRow::deletePotRow() {

    for (size_t i = 0; i < count; i++) {

        delete plants[i];

    }

    delete[] plants;
    
}

void PotRow::copy(const PotRow& other) {

    this->count = other.count;

    for (size_t i = 0; i < count; i++) {

        if (other.plants[i] == nullptr) {

            this->plants[i] = nullptr;

        }
        else {

            this->plants[i] = new Plant{*other.plants[i]};

        }

    }
    
}

void PotRow::copyMove(PotRow&& other) {

    this->count = other.count;
    this->plants = other.plants;

    other.count = 0;
    other.plants = nullptr;

}

PotRow::PotRow(const size_t count) : count(count) {

    this->plants = new Plant*[count]{nullptr};
    
}

PotRow::PotRow(const PotRow& other) {

    copy(other);

}

PotRow::PotRow(PotRow&& other) {

    copyMove((PotRow&&)other);

}

PotRow::~PotRow() {

    deletePotRow();

}

PotRow& PotRow::operator=(const PotRow& other) {

    if (this != &other) {

        deletePotRow();
        copy(other);

    }

    return *this;

}

PotRow& PotRow::operator=(PotRow&& other) {

    if (this != &other) {

        deletePotRow();
        copyMove((PotRow&&)other);

    }

    return *this;

}

#endif // __POTROW_H__