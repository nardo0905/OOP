#include <iostream>

class Rational {

private:

    int p, q;

public:

    Rational(int p, int q) {

        this->p = p;
        this->q = q;

    }

    Rational add(const Rational& num2) {

        int newP = this->p + num2.p;
        int newQ = (this->q * num2.q) + (num2.q * this->q);

        Rational newRat(newP, newQ);

        return newRat;

    }

    Rational sub(const Rational& num2) {

        int newP = this->p - num2.p;
        int newQ = (this->q * num2.q) - (num2.q * this->q);

        Rational newRat(newP, newQ);

        return newRat;

    }

    Rational multiply(const Rational& num2) {

        int newP = this->p * num2.p;
        int newQ = this->q * num2.q;

        Rational newRat(newP, newQ);

        return newRat;

    }

    Rational divide(const Rational& num2) {

        int newP = this->p * num2.q;
        int newQ = this->q * num2.p;

        Rational newRat(newP, newQ);

        return newRat;

    }

    void print() {

        std::cout << p << '/' << q << std::endl;

    }

};

int main() {

    Rational a(3,4);
    Rational b(2,3);

    Rational aPlusb = a.add(b);
    Rational aTimesb = a.multiply(b);

    a.print();
    b.print();
    aPlusb.print();
    aTimesb.print();

    return 0;

}