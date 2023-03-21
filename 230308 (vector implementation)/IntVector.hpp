#ifndef _INTVECTOR_
#define _INTVECTOR_
#include <iostream>

class Vector {

    size_t _count, _capacity; // capacity is 10 by default, after filling, copy to new array with double the size and delete old one
    int* _array;

    void checkDoubleArr();

public:

    Vector(const size_t count = 0, const size_t capacity = 10);
    Vector(const Vector &that);
    ~Vector();
    void append(const int value);
    void insert(const size_t pos, const int value);
    void pop();
    void remove(const size_t pos);
    void clear();
    bool isEmpty();
    size_t size();
    int get(const size_t pos);
    void set(const size_t pos, const int value);
    size_t find(const int value);

    Vector& operator =(const Vector& that) {

        if (this != &that) {

            delete [] _array;
            _array = new int[that._capacity];
            this->_count = that._count;
            this->_capacity = that._capacity;

        }

        return *this;

    }

    void print() const {

        for (size_t i = 0; i < _count; i++) {

            std::cout << _array[i] << " ";

        }

        std::cout << std::endl;

    }

};

Vector::Vector(const size_t count, const size_t capacity) {

    _array = new int[capacity];
    this->_count = count;
    this->_capacity = capacity;

}

Vector::Vector(const Vector &that) {

    delete [] _array;
    this->_array = that._array;
    this->_count = that._count;
    this->_capacity = that._capacity;

}

Vector::~Vector() {

    delete [] this->_array;

}

void Vector::checkDoubleArr() {

    if (_count >= _capacity) {

        int* cpyArr = new int[_capacity * 2];

        for (size_t i = 0; i < _count; i++) {

            cpyArr[i] = _array[i];

        }

        delete[] _array;

        _array = cpyArr;
        _capacity *= 2;

    }
    
}

void Vector::append(const int value) {

    checkDoubleArr();

    _array[_count] = value;
    _count++;

}

void Vector::insert(const size_t pos, const int value) {

    if (pos >= _count) {

        throw "Out of bounds!";

    }

    checkDoubleArr();

    size_t i;
    for (i = _count; i > pos; i--) {
    
        _array[i] = _array[i - 1];

    }

    _array[i] = value;
    _count++;

}

void Vector::pop() {

    if (_count == 0) {

        throw "Can't pop an empty array";

    }

    _count--;

}

void Vector::remove(const size_t pos) {

    if (pos >= _count) {

        throw "Out of bounds!";

    }

    int* tempArr = new int[_capacity];

    for (size_t i = 0, j = 0; i < _count; i++) {

        if (i != pos) {

            tempArr[j] = _array[i];
            j++;

        }
        else {

            continue;

        }

    }

    delete[] _array;
    _array = tempArr;
    _count--;

}

void Vector::clear() {

    _capacity = 10;
    _count = 0;
    
    delete[] _array;
    _array = new int[_capacity];

}

bool Vector::isEmpty() {

    return _count == 0;

}

size_t Vector::size() {

    return _count;

}

int Vector::get(const size_t pos) {

    if (pos >= _count) {

        throw "Out of bounds!";

    }

    return _array[pos];

}

void Vector::set(const size_t pos, const int value) {

    if (pos >= _count) {

        throw "Out of bounds!";

    }

    _array[pos] = value;

}

size_t Vector::find(const int value) {

    for (size_t i = 0; i < _count; i++) {

        if (_array[i] == value) {

            return i;

        }

    }

    throw "Value not found!";

}

#endif