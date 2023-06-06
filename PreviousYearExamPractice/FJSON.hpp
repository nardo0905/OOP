#ifndef __FJSON_H__
#define __FJSON_H__
#include "StringPair.hpp"
#include "DateTimePair.hpp"
#include <vector>

class FJSON {

private:

    std::vector<Pair*> pairs;

    void deleteFJSON();
    void copy(const FJSON&);

public:

    FJSON(){}
    FJSON(const FJSON&);
    ~FJSON();
    FJSON& operator=(const FJSON&);

    void addPair(const Pair&);
    void removePair(const size_t);

    void toString() const;

};

void FJSON::deleteFJSON() { 

    for (Pair* t : pairs) {

        delete t;

    }
    
}

void FJSON::copy(const FJSON& other) {

    size_t otherSize = other.pairs.size();

    for (size_t i = 0; i < otherSize; i++) {

        this->pairs.push_back(other.pairs[i]->clone());

    }
    
}

FJSON::FJSON(const FJSON& other) {

    copy(other);
    
}

FJSON::~FJSON() {

    deleteFJSON();

}

FJSON& FJSON::operator=(const FJSON& other) {

    if (this != &other) {

        deleteFJSON();
        copy(other);

    } 

    return *this;
    
}

void FJSON::addPair(const Pair& pair) {

    pairs.push_back(pair.clone());

}

void FJSON::removePair(const size_t index) {

    pairs[index] = nullptr;

}

void FJSON::toString() const {

    std::cout << "[";

    size_t pairCount = pairs.size();

    for (size_t i = 0; i < pairCount - 1; i++) {

        pairs[i]->toString();

    }

    pairs[pairCount - 1]->toString();
    std::cout << "]" << std::endl;

}

#endif // __FJSON_H__