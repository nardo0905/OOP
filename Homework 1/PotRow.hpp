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

    PotRow();
    PotRow(const size_t /*size = 0*/);
    PotRow(const PotRow&);
    PotRow(PotRow&&);
    ~PotRow();

    PotRow& operator=(const PotRow&);
    PotRow& operator=(PotRow&&);

    void addPlant(const Plant&);
    const Plant removePlant(const size_t);
    bool hasSpace() const;
    int plantCount() const;

    friend std::ostream& operator<<(std::ostream&, const PotRow&);

};

void PotRow::deletePotRow() {

    for (size_t i = 0; i < count; i++) {

        delete plants[i];
        // if (plants[i] != nullptr) delete plants[i];

    }

    delete[] plants;
    
}

void PotRow::copy(const PotRow& other) {

    this->count = other.count;
    this->plants = new Plant*[this->count];

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

PotRow::PotRow() {

    plants = nullptr;
    count = 0;

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

void PotRow::addPlant(const Plant& plant) {

    bool found = false;

    for (size_t i = 0; i < count; i++) {

        if (plants[i] == nullptr) {

            plants[i] = new Plant{plant};
            found = true;
            break;

        }

    }

    if (!found) throw "No place found for the plant!";

}

const Plant PotRow::removePlant(const size_t pos) {

    if (pos < 0 || pos >= count) throw "Index out of bounds!";
    Plant temp = {*plants[pos]};
    plants[pos] = nullptr;

    return temp;

}

bool PotRow::hasSpace() const {

    for (size_t i = 0; i < count; i++) {

        if (plants[i] == nullptr) {

            return true;

        }

    }

    return false;

}

int PotRow::plantCount() const {

    int pCount = 0;

    for (size_t i = 0; i < count; i++) {

        if (plants[i] != nullptr) pCount++;

    }

    return pCount;

}

std::ostream& operator<<(std::ostream& os, const PotRow& obj) {

    for (size_t i = 0; i < obj.count; i++) {

        if (obj.plants[i] != nullptr) {

            os << *obj.plants[i] << '\n';

        }

    }

    return os;

}

#endif // __POTROW_H__