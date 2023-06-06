#ifndef __QUICKTRAIN_H__
#define __QUICKTRAIN_H__
#include "Train.hpp"

class QuickTrain : virtual public Train {

private:

    unsigned short speedCoefficient;

public:

    QuickTrain(const unsigned speed, const unsigned tp, Line* line, const unsigned short sc) : Train(speed * sc, tp , line), speedCoefficient(sc) {}

    void changeSC(const unsigned short sc) {

        this->speedCoefficient = sc;
        this->setSpeed(speedCoefficient * getSpeed());

    }

    Train* clone() const {

        return new QuickTrain{*this};

    }

};

#endif // __QUICKTRAIN_H__