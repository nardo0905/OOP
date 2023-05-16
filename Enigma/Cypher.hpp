#ifndef __CYPHER_H__
#define __CYPHER_H__
#include <iostream>

class Cypher {

public:

    static const size_t ALPHABETSIZE = 'Z' - 'A' + 1;

    virtual ~Cypher() = default;
    virtual char encrypt(const char) = 0;

};

#endif // __CYPHER_H__