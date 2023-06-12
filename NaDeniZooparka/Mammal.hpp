#ifndef __MAMMAL_H__
#define __MAMMAL_H__
#include "Animal.hpp"
#include <iostream>

class Mammal : public Animal {

private:

    std::string furColour;

public:

    Mammal(const char* id = "", const std::string& name = "", const int age = 0, const std::string& species = "", const std::string& fc = "");

    void nurse() const;
    Animal* clone() const;

};

Mammal::Mammal(const char* id, const std::string& name, const int age, const std::string& species, const std::string& furcolour) : Animal(id, name, age, species), furColour(furcolour) {}

void Mammal::nurse() const {

    std::cout << "grrr" << std::endl;
    
}

Animal* Mammal::clone() const {

    return new Mammal{*this};
    
}

#endif // __MAMMAL_H__