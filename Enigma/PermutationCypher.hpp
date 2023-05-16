#ifndef __PERMUTATIONCYPHER_H__
#define __PERMUTATIONCYPHER_H__
#include "Cypher.hpp"
#include "cstring"
#include <algorithm>

class PermutationCypher : public Cypher {

protected:

    char letters[ALPHABETSIZE];

public:

    PermutationCypher(const char* letters);

    char encrypt(const char);

};

PermutationCypher::PermutationCypher(const char* letters) {

    if (strlen(letters) != ALPHABETSIZE) throw std::invalid_argument("Letters must be 26 characters!");

    for (size_t i = 0; i < ALPHABETSIZE; i++) {

        this->letters[i] = letters[i];

    }
    
}

char PermutationCypher::encrypt(const char ch) {

    return letters[ch - 'A'];
    
}

#endif // __PERMUTATIONCYPHER_H__