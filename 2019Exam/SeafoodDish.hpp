#ifndef __SEAFOODDISH_H__
#define __SEAFOODDISH_H__
#include "Dish.hpp"

class SeafoodDish : virtual public Dish {

protected:

    char* seafood;

    void copySeafood(const SeafoodDish&);
    void deleteSeafoodDish();

public:

    SeafoodDish();
    SeafoodDish(char* const[100], const size_t, const unsigned, const char*);
    SeafoodDish(const SeafoodDish&);
    ~SeafoodDish();
    SeafoodDish& operator=(const SeafoodDish&);

    void print() const;

};

void SeafoodDish::copySeafood(const SeafoodDish& other) {

    this->seafood = new char[strlen(other.seafood) + 1];
    strcpy(this->seafood, other.seafood);

}

void SeafoodDish::deleteSeafoodDish() {

    delete[] seafood;

}

SeafoodDish::SeafoodDish() {

    seafood = nullptr;

}

SeafoodDish::SeafoodDish(char* const ingredients[100], const size_t num, const unsigned cookTime, const char* seafood) : Dish(ingredients, num, cookTime) {

    this->seafood = new char[strlen(seafood) + 1];
    strcpy(this->seafood, seafood);

}

SeafoodDish::SeafoodDish(const SeafoodDish& other) : Dish(other.ingredientsName, other.currNumOfIngredients, other.cookTime) {

    copy(other);

}

SeafoodDish::~SeafoodDish() {

    deleteSeafoodDish();

}

SeafoodDish& SeafoodDish::operator=(const SeafoodDish& other) {

    if (this != &other) {

        Dish::operator=(other);
        deleteSeafoodDish();
        copy(other);

    }

    return *this;

}

void SeafoodDish::print() const {

    Dish::print();
    std::cout << "Fish: " << seafood << std::endl;

}

#endif // __SEAFOODDISH_H__