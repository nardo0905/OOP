#ifndef __AMPHIBIAN_H__
#define __AMPHIBIAN_H__
#include "Bird.hpp"
#include "Reptile.hpp"

class Amphibian : public Bird, public Reptile {

private:

    char* kakSeKazvaSharkataMu; // slqagam char* tuka za da ti pkaja kak raboti diamanteniq problem s dinamichna pamet

    void copy(const Amphibian&);
    void deleteAmphibian();

public:

    Amphibian();
    Amphibian(const char*, const std::string&, const int, const std::string&, const double, const std::string&, const char*);
    Amphibian(const Amphibian&);
    ~Amphibian();
    Amphibian& operator=(const Amphibian&);

    void zvuk() const;
    Animal* clone() const;

};

void Amphibian::copy(const Amphibian& other) {

    this->kakSeKazvaSharkataMu = new char[strlen(other.kakSeKazvaSharkataMu) + 1];
    strcpy(this->kakSeKazvaSharkataMu, other.kakSeKazvaSharkataMu);

}

void Amphibian::deleteAmphibian() {

    delete[] kakSeKazvaSharkataMu;

}

Amphibian::Amphibian() {

    this->kakSeKazvaSharkataMu = nullptr;

}

Amphibian::Amphibian(const char* id, const std::string& name, const int age, const std::string& species, const double wingSpan, const std::string& scaleColour, const char* sharka) :
Animal(id, name, age, species), Bird(id, name, age, species, wingSpan), Reptile(id, name, age, species, scaleColour) {

    this->kakSeKazvaSharkataMu = new char[strlen(sharka) + 1];
    strcpy(kakSeKazvaSharkataMu, sharka);

}

Amphibian::Amphibian(const Amphibian& other) : Animal(other), Bird(other), Reptile(other) {

    copy(other);

}

Amphibian::~Amphibian() {

    deleteAmphibian();
    
}

Amphibian& Amphibian::operator=(const Amphibian& other) {

    if (this != &other) {

        deleteAmphibian();
        Bird::operator=(other);
        Reptile::operator=(other);
        copy(other);

    }

    return *this;

}

void Amphibian::zvuk() const {

    std::cout << "<3" << std::endl;

}

Animal* Amphibian::clone() const {

    return new Amphibian{*this};

}

#endif // __AMPHIBIAN_H__