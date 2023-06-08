#ifndef __VEHICLE_H__
#define __VEHICLE_H__
#include <cstring>

class Vehicle { // tova e izcqlo abstrakten klas, toest ni trqbva pone edna virtualna funkciq koqto e pure virtual (toest ima = 0)

private:

    static unsigned generateId; // tazi promenliva e obshta za vsichki instancii na obekt koeto e Vehicle, nie q izpolzvame za da "generirame id"
    unsigned id;
    char model[33]; // 32 + 1 za terminirashta nula
    unsigned range;

public:

    Vehicle(const char*, const unsigned);

    unsigned getId() const;
    const char* getModel() const;
    unsigned getRange() const;

    void setModel(const char*);
    void setRange(const unsigned);

    virtual ~Vehicle() = default; // vuv vseki bazov abstrakten klas, koito ima naslednici trqbva da ima virtualen destruktor kotio e = default ako nqma dinamichna pamet
    virtual unsigned getMaxRange() const = 0;
    virtual Vehicle* clone() const = 0; // tozi clone ni trqbva za database klasa v koito skladirame pointeri kum Vehicle(zashtoto vehicle e abstrakten i ne moje)
    // da ima instancii, toest ni trqbva nqkva funkciq koqto da kopira pametta na pointer kum nqkakuv tip vehicle toest kola, kamion i t.n. v drug obekt ot sushtiq tip
    virtual void write(std::ofstream&) const = 0; // tova e funkciq koqto drugite klsove trqbva da imat, polzvame q za da zapishem obekta na failov potok

};

unsigned Vehicle::generateId = 0; // tuk inicializirame statichnata promeenliva

Vehicle::Vehicle(const char* model, const unsigned range) : id(generateId), range(range) {

    generateId++; // tuk q digame, za da digne id-to s edno, to e spodeleno za vischki obekti, taka moje akto suzdavame novi da sa s id 1 posle 2 posle 3 i tn
    strcpy(this->model, model);
    
}

unsigned Vehicle::getId() const {

    return id;
    
}

const char* Vehicle::getModel() const {

    return model;
    
}

unsigned Vehicle::getRange() const {

    return range;
    
}

void Vehicle::setModel(const char* model) {

    strcpy(this->model, model);

}

void Vehicle::setRange(const unsigned range) {

    this->range = range;

}

#endif // __VEHICLE_H__