#ifndef __CEASERCYPHER_H__
#define __CEASERCYPHER_H__
#include "Cypher.hpp"

class CeaserCypher : public Cypher {

    int offset;

public:

    CeaserCypher(const int offset = 0);

    char encrypt(const char);
    char decrypt(const char);

    int getOffset() const;
    void setOffset(const size_t);

};

CeaserCypher::CeaserCypher(const int offset) : offset(offset){}

char CeaserCypher::encrypt(const char ch) {

    if (ch + offset > 'Z') {

        return ch - ALPHABETSIZE + offset;

    }

    return ch + offset;
    
}

char CeaserCypher::decrypt(const char ch) {

    if (ch - offset < 'A') {

        return ch + ALPHABETSIZE - offset;

    }

    return ch - offset;
    
}

int CeaserCypher::getOffset() const {

    return offset;
    
}

void CeaserCypher::setOffset(const size_t offset) {

    this->offset = offset;
    
}

#endif // __CEASERCYPHER_H__