#ifndef __RESERVATION_H__
#define __RESERVATION_H__
#include <iostream>

struct Date {

    int day, month, year;

    Date() {

        day = 0, month = 0, year = 0;

    }

    Date(const int day, const int month, const int year) {

        this->day = day;
        this->month = month;
        this->year = year;

    }

    long long toLong() const {

        return 10000 * year + 100 * month + day;

    }

    bool operator<=(const Date& other) const {

        return this->toLong() <= other.toLong();

    }

};

std::ostream& operator<<(std::ostream& os, const Date& obj) {

    os << obj.day << '/' << obj.month << '/' << obj.year;

    return os;

}

std::istream& operator>>(std::istream& is, Date& obj) {

    is >> obj.day;
    is.ignore(1, '/');
    is >> obj.month;
    is.ignore(1, '/');
    is >> obj.year;

    return is;

}

class Reservation {

    Date start, end;

    bool validate() {

        return start <= end;

    }

public:

    Reservation() : start(), end() {};

    Reservation(const Date& start, const Date& end) {

        this->start.day = start.day;
        this->start.month = start.month;
        this->start.year = start.year;

        this->end.day = end.day;
        this->end.month = end.month;
        this->end.year = end.year;

    }

    bool overlaps(const Reservation& other) const {

        return this->start <= other.end && other.start <= this->end;

    }

    friend std::ostream& operator<<(std::ostream&, const Reservation&);
    friend std::istream& operator>>(std::istream&, Reservation&);

};

std::ostream& operator<<(std::ostream& os, const Reservation& obj) {

    os << obj.start << " " << obj.end;

    return os;
    
}

std::istream& operator>>(std::istream& is, Reservation& obj) {

    is >> obj.start >> obj.end;
    if (!obj.validate()) throw std::exception();

    return is;
    
}

#endif // __RESERVATION_H__