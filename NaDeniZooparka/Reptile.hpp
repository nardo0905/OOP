#ifndef __REPTILE_H__
#define __REPTILE_H__
#include "Animal.hpp"
#include <iostream>

class Reptile : virtual public Animal {

private:

    std::string scalePattern;

public:

    Reptile(const char* id = "", const std::string& name = "", const int age = 0, const std::string& species = "", const std::string& sp = "");

    void bask() const;
    Animal* clone() const;

};

Reptile::Reptile(const char* id, const std::string& name, const int age, const std::string& species, const std::string& sp) : Animal(id, name, age, species), scalePattern(sp) {}

void Reptile::bask() const {

    std::cout << "gushter" << std::endl;
    
}

Animal* Reptile::clone() const {

    return new Reptile{*this};
    
}


#endif // __REPTILE_H__