#include <iostream>
#include <fstream>
#include <string>
#include "Operation.hpp"

int main() {

    std::string file = "test.bin";

    Operation test;

    // int one = 1;
    // int two = 2;
    // test.create(one, file);
    // test.create(two, file);
    int testRead = test.read<int>(file, 1);
    std::cout << testRead << std::endl;
    test.update(file, 5, 1);
    testRead = test.read<int>(file, 1);
    std::cout << testRead << std::endl;

    return 0;

}