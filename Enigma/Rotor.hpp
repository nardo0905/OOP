#ifndef __ROTOR_H__
#define __ROTOR_H__
#include "CeaserCypher.hpp"
#include "PermutationCypher.hpp"

class Rotor : public Cypher {

    CeaserCypher cc;
    PermutationCypher pc;

    static const char* getPermutation(const char*);

public:

    Rotor(const int, const char*);

    char encrypt(const char ch);
    void step();

};

const char* Rotor::getPermutation(const char* type) {
    
    if (!strcmp(type, "I")) return "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
    if (!strcmp(type, "II")) return "AJDKSIRUXBLHWTMCQGZNPYFVOE";
    if (!strcmp(type, "III")) return "BDFHJLCPRTXVZNYEIWGAKMUSQO";
    if (!strcmp(type, "IV")) return "ESOVPZJAYQUIRHXLNFTGKDCMWB";
    if (!strcmp(type, "V")) return "VZBRGITYUPSDNHLXAWMJQOFECK";
    throw std::invalid_argument("invalid type");

}

Rotor::Rotor(const int offset, const char* type) : pc{getPermutation(type)} {
    
    cc.setOffset(offset);

}

char Rotor::encrypt(const char ch) {

    char res = cc.encrypt(ch);
    res = pc.encrypt(res);
    res = cc.decrypt(res);
    step();

    return res;
    
}

void Rotor::step() {

    const size_t offset = cc.getOffset();
    cc.setOffset(offset + 1);
    
}

#endif // __ROTOR_H__