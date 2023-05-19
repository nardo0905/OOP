#ifndef __ANIMAL_H__
#define __ANIMAL_H__
#include <cstring>

enum Food{Plant, Meat, Both};

class Animal {

private:

    char* name;
    int weight;

    void copy(const Animal&);
    void deleteAnimal();

public:

    Animal(const char* name = "", const int weight = 0);
    Animal(const Animal&);
    Animal& operator=(const Animal&);
    virtual ~Animal();

    const char* getName() const {

        return name;

    }

    int getWeight() const {

        return weight;

    }

    virtual int eat() const = 0;
    virtual Food getFood() const = 0;
    virtual Animal* copy() const = 0;

};

void Animal::copy(const Animal& other) {

    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    this->weight = other.weight;
    
}

void Animal::deleteAnimal() {

    delete[] name;
    
}

Animal::Animal(const char* name, const int weight) : weight(weight) {

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

}

Animal::Animal(const Animal& other) {

    copy(other);
    
}

Animal& Animal::operator=(const Animal& other) {

    if (this != &other) {

        deleteAnimal();
        copy(other);

    }
    
    return *this;

}

Animal::~Animal() {

    deleteAnimal();
    
}

#endif // __ANIMAL_H__