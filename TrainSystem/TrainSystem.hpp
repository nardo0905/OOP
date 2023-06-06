#ifndef __TRAINSYSTEM_H__
#define __TRAINSYSTEM_H__
#include "QuickTrain.hpp"
#include "DirectTrain.hpp"
#include "ExpressTrain.hpp"

class TrainSystem {

private:

    std::vector<Train*> trains;
    std::vector<Line> lines;

    void deleteTS();
    void copy(const TrainSystem&);

public:

    TrainSystem() {}
    ~TrainSystem();
    TrainSystem(const TrainSystem&);
    TrainSystem& operator=(const TrainSystem&);

    void addTrain(const Train*);
    void addLine(const Line&);
    void sendForInspection(const unsigned);

};

void TrainSystem::deleteTS() {

    for (Train* t : trains) {

        delete t;

    }
    
}

void TrainSystem::copy(const TrainSystem& other) {

    for (Train* t : other.trains) {

        this->trains.push_back(t->clone());

    }
    
    for (Line l : other.lines) {

        this->lines.push_back(l);

    }
    
}

TrainSystem::~TrainSystem() {

    deleteTS();

}

TrainSystem::TrainSystem(const TrainSystem& other) {

    copy(other);

}

TrainSystem& TrainSystem::operator=(const TrainSystem& other) {

    if (this != &other) {

        deleteTS();
        copy(other);

    }

    return *this;

}

void TrainSystem::addTrain(const Train* train) {

    this->trains.push_back(train->clone());

}

void TrainSystem::addLine(const Line& line) {

    this->lines.push_back(line);

}

void TrainSystem::sendForInspection(const unsigned trainID) {

    for (Train* tr : this->trains) {

        if (tr->getID() == trainID) {

            tr = nullptr;

        }

    }

}

#endif // __TRAINSYSTEM_H__