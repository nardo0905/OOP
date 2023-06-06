#ifndef __DATEPAIR_H__
#define __DATEPAIR_H__
#include "Pair.hpp"
#include <iostream>
#include <string>

struct Date {
    
    int day, month, year;

    Date(const int day = 31, const int month = 12, const int year = 1900) {

        if (day < 1 || day > 31) {
            
            this->day = 31;
            std::cerr << "Invalid day!" << std::endl;

        }
        if (month < 1 || day > 12) {
            
            this->month = 12;
            std::cerr << "Invalid month!" << std::endl;

        }
        if (year < 0) {
            
            this->year = 1900;
            std::cerr << "Invalid year!" << std::endl;

        }

        this->day = day;
        this->month = month;
        this->year = year;

    }

    friend std::ostream& operator<<(std::ostream&, const Date&);

};

std::ostream& operator<<(std::ostream& os, const Date& obj) {

    os << obj.day << "." << obj.month << "." << obj.year;
    
    return os;

}

class DatePair : virtual public Pair {

protected:

    Date date;

public:

    DatePair(const char* key, const Date& date) : Pair(key), date(date){}

    Pair* clone() const override;

    void toString() const override {

        std::cout << "{" << getKey() << " : " << date << "}" << std::endl;
        
    }
    
};

Pair* DatePair::clone() const {

    return new DatePair{*this};

}

#endif // __DATEPAIR_H__