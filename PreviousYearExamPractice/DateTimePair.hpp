#ifndef __DATETIMEPAIR_H__
#define __DATETIMEPAIR_H__
#include "DatePair.hpp"
#include "TimePair.hpp"

// struct DPPair {

//     Date date;
//     Time time;

//     friend std::ostream& operator<<(std::ostream&, const DPPair&);

// };

// std::ostream& operator<<(std::ostream& os, const DPPair& obj) {

//     os << obj.date << ", " << obj.time;

//     return os;

// }


class DateTimePair : public DatePair, public TimePair {

public:

    DateTimePair(const char* key, const Date& date, const Time& time) : Pair(key), DatePair(key, date), TimePair(key, time){} 

    Pair* clone() const override {

        return new DateTimePair{*this};

    }

    void toString() const override {

        std::cout << "{" << getKey() << " : " << date <<  ", " << time << "}" << std::endl;
        
    }

};

#endif // __DATETIMEPAIR_H__