#include <iostream>
#include "Plant.hpp"

int main() {

    Plant test{"Petuniq"};
    test.setEnv(2);
    test.setWatFreq(12);
    std::cout << test << std::endl;
    Plant test2{Plant{"orhideq"}};
    test2.setEnv(1);
    test2.setWatFreq(14);
    std::cout << test2 << std::endl;

    return 0;

}