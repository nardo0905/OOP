#include <iostream>
#include "Plant.hpp"
#include "PlantsBook.hpp"

int main() {

    Plant test{"Petuniq"};
    test.setEnv(2);
    test.setWatFreq(12);
    std::cout << test << std::endl;
    Plant test2{Plant{"orhideq"}};
    test2.setEnv(1);
    test2.setWatFreq(14);
    std::cout << test2 << std::endl;
    // Plant test3{"f"};
    // std::cin >> test3;

    PlantsBook testBook{"testBook.txt"};

    try {

        testBook.addPlant(test);
        testBook.addPlant(test2);
        // testBook.addPlant(test3);

    } catch (const char* e) {

        std::cerr << e << std::endl;

    }

    return 0;

}