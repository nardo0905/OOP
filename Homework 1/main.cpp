#include <iostream>
#include "Plant.hpp"
#include "PlantsBook.hpp"
#include "PotRow.hpp"
#include "Greenhouse.hpp"
#include "GreenhouseDB.hpp"

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
    Plant test4{"hrizantema"};

    PlantsBook testBook{"testBook.txt"};

    try {

        testBook.addPlant(test);
        testBook.addPlant(test2);
        // testBook.addPlant(test3);
        testBook.addPlant(test4);

    } catch (const char* e) {

        std::cerr << e << std::endl;

    }

    std::cout << "---------------------------" << std::endl;

    PotRow testRow{4};
    testRow.addPlant(test);
    testRow.addPlant(test2);
    // testRow.addPlant(test3);
    testRow.addPlant(test4);
    std::cout << testRow;

    std::cout << "---------------------------" << std::endl;

    Greenhouse testGreenhouse{testBook, 5, 5, 5};
    testGreenhouse.addPlant(test);
    testGreenhouse.addPlant(test2);
    // testGreenhouse.addPlant(test3);
    testGreenhouse.addPlant(test4);
    testGreenhouse.addPlant(test4);
    testGreenhouse.addPlant(test4);
    testGreenhouse.addPlant(test4);
    testGreenhouse.addPlant(test4);
    testGreenhouse.addPlant(test4);
    testGreenhouse.addPlant(test2);
    testGreenhouse.addPlant(test2);
    testGreenhouse.addPlant(test2);
    testGreenhouse.addPlant(test);
    testGreenhouse.addPlant(test);

    std::cout << testGreenhouse << std::endl;

    Plant removed1 = testGreenhouse.removePlant(2, 0);
    Plant removed2 = testGreenhouse.removePlant(1, 1);
    std::cout << "Removed: " << removed1 << std::endl;
    std::cout << "Removed: " << removed2 << std::endl;

    std::cout << "---------------------------" << std::endl;
    std::cout << testGreenhouse << std::endl;
    testGreenhouse.statistics();

    GreenhouseDB testGreenhouseDB{testGreenhouse, "testDB.txt"};

    return 0;

}