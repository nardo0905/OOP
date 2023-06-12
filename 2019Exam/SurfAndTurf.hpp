#ifndef __SURFANDTURF_H__
#define __SURFANDTURF_H__
#include "MeatDish.hpp"
#include "SeafoodDish.hpp"

class SurfAndTurf : public MeatDish, public SeafoodDish {

public:

    SurfAndTurf(char* const[100], const size_t, const unsigned, const Meat&, const char*);

    void print() const;

};

SurfAndTurf::SurfAndTurf(char* const ingred[100], const size_t num, const unsigned cookTime, const Meat& meat, const char* fish) :
Dish(ingred, num, cookTime), MeatDish(ingred, num, cookTime, meat), SeafoodDish(ingred, num, cookTime, fish) {}

void SurfAndTurf::print() const {

    MeatDish::print();
    std::cout << "Fish: " << seafood << std::endl;

}

#endif // __SURFANDTURF_H__