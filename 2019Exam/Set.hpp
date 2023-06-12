#ifndef __SET_H__
#define __SET_H__
#include <vector>

template <typename T>
class Set {

private:

    std::vector<T> elements;

public:

    Set() {}

    bool member(T x) const {

        for (T el : elements) {

            if (el == x) return true;

        }

        return false;

    }

    void addElement(const T& element) {

        elements.push_back(element);

    }

    T& operator[](const size_t index) {

        if (index < 0 || index >= elements.size()) {

            throw "Index out of bounds";

        }

        return elements[index];

    }

    const T& operator[](const size_t index) const {

        if (index < 0 || index >= elements.size()) {

            throw "Index out of bounds";

        }

        return elements[index];

    }

    int length() const {

        return elements.size();

    }

};

#endif // __SET_H__