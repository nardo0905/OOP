#include "Rational.hpp"
#include <iostream>

int main() {

    Rational rat1{2, 3};
    Rational rat2{1, 2};
    Rational rat3{5,3};
    Rational rat4{4,6};

    // std::cout << rat1.compare(rat2) << std::endl;
    std::cout << (rat1 < rat2) << std::endl;
    std::cout << (rat1 <= rat2) << std::endl;
    std::cout << (rat1 < rat3) << std::endl;
    std::cout << (rat1 < rat4) << std::endl;
    std::cout << (rat1 == rat4) << std::endl;
    std::cout << rat1 << std::endl;

    return 0;

}