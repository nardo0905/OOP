#include "Dish.hpp"
#include "MeatDish.hpp"
#include "SeafoodDish.hpp"
#include "SurfAndTurf.hpp"

int main() {

    char* const ingredients[100] = {

        "fish", "meat", "cucumber", "tomato", "potatoes"

    };

    Dish dish1{ingredients, 5, 120};
    dish1.print();

    MeatDish md1{ingredients, 5, 130, Meat::chicken};
    md1.print();

    SeafoodDish sd1{ingredients, 5, 90, "riba ton"};
    sd1.print();

    std::cout << "----------------------------" << std::endl;

    SurfAndTurf sf1{ingredients, 5, 140, Meat::beef, "siomga"};
    sf1.print();

    return 0;

}