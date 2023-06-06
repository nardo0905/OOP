#ifndef __STRINGPAIR_H__
#define __STRINGPAIR_H__
#include "Pair.hpp"
#include <string>

class StringPair : public Pair {

protected:

    std::string str;

public:

    StringPair(const char* key, const std::string& str) : Pair(key), str(str) {}

    Pair* clone() const override;

    void toString() const override {

        std::cout << "{" << getKey() << " : " << str << "}" << std::endl;
        
    }

};

Pair* StringPair::clone() const {

    return new StringPair{*this};

}

#endif // __STRINGPAIR_H__