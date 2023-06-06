#ifndef __RATIONAL_H__
#define __RATIONAL_H__
#include "Comparable.hpp"
#include "Printable.hpp"

class Rational : public Comparable<Rational>, public Printable {

private:

    int p, q;

public:

    Rational(const int p = 0, const int q = 1) : p(p), q(q){}

    int compare(const Rational&) const;
    std::ostream& print(std::ostream&) const;

};

int Rational::compare(const Rational& other) const {

    if (this->q == other.q) {

        return this->p - other.p;

    }

    int thisNewP = this->p * other.q;
    int otherNewP = this->q * other.p;

    return thisNewP - otherNewP;

}

std::ostream& Rational::print(std::ostream& out) const {

    out << p << "/" << q;
    return out;

}

#endif // __RATIONAL_H__