#ifndef __WAGON_H__
#define __WAGON_H__

class Wagon {

private:

    static int capacity;
    int currFilled;

public:

    Wagon() {}

    void add();
    void remove();

};

int Wagon::capacity = 50;

void Wagon::add() {

    if (currFilled == capacity) throw "Not enough room!";
    capacity++;

}

void Wagon::remove() {

    if (currFilled == 0) throw "No seats taken!";
    capacity--;

}

#endif // __WAGON_H__