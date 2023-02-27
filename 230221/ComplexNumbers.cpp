#include <iostream>

class Complex {

private:

    int realPart, imagPart;

public:

    Complex(int rp, int imp) {

        realPart = rp;
        imagPart = imp;

    }

    Complex add(const Complex& comp) const {

        int newRealPart = this->realPart + comp.realPart;
        int newImPart = this->imagPart + comp.imagPart;

        return Complex(newRealPart, newImPart);

    }

    Complex sub(const Complex& comp) const {

        int newRealPart = this->realPart - comp.realPart;
        int newImPart = this->imagPart - comp.imagPart;

        return Complex(newRealPart, newImPart);

    }

    Complex multiply(const Complex& comp) const {

        int help1 = this->realPart * comp.realPart;
        int help2 = this->realPart * comp.imagPart;
        int help3 = this->imagPart * comp.realPart;
        int help4 = this->imagPart * comp.imagPart * -1;

        int newRealPart = help1 + help4;
        int newImPart = help2 + help3;

        return Complex(newRealPart, newImPart);

    }

    Complex divide(Complex& comp) const {

        Complex cong(comp.realPart, -1 * comp.imagPart);
        Complex top = this->multiply(cong);
        Complex bottom = comp.multiply(cong);

        int newRealPart = top.realPart / bottom.realPart;
        int newImPart = top.imagPart / bottom.realPart;

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