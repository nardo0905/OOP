#ifndef __MENU_H__
#define __MENU_H__
#include "Meal.h"

class Menu {

private:

    std::vector<Meal> menu;

public:

    Menu();

    void addMeal(const Meal& meal) const;
    void removeMeal(const Meal& meal) const;

    void printMenu() const;

};

#endif // __MENU_H__