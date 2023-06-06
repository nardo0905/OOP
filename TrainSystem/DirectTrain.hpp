#ifndef __DIRECTTRAIN_H__
#define __DIRECTTRAIN_H__
#include "Train.hpp"

class DirectTrain : virtual public Train {

private:

    short trainPriority;

public:

    DirectTrain(const unsigned speed, const unsigned tp, Line* line, const short prio) : Train(speed, tp, line), trainPriority(prio) {}

    std::vector<Station> getDirectStations() {

        std::vector<Station> directStations;

        for (Station st : this->getLine()->getPath().getStations()) {

            if (st.getPriority() >= this->trainPriority) {

                directStations.push_back(st);

            }

        }

        return directStations;

    }

    Train* clone() const {

        return new DirectTrain{*this};

    }

};

#endif // __DIRECTTRAIN_H__