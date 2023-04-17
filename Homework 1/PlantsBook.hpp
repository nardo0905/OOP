#ifndef _PLANTBOOK_
#define _PLANTBOOK_
#include "Plant.hpp"
#include <iostream>
#include <fstream>
#include <cstring>

class PlantsBook {

private:

    char bookName[129];
    Plant** plants;
    size_t plantsCount;

    void sort();
    void updateFile();

    void copy(const PlantsBook&);
    void copyMove(PlantsBook&&);
    void deletePlantBook();

public:

    PlantsBook();
    PlantsBook(const char* /*filename = ""*/);
    PlantsBook(const PlantsBook&);
    PlantsBook(PlantsBook&&);
    ~PlantsBook();

    PlantsBook& operator=(const PlantsBook&);
    PlantsBook& operator=(PlantsBook&&);

    size_t getCount() const;
    const Plant& getPlant(const int) const;

    bool exists(const Plant&);
    void addPlant(Plant&);

};

void PlantsBook::sort() {

    for (size_t i = 0; i < plantsCount; i++) {

        for (size_t j = 0; j < plantsCount - i - 1; j++) {

            if (*plants[j] < *plants[j + 1]) {

                Plant temp = *plants[j];
                *plants[j] = *plants[j + 1];
                *plants[j + 1] = temp;

            }

        }

    }
    
}

void PlantsBook::updateFile() {

    std::ofstream fout(bookName);

    for (size_t i = 0; i < plantsCount; i++) {

        // std::cout << plants[i]->getPref() << std::endl;
        fout << *plants[i] << std::endl;

    }

    fout.close();
    
}

bool PlantsBook::exists(const Plant& obj) {

    for (size_t i = 0; i < plantsCount; i++) {

        if (obj.equalTypes(*plants[i])) return true;

    }

    return false;
    
}

void PlantsBook::copy(const PlantsBook& other) {

    strcpy(this->bookName, other.bookName);
    this->plantsCount = other.plantsCount;

    plants = new Plant*[plantsCount];

    for (size_t i = 0; i < plantsCount; i++) {

        plants[i] = new Plant{*other.plants[i]};

    }
    
}

void PlantsBook::copyMove(PlantsBook&& other) {

    strcpy(this->bookName, other.bookName);
    this->plantsCount = other.plantsCount;
    this->plants = other.plants;

    strcpy(other.bookName, "");
    other.plantsCount = 0;
    other.plants = nullptr;
    
}

void PlantsBook::deletePlantBook() {

    for (size_t i = 0; plants != nullptr && i < plantsCount; i++) {

        delete plants[i];

    }

    delete[] plants;
    
}

PlantsBook::PlantsBook() {

    strcpy(this->bookName, "");
    plants = nullptr;
    plantsCount = 0;

}

PlantsBook::PlantsBook(const char* filename) {

    strcpy(this->bookName, filename);
    //plants = new Plant*[plantsCount];
    plants = nullptr;
    plantsCount = 0;
    
}

PlantsBook::PlantsBook(const PlantsBook& other) {

    copy(other);
    
}

PlantsBook::PlantsBook(PlantsBook&& other) {
    
    copyMove((PlantsBook&&)other);
    
}

PlantsBook::~PlantsBook() {

    deletePlantBook();
    
}

PlantsBook& PlantsBook::operator=(const PlantsBook& that) {

    if (this != &that) {

        deletePlantBook();
        copy(that);

    }

    return *this;
    
}

PlantsBook& PlantsBook::operator=(PlantsBook&& that) {

    if (this != &that) {

        deletePlantBook();
        copyMove((PlantsBook&&)that);

    }

    return *this;
    
}

size_t PlantsBook::getCount() const {

    return plantsCount;

}

const Plant& PlantsBook::getPlant(const int index) const {

    return *plants[index];

}

void PlantsBook::addPlant(Plant& plant) {

    if(exists(plant)) throw "Plant type already exists!";

    if(plant.getEnvType() == -1) {

        plant.setEnv(1);

    }

    if(plant.getFreq() == -1) {

        plant.setWatFreq(3);

    }

    Plant** temp = new Plant*[plantsCount + 1];

    if (plantsCount == 0) {

        temp[0] = new Plant{plant};
        plantsCount++;

        deletePlantBook();
        plants = temp;
        temp = nullptr;

        updateFile();
        return;

    }

    for (size_t i = 0; i < plantsCount; i++) {

        temp[i] = new Plant{*plants[i]};

    }

    temp[plantsCount] = new Plant{plant};
    plantsCount++;

    deletePlantBook();
    plants = temp;
    temp = nullptr;

    sort();
    updateFile();

}

#endif