#ifndef __MEATDISH_H__
#define __MEATDISH_H__
#include "Dish.hpp"

enum Meat {

    chicken,
    beef,
    pork,
    duck

};

class MeatDish : virtual public Dish {

private:

    Meat meat;

public:

    MeatDish(char* const[100], const size_t, const unsigned, const Meat&);

    void print() const;

};

MeatDish::MeatDish(char* const ingredients[100], const size_t numIngr, const unsigned cookTime, const Meat& meat) : Dish(ingredients, numIngr, cookTime), meat(meat) {}

void MeatDish::print() const {

    Dish::print();
    std::cout << "Protein: " << meat << std::endl;

}

#endif // __MEATDISH_H__