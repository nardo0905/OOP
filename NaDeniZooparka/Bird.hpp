#ifndef __BIRD_H__
#define __BIRD_H__
#include "Animal.hpp"
#include <iostream>

class Bird : virtual public Animal {

private:

    double wingSpan;

public:

    Bird(const char* id = "", const std::string& name = "", const int age = 0, const std::string& species = "", const double ws = 0);

    void fly() const;
    Animal* clone() const;

};

Bird::Bird(const char* id, const std::string& name, const int age, const std::string& species, const double ws) : Animal(id, name, age, species), wingSpan(ws) {}

void Bird::fly() const {

    std::cout << "letiii" << std::endl;
    
}

Animal* Bird::clone() const {

    return new Bird{*this};
    
}


#endif // __BIRD_H__