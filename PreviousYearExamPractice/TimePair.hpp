#ifndef __TIMEPAIR_H__
#define __TIMEPAIR_H__
#include "Pair.hpp"
#include <iostream>

struct Time {

    int minutes, hours;

    Time(const int hours = 0, const int minutes = 0) {

        if (minutes < 0 || minutes > 60 || hours < 0 || hours > 24) {

            this->minutes = 0;
            this->hours = 0;

            std::cerr << "Invalid time!" << std::endl;

        }

        this->minutes = minutes;
        this->hours = hours;

    }

    friend std::ostream& operator<<(std::ostream&, const Time&);

};

std::ostream& operator<<(std::ostream& os, const Time& obj) {

    if (obj.minutes < 10) {

        if (obj.hours < 10) {

            os << "0" << obj.hours << ":0" << obj.minutes;

        }
        else {

            os << obj.hours << ":0" << obj.minutes;
            
        }

    }
    else {

        os << obj.hours << ":" << obj.minutes;

    }

    return os;

}

class TimePair : virtual public Pair {

protected:

    Time time;

public:

    TimePair(const char* key, const Time& value) : Pair(key), time(value){}

    Pair* clone() const override;

    void toString() const override {

        std::cout << "{" << getKey() << " : " << time << "}" << std::endl;
        
    }

};

Pair* TimePair::clone() const {

    return new TimePair{*this};

}

#endif // __TIMEPAIR_H__