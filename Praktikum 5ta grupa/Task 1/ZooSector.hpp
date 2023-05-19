#ifndef __ZOOSECTOR_H__
#define __ZOOSECTOR_H__
#include "Mamal.hpp"
#include "Bird.hpp"
#include <vector>

template <typename T>
class ZooSector {

private:

    std::vector<T> animals;
    int x, y;

public:

    ZooSector(const int, const int);

    void addAnimal(const T&);
    void print() const;

};

template<typename T>
ZooSector<T>::ZooSector(const int x, const int y) {

    this->x = x;
    this->y = y;
    
}

template<typename T>
void ZooSector<T>::addAnimal(const T& animal) {

    animals.push_back(animal);
    
}

template<typename T>
void ZooSector<T>::print() const {

    for (T animal : animals) {

        std::cout << animal;

    }
    
}

#endif // __ZOOSECTOR_H__