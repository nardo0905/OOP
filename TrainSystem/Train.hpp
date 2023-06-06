#ifndef __TRAIN_H__
#define __TRAIN_H__
#include "Wagon.hpp"
#include "Line.hpp"
#include <vector>

class Train {

private:

    static unsigned generateId;
    unsigned id;
    std::vector<Wagon> wagons;
    unsigned speed;
    unsigned ticketPrice;
    Line* line;

    void deleteTrain();
    void copy(const Train&);

public:

    Train();
    Train(const unsigned speed, const unsigned tp, Line* line) : speed(speed), ticketPrice(tp) {

        this->line = new Line{*line};
        generateId++;
        this->id = generateId;

    }
    Train(const Train&);
    virtual ~Train();
    Train& operator=(const Train&);

    virtual Train* clone() const = 0;

    void setSpeed(const unsigned speed) {

        this->speed = speed;

    }

    unsigned getSpeed() const {

        return speed;

    }

    const Line* getLine() const {

        return line;

    }

    unsigned getID() const {

        return id;

    }

};

unsigned Train::generateId = 0;

void Train::deleteTrain() {

    if (line) {

        delete line;
        line = nullptr;

    }
    
}

void Train::copy(const Train& other) {

    this->id = other.id;
    for (Wagon wag : other.wagons) {

        this->wagons.push_back(wag);

    }
    this->speed = other.speed;
    this->ticketPrice = other.ticketPrice;
    this->line = new Line{*other.line};

}

Train::Train() {

    generateId++;
    id = generateId;
    speed = 0;
    ticketPrice = 0;
    line = nullptr;

}

Train::~Train() {

    deleteTrain();

}

Train::Train(const Train& other) {

    copy(other);

}

Train& Train::operator=(const Train& other) {


    if (this != &other) {

        deleteTrain();
        copy(other);

    }

    return *this;

}

#endif // __TRAIN_H__