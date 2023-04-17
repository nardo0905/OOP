#ifndef __GREENHOUSE_H__
#define __GREENHOUSE_H__
#include "Plant.hpp"
#include "PotRow.hpp"
#include "PlantsBook.hpp"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

class Greenhouse {

private:

    PlantsBook book;
    PotRow pots[3];// 0 - sunny, 1 - neutral, 2 - shadow

    void copy(const Greenhouse&);

public:

    Greenhouse();
    Greenhouse(const PlantsBook&, const size_t, const size_t, const size_t);
    Greenhouse(const Greenhouse&);

    Greenhouse& operator=(const Greenhouse&);

    void addPlant(Plant&);
    const Plant removePlant(const size_t, const size_t);
    void statistics() const;

    friend std::ostream& operator<<(std::ostream&, const Greenhouse&);

};

void Greenhouse::copy(const Greenhouse& other) {

    this->book = other.book;
    this->pots[0] = other.pots[0];
    this->pots[1] = other.pots[1];
    this->pots[2] = other.pots[2];

}

Greenhouse::Greenhouse() {

    this->book = PlantsBook();
    this->pots[0] = PotRow();
    this->pots[1] = PotRow();
    this->pots[2] = PotRow();

}

Greenhouse::Greenhouse(const PlantsBook& book, const size_t sunnySize, const size_t neutralSize, const size_t shadowSize) {

    this->book = book;
    pots[0] = PotRow(sunnySize);
    pots[1] = PotRow(neutralSize);
    pots[2] = PotRow(shadowSize);

}

Greenhouse::Greenhouse(const Greenhouse& other) {

    copy(other);

}

Greenhouse& Greenhouse::operator=(const Greenhouse& other) {

    if (this != &other) {

        copy(other);

    }

    return *this;

}

void Greenhouse::addPlant(Plant& plant) {

    if(!book.exists(plant)) throw "Plant is not in book!";

    int envType = -1;
    int preferedWatFreq = -1;
    size_t plantCountBook = book.getCount();

    for (size_t i = 0; i < plantCountBook; i++) {

        if (!strcmp(plant.getType(), book.getPlant(i).getType())) {

            envType = book.getPlant(i).getEnvType();
            preferedWatFreq = book.getPlant(i).getFreq();
            break;

        }

    }

    bool freeSpaces[3]{false};
    int freeSpaceCount = 0;

    for (int i = 0; i < 3; i++) {

        if (pots[i].hasSpace()) {

            freeSpaces[i] = true;
            freeSpaceCount++;

        }

    }

    if (freeSpaces[envType]) {

        plant.setWatFreq(preferedWatFreq);
        pots[envType].addPlant(plant);
        return;

    }

    if (freeSpaceCount == 1) {

        int freeSpace = -1;
        for (int i = 0; i < 3; i++) {

            if (freeSpaces[i]) {

                freeSpace = i;
                break;

            }

        }

        int newPrefer = preferedWatFreq + (envType - freeSpace);
        if (newPrefer <= 0) newPrefer = 1;
        plant.setWatFreq(newPrefer);
        pots[freeSpace].addPlant(plant);
        return;

    }

    if (freeSpaceCount == 2) {

        int firstFreeSpot = -2;
        int secondFreeSpot = -1;
        bool firstFound = false;

        for (int i = 0; i < 3; i++) {

            if (freeSpaces[i]) {

                if (!firstFound) {

                    firstFreeSpot = i;
                    firstFound = true;

                }
                else {

                    secondFreeSpot = i;
                    break;

                }

            }

        }

        int finalSpot = -1;

        std::srand(std::time(nullptr));
        double rnd;
        for (int i = 0; i < 100; i++) {

            rnd = (std::rand() * 1.0) / RAND_MAX;

        }
        rnd = (std::rand() * 1.0) / RAND_MAX;
        // std::cout << rnd << std::endl; magick

        if (rnd <= 0.5) finalSpot = firstFreeSpot;
        else finalSpot = secondFreeSpot;

        int newPrefer = preferedWatFreq + (envType - finalSpot);
        if (newPrefer <= 0) newPrefer = 1;
        plant.setWatFreq(newPrefer);
        pots[finalSpot].addPlant(plant);
        return;

    }

}

const Plant Greenhouse::removePlant(const size_t pot, const size_t pos) {

    return pots[pot].removePlant(pos);

}

void Greenhouse::statistics() const {

    std::cout << "Sunny plants: " << pots[0].plantCount() << std::endl;
    std::cout << "Neutral plants: " << pots[1].plantCount() << std::endl;
    std::cout << "Shadow plants: " << pots[2].plantCount() << std::endl;

}

std::ostream& operator<<(std::ostream& os, const Greenhouse& obj) {

    for (size_t i = 0; i < 3; i++) {

        os << i << '\n' << obj.pots[i];

    }

    return os;

}

#endif // __GREENHOUSE_H__