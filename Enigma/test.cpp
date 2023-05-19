#include <iostream>
#include "CeaserCypher.hpp"
#include "PermutationCypher.hpp"
#include "Reflector.hpp"
#include "Plugboard.hpp"

int main() {

    CeaserCypher ccTest{5};
    PermutationCypher pcTest{"EJMZALYXVBWFCRQUONTSPIKHGD"};
    Reflector rfTest{"UKW-B"};
    Plugboard pbTest;
    pbTest.connect('A', 'D');
    pbTest.connect('H', 'C');
    
    for (int i = 0; i < 26; i++) {

        // std::cout << (char)('A' + i) << " -> " << ccTest.encrypt('A' + i) << std::endl;
        // std::cout << (char)('A' + i) << " -> " << pcTest.encrypt('A' + i) << std::endl;
        std::cout << (char)('A' + i) << " -> " << rfTest.encrypt('A' + i) << std::endl;
        // std::cout << (char)('A' + i) << " -> " << pbTest.encrypt('A' + i) << std::endl;

    }

    return 0;

}