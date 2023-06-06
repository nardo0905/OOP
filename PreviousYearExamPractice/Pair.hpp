#ifndef __PAIR_H__
#define __PAIR_H__
#include <cstring>
#include <string>

class Pair {

private:

    char* key;

    void deletePair() {

        delete[] key;

    }

    void copy(const Pair& other) {

        this->key = new char[strlen(other.key) + 1];
        strcpy(this->key, other.key);

    }

public:

    Pair(const char* key) {

        this->key = new char[strlen(key) + 1];
        strcpy(this->key, key);

    }

    Pair(const Pair& other) {

        copy(other);

    }

    Pair& operator=(const Pair& other) {

        if (this != &other) {

            deletePair();
            copy(other);

        }

        return *this;

    }

    const char* getKey() const {

        return key;

    }

    virtual ~Pair() {

        deletePair();

    }

    virtual Pair* clone() const = 0;
    virtual void toString() const = 0;

};

#endif // __PAIR_H__