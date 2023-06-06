#ifndef __RESTAURANT_H__
#define __RESTAURANT_H__
#include "Menu.h"
#include "Client.h"

class Restaurant {

private:

    std::string name, city, address, email, phone;
    double averageRating;
    unsigned numOfRatings;
    Menu menu;
    std::vector<Client*> subscribers;

public:

    Restaurant();
    Restaurant(const std::string& name, const std::string& city, const std::string& address, const std::string& email, const std::string& phone, const Menu& menu);
    Restaurant(const Restaurant&);
    ~Restaurant();
    Restaurant& operator=(const Restaurant&);

    void addItemToMenu(const Meal& meal);
    void removeItemFromMenu(const Meal& meal);

    void rate(unsigned rating);

};

#endif // __RESTAURANT_H__