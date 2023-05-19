#ifndef __MAMAL_H__
#define __MAMAL_H__
#include "Animal.hpp"
#include <iostream>

class Mamal : public Animal {

private:

    char* adopterName;

    void copy(const Mamal&);
    void deleteMamal();

public:

    Mamal(const char* name = "", const int weight = 0, const char* adopterName = "");
    Mamal(const Mamal&);
    ~Mamal();
    Mamal& operator=(const Mamal&);

    int eat() const;
    Food getFood() const;
    Animal* copy() const;

    friend std::ostream& operator<<(std::ostream&, const Mamal&);

};

void Mamal::copy(const Mamal& other) {

    this->adopterName = new char[strlen(other.adopterName) + 1];
    strcpy(this->adopterName, other.adopterName);
    
}

void Mamal::deleteMamal() {

    delete[] adopterName;
    
}

Mamal::Mamal(const char* name, const int weight, const char* adopterName) : Animal(name, weight) {

    this->adopterName = new char[strlen(adopterName) + 1];
    strcpy(this->adopterName, adopterName);
    
}

Mamal::Mamal(const Mamal& other) : Animal(other.getName(), other.getWeight()) {
    
    copy(other);

}

Mamal::~Mamal() {

    deleteMamal();
    
}

Mamal& Mamal::operator=(const Mamal& other) {

    if (this != &other) {

        deleteMamal();
        copy(other);

    }

    return *this;
    
}

int Mamal::eat() const {

    return 5;
    
}

Food Mamal::getFood() const {

    return Food::Both; // qde i meso i treva
    
}

Animal* Mamal::copy() const {

    return new Mamal(*this);
    
}

std::ostream& operator<<(std::ostream& os, const Mamal& obj) {

    os << "Name: " << obj.getName() << ", Weight: " << obj.getWeight();
    os << "Eats: " << obj.getFood() << ", Adopter name: " << obj.adopterName;
    
}

#endif // __MAMAL_H__