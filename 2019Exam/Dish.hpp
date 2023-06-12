#ifndef __DISH_H__
#define __DISH_H__
#include <cstring>
#include <iostream>

class Dish {

protected:

    char* ingredientsName[100]; // [0] -> "pile", [1] -> "krastavici", ....
    size_t currNumOfIngredients;
    unsigned cookTime;

    void copy(const Dish&);
    void deleteDish();

public:

    Dish();
    Dish(char* const[100], const size_t, const unsigned);
    Dish(const Dish&);
    virtual ~Dish();
    Dish& operator=(const Dish&);

    void print() const;

};

void Dish::copy(const Dish& other) {

    this->currNumOfIngredients = other.currNumOfIngredients;

    for (size_t i = 0; i < currNumOfIngredients; i++) {

        this->ingredientsName[i] = new char[strlen(other.ingredientsName[i]) + 1];
        strcpy(this->ingredientsName[i], other.ingredientsName[i]);

    }

    this->cookTime = other.cookTime;
    
}

void Dish::deleteDish() {

    for (size_t i = 0; i < currNumOfIngredients; i++) {

        delete[] ingredientsName[i];
        
    }

}

Dish::Dish() {

    for (size_t i = 0; i < 100; i++) {

        ingredientsName[i] = nullptr;

    }

    this->currNumOfIngredients = 0;
    this->cookTime = 0;

}

Dish::Dish(char* const ingredientsList[100], const size_t numOfIngr, const unsigned cookTime) : currNumOfIngredients(numOfIngr), cookTime(cookTime) {

    for (size_t i = 0; i < currNumOfIngredients; i++) {

        this->ingredientsName[i] = new char[strlen(ingredientsList[i]) + 1];
        strcpy(this->ingredientsName[i], ingredientsList[i]);

    }

}

Dish::Dish(const Dish& other) {

    copy(other);

}

Dish::~Dish() {

    deleteDish();

}

Dish& Dish::operator=(const Dish& other) {

    if (this != &other) {

        deleteDish();
        copy(other);

    }

    return *this;

}

void Dish::print() const {

    std::cout << "Ingredients: " << std::endl;
    for (size_t i = 0; i < currNumOfIngredients; i++) {

        std::cout << ingredientsName[i] << ", ";

    }
    std::cout << std::endl << "Cook time: " << cookTime << std::endl;

}

#endif // __DISH_H__