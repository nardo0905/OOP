#ifndef __PLUGBOARD_H__
#define __PLUGBOARD_H__
#include "PermutationCypher.hpp"

class Plugboard : public PermutationCypher {

public:

    Plugboard();

    void connect(const char, const char);

};

Plugboard::Plugboard() : PermutationCypher("ABCDEFGHIJKLMNOPQRSTUVWXYZ"){}

void Plugboard::connect(const char ch1, const char ch2) {

    if (letters[ch2 - 'A'] != ch2 || letters[ch1 - 'A'] != ch1) throw std::invalid_argument("alredy connected!");

    letters[ch1 - 'A'] = ch2;
    letters[ch2 - 'A'] = ch1;
    
}

#endif // __PLUGBOARD_H__