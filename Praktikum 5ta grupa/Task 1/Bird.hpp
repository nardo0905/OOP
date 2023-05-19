#ifndef __BIRD_H__
#define __BIRD_H__
#include <string>
#include <iostream>
#include "Animal.hpp"

class Bird : public Animal {

private:

    std::string rescueCity;

public:

    Bird(const char* name = "", const int weight = 0, const std::string& rescueCity = "");

    int eat() const;
    Food getFood() const;
    Animal* copy() const;

    friend std::ostream& operator<<(std::ostream&, const Bird&);

};

Bird::Bird(const char* name, const int weight, const std::string& rescueCity) : Animal(name, weight), rescueCity(rescueCity){}

int Bird::eat() const {

    return 1;
    
}

Food Bird::getFood() const {

    return Plant;
    
}

Animal* Bird::copy() const {

    return new Bird(*this);
    
}

std::ostream& operator<<(std::ostream& os, const Bird& obj) {
    
    os << "Name: " << obj.getName() << ", Weight: " << obj.getWeight();
    os << "Eats: " << obj.getFood() << ", Rescue city: " << obj.rescueCity;

}

#endif // __BIRD_H__s