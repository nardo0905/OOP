#include <iostream>

class Complex {

private:

    double realPart, imagPart;

public:

    Complex(const double rp = 0, const double imp = 0) {

        realPart = rp;
        imagPart = imp;

    }

    Complex add(const Complex& comp) const {

        double newRealPart = this->realPart + comp.realPart;
        double newImPart = this->imagPart + comp.imagPart;

        return Complex(newRealPart, newImPart);

    }

    Complex sub(const Complex& comp) const {

        double newRealPart = this->realPart - comp.realPart;
        double newImPart = this->imagPart - comp.imagPart;

        return Complex(newRealPart, newImPart);

    }

    Complex negate() const {

        return Complex{-1 * realPart, -1 * imagPart};

    }

    Complex conjugate() const {

        return Complex{realPart, -1 * imagPart};

    }

    Complex multiply(const Complex& comp) const {

        double help1 = this->realPart * comp.realPart;
        double help2 = this->realPart * comp.imagPart;
        double help3 = this->imagPart * comp.realPart;
        double help4 = this->imagPart * comp.imagPart * -1;

        double newRealPart = help1 + help4;
        double newImPart = help2 + help3;

        return Complex(newRealPart, newImPart);

    }

    Complex divide(Complex& comp) const {

        Complex cong = comp.conjugate();
        Complex top = this->multiply(cong);
        Complex bottom = comp.multiply(cong);

        double newRealPart = top.realPart / bottom.realPart;
        double newImPart = top.imagPart / bottom.realPart;

        return Complex(newRealPart, newImPart);

    }

    void print() const {

        if (imagPart < 0) {

            std::cout << realPart << imagPart << "i" << std::endl;

        }
        else if (imagPart > 0) {

            std::cout << realPart << "+" << imagPart << "i" << std::endl;

        }
        else {
    
            std::cout << realPart << std::endl;
        }

    }

};

int main() {

    Complex num1(20, -4);
    Complex num2(3, 2);

    Complex add = num1.add(num2);
    Complex sub = num1.sub(num2);
    Complex mult = num1.multiply(num2);
    Complex div = num1.divide(num2);

    add.print();
    sub.print();
    mult.print();
    div.print();

    return 0;

}