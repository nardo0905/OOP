#ifndef __REFLECTOR_H__
#define __REFLECTOR_H__
#include <cstring>
#include "PermutationCypher.hpp"

class Reflector : public PermutationCypher {

    static const char* getPermutation(const char*);

public:

    Reflector(const char*);

};

Reflector::Reflector(const char* type) : PermutationCypher(getPermutation(type)){}

const char* Reflector::getPermutation(const char* type) {

    if (!strcmp(type, "UKW-A")) return "EJMZALYXVBWFCRQUONTSPIKHGD";
    if (!strcmp(type, "UKW-B")) return "YRUHQSLDPXNGOKMIEBFZCWVJAT";
    if (!strcmp(type, "UKW-C")) return "FVPJIAOYEDRZXWGCTKUQSBNMHL";
    throw std::invalid_argument("invalid type");
    
}

#endif // __REFLECTOR_H__