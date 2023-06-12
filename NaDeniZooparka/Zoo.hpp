#ifndef __ZOO_H__
#define __ZOO_H__
#include "Mammal.hpp"
#include "Bird.hpp"
#include "Reptile.hpp"
#include "Amphibian.hpp"
#include <vector>

class Zoo {

private:

    std::vector<Animal*> animals;

    void copy(const Zoo&);
    void deleteZoo();

public:

    Zoo() {};
    Zoo(const Zoo&);
    ~Zoo();
    Zoo& operator=(const Zoo&);

    void addAnimal(const Animal&);
    void removeAnimal(const int);

    void printAnimals() const;
    Animal& getOldestAnimal() const;
    std::vector<Animal*> getAllAnimalsFromSpecies(const std::string&) const;
    // void printCountOfAllTypes() const; tova nqma da go pravq

};

void Zoo::copy(const Zoo& other) {

    for (Animal* a : other.animals) {

        this->animals.push_back(a->clone());

    }
    
}

void Zoo::deleteZoo() {

    for (Animal* a : animals) {

        delete a;

    }

}

Zoo::Zoo(const Zoo& other) {

    copy(other);

}

Zoo::~Zoo() {

    deleteZoo();

}

Zoo& Zoo::operator=(const Zoo& other) {

    if (this != &other) {

        deleteZoo();
        copy(other);

    }

    return *this;

}

void Zoo::addAnimal(const Animal& animal) {

    animals.push_back(animal.clone());

}

void Zoo::removeAnimal(const int index) {

    animals.erase(animals.begin() + index);

}

void Zoo::printAnimals() const {

    for (Animal* a : animals) {

        std::cout << a->getName() << std::endl;

    }

}

Animal& Zoo::getOldestAnimal() const {

    int oldestAge = 0;
    std::string nameOfOldest{};

    for (Animal* a : animals) {

        if (a->getAge() > oldestAge) {

            oldestAge = a->getAge();
            nameOfOldest = a->getName();

        }

    }

    for (Animal* a : animals) {

        if (a->getName() == nameOfOldest) {

            return *a;

        }

    }

    return *animals[0];

}

std::vector<Animal*> Zoo::getAllAnimalsFromSpecies(const std::string& species) const {

    std::vector<Animal*> animalsFromSpecies;

    for (Animal* a : animals) {

        if (a->getSpecies() == species) {

            animalsFromSpecies.push_back(a->clone());

        }

    }

    return animalsFromSpecies;

}

#endif // __ZOO_H__