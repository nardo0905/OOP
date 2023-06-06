#ifndef __PRINTABLE_H__
#define __PRINTABLE_H__
#include <iostream>

class Printable {

public:

    virtual std::ostream& print(std::ostream& out) const = 0;
    virtual ~Printable() = default;

};

std::ostream& operator<<(std::ostream& out, const Printable& p) {

    return p.print(out);

}

#endif // __PRINTABLE_H__