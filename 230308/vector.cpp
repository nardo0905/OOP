#include <iostream>

class Vector {

    size_t _count, _capacity; // capacity is 10 by default, after filling, copy to new array with double the size and delete old one
    int* _array;

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
    int find(const int value);

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

// void Vector::append(const int value) {

//     if (_count + 1 > _capacity) {

//         int* cpyArr = new int[_capacity];

//         for (size_t i = 0; i < _count; i++) {

//             cpyArr[i] = _array[i];

//         }

//         delete[] _array;

//         _array = new int[_capacity * 2];

//         for (size_t i = 0; i < _count; i++) {

//             _array[i] = cpyArr[i];

//         }

//         delete[] cpyArr;

//     }

//     _array[_count] = value;
//     _count++;

// }

// void Vector::insert(const size_t pos, const int value) {

//     if (pos >= _count) {

//         throw "Out of bounds!";

//     }

//     if (_count + 1 > _capacity) {

//         int* cpyArr = new int[_capacity];

//         for (size_t i = 0; i < _count; i++) {

//             cpyArr[i] = _array[i];

//         }

//         delete[] _array;

//         _array = new int[_capacity * 2];

//         for (size_t i = 0; i < _count; i++) {

//             _array[i] = cpyArr[i];

//         }

//         delete[] cpyArr;

//     }

//     size_t i;
//     for (i = _count; i > pos; i--) {
    
//         _array[i] = _array[i - 1];

//     }

//     _array[i] = value;
//     _count++;

// }

void Vector::pop() {

    if (_count == 0) {

        throw "Can't pop an empty array";

    }

    _count--;

}

// void Vector::remove(const size_t pos) {

//     if (pos >= _count) {

//         throw "Out of bounds!";

//     }

// }

int main() {

    Vector vec{};
    vec.append(1);
    vec.append(4);
    vec.append(6);

    vec.print();

    // for (int i = 1; i < 25; i++) {

    //     vec.append(i);

    // }

    vec.append(1);
    vec.append(2);
    vec.append(3);
    vec.append(4);
    vec.append(5);
    vec.append(6);
    vec.append(7);
    vec.append(8);
    vec.append(9);
    vec.append(10);
    vec.append(11);
    vec.append(12);

    vec.print();

    vec.insert(2, 9);
    vec.insert(5, 12);

    vec.print();

    return 0;

}