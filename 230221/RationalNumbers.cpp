#include <iostream>

class Rational {

private:

    int p, q;

public:

    Rational(const int p = 0, const int q = 1) {

        this->p = p;
        this->q = q;

    }

    // Rational add(const Rational& num2) const {

    //     int newP = this->p + num2.p;
    //     int newQ = (this->q * num2.q) + (num2.q * this->q);

    //     Rational newRat(newP, newQ);

    //     return newRat;

    // }

    Rational operator+(const Rational& num2) const {

        int newP = this->p + num2.p;
        int newQ = (this->q * num2.q) + (num2.q * this->q);

        return Rational{newP, newQ};

    }

    // Rational sub(const Rational& num2) const {

    //     int newP = this->p - num2.p;
    //     int newQ = (this->q * num2.q) - (num2.q * this->q);

    //     Rational newRat(newP, newQ);

    //     return newRat;

    // }

    Rational operator-(const Rational& num2) const {

        int newP = this->p - num2.p;
        int newQ = (this->q * num2.q) - (num2.q * this->q);

        return Rational{newP, newQ};

    }

    // Rational multiply(const Rational& num2) const {

    //     int newP = this->p * num2.p;
    //     int newQ = this->q * num2.q;

    //     Rational newRat(newP, newQ);

    //     return newRat;

    // }

    Rational operator*(const Rational& num2) const {

        int newP = this->p * num2.p;
        int newQ = this->q * num2.q;

        return Rational{newP, newQ};

    }

    // Rational divide(const Rational& num2) const {

    //     int newP = this->p * num2.q;
    //     int newQ = this->q * num2.p;

    //     Rational newRat(newP, newQ);

    //     return newRat;

    // }

    Rational operator/(const Rational& num2) const {

        int newP = this->p * num2.q;
        int newQ = this->q * num2.p;

        return Rational{newP, newQ};
        
    }

    void print() const {

        std::cout << p << '/' << q << std::endl;

    }

};

int main() {

    Rational a(3,4);
    Rational b(2,3);

    Rational aPlusb = a + b;
    Rational aTimesb = a * b;
    Rational aDivideb = a / b;
    a.print();
    b.print();
    aPlusb.print();
    aTimesb.print();
    aDivideb.print();

    return 0;

}