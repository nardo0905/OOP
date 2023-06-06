#ifndef __COMPARABLE_H__
#define __COMPARABLE_H__

template <typename T>
class Comparable {

public:

    virtual int compare(const T&) const = 0;
    virtual ~Comparable() = default;

    bool operator<(const T& other) const {

        return this->compare(other) < 0;

    }

    bool operator<=(const T& other) const {

        return this->compare(other) < 0 || this->compare(other) == 0;

    }

    bool operator==(const T& other) const {

        return this->compare(other) == 0;

    }

    bool operator!=(const T& other) const {

        return this->compare(other) != 0;

    }

    bool operator>=(const T& other) const {

        return this->compare(other) > 0 || this->compare(other) == 0;

    }

    bool operator>(const T& other) const {

        return this->compare(other) > 0;

    }

};

#endif // __COMPARABLE_H__