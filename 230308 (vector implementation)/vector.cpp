#include <iostream>
#include "IntVector.hpp"

int main() {

    Vector vec{};
    vec.append(1);
    vec.append(4);
    vec.append(6);
    vec.print();

    vec.append(1);
    vec.append(2);
    vec.append(3);
    vec.append(4);
    vec.append(5);
    vec.append(6);
    vec.append(7);
    vec.append(8);
    vec.append(9);
    vec.append(10);
    vec.append(11);
    vec.append(12);
    vec.print();

    vec.insert(2, 9);
    vec.insert(5, 12);
    vec.print();

    vec.pop();
    vec.print();

    vec.append(120);
    vec.print();

    vec.remove(2);
    vec.print();

    // vec.clear();
    // vec.print();

    std::cout << vec.isEmpty() << std::endl;
    std::cout << vec.size() << std::endl;
    std::cout << vec.get(2) << std::endl;

    vec.set(2, 420);
    std::cout << vec.get(2) << std::endl;
    std::cout << vec.find(120) << std::endl;

    return 0;

}