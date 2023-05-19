#ifndef __ZOO_H__
#define __ZOO_H__
#include "Mamal.hpp"
#include "Bird.hpp"

class Zoo {

private:

    std::string name;
    Animal** animals;
    size_t count;
    int kgOfPlants;
    int kgOfMeat;

    void copy(const Zoo&);
    void deleteZoo();

public:

    Zoo(const std::string& name = "", const int kgOfPlants = 0, const int kgOfMeat = 0);
    Zoo(const Zoo&);
    ~Zoo();
    Zoo& operator=(const Zoo&);

    void addAnimal(const Animal&);
    size_t getCount() const;
    void feedAnimals();

};

void Zoo::copy(const Zoo& other) {

    this->name = other.name;
    this->count = other.count;
    this->animals = new Animal*[count];

    for (size_t i = 0; i < count; i++) {

        this->animals[i] = other.animals[i]->copy();

    }

    this->kgOfPlants = other.kgOfPlants;
    this->kgOfMeat = other.kgOfMeat;
    
}

void Zoo::deleteZoo() {

    for (size_t i = 0; i < count; i++) {

        delete animals[i];

    }

    delete[] animals;

}

Zoo::Zoo(const std::string& name = "", const int kgOfPlants = 0, const int kgOfMeat = 0) : name(name), kgOfPlants(kgOfPlants), kgOfMeat(kgOfMeat) {

    this->animals = nullptr;
    this->count = 0;

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

    if (this->count == 0) {

        deleteZoo();
        count++;
        this->animals = new Animal*[count];
        animals[0] = animal.copy();
        return;

    }

    Animal** temp = new Animal*[count + 1];

    for (size_t i = 0; i < count; i++) {

        temp[i] = animals[i]->copy();

    }
    temp[count] = animal.copy();
    count++;

    deleteZoo();
    this->animals = temp;

}

size_t Zoo::getCount() const {

    return count;

}

void Zoo::feedAnimals() {

    for (size_t i = 0; i < count; i++) {

        switch(animals[i]->getFood()) {

            case Food::Plant:
                if (kgOfPlants - animals[i]->eat() < 0) throw "Not enough food!";
                else {

                    kgOfPlants -= animals[i]->eat();
                
                }
                break;
            case Food::Meat:
                if (kgOfMeat - animals[i]->eat() < 0) throw "Not enough food!";
                else {

                    kgOfMeat -= animals[i]->eat();
                
                }
                break;
            case Food::Both:
                if (kgOfPlants - animals[i]->eat() < 0 || kgOfMeat - animals[i]->eat() < 0) throw "Not enough food!";
                else {

                    kgOfPlants -= animals[i]->eat();
                    kgOfMeat -= animals[i]->eat();
                
                }
                break;
            

        }

    }

}

#endif // __ZOO_H__