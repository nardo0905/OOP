#ifndef __EXPRESSTRAIN_H__
#define __EXPRESSTRAIN_H__
#include "QuickTrain.hpp"
#include "DirectTrain.hpp"

class ExpressTrain : public QuickTrain, public DirectTrain {

private:

    static unsigned tpCoefficient;

public:

    ExpressTrain(const unsigned speed, const unsigned tp, Line* line, const unsigned short sc, const short prio) : Train(speed, tp * tpCoefficient, line), QuickTrain(speed, tp * tpCoefficient, line, sc),
    DirectTrain(speed, tp * tpCoefficient, line, prio) {}

    Train* clone() const {

        return new ExpressTrain{*this};

    }

};

unsigned ExpressTrain::tpCoefficient = 2;

#endif // __EXPRESSTRAIN_H__