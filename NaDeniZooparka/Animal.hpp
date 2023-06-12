#ifndef __ANIMAL_H__
#define __ANIMAL_H__
#include <cstring>
#include <string>

class Animal {

private:

    char* id;
    std::string name;
    int age;
    std::string species;

    void copy(const Animal&);
    void deleteAnimal();

public:

    Animal();
    Animal(const char*, const std::string&, const int, const std::string&);
    Animal(const Animal&);
    Animal& operator=(const Animal&);
    virtual ~Animal();

    const char* getId() const;
    const std::string& getName() const;
    int getAge() const;
    const std::string& getSpecies() const;

    virtual Animal* clone() const = 0;

};

void Animal::copy(const Animal& other) {

    this->id = new char[strlen(other.id) + 1];
    strcpy(this->id, other.id);
    this->name = other.name;
    this->age = other.age;
    this->species = other.species;
    
}

void Animal::deleteAnimal() {

    delete[] id;
    
}

Animal::Animal() : name(""), age(0), species("") {

    id = nullptr;
    
}

Animal::Animal(const char* id, const std::string& name, const int age, const std::string& species) : name(name), age(age), species(species) {

    this->id = new char[strlen(id) + 1];
    strcpy(this->id, id);
    
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

const char* Animal::getId() const {

    return id;
    
}

const std::string& Animal::getName() const {

    return name;
    
}

int Animal::getAge() const {

    return age;
    
}

const std::string& Animal::getSpecies() const {

    return species;
    
}

#endif // __ANIMAL_H__