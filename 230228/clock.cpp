#include <iostream>

class Clock {

private:

    short hours, minutes, seconds;

    friend std::ostream& operator <<(std::ostream& os, const Clock& cl);

public:

    Clock(const short hours = 0, const short minutes = 0, const short seconds = 0) {

        if (minutes < 0) {

            throw std::invalid_argument("Minutes must be greater than or equal to 0");

        }
        if (seconds < 0) {

            throw std::invalid_argument("Seconds must be greater than or equal to 0");

        }

        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;

        if (this->hours == 24) this->hours = 0;

        if (this->minutes >= 60) {

            this->hours = this->minutes / 60 + this->hours;
            this->minutes = this->minutes - ((this->minutes / 60) * 60);

        }

        if (this->seconds >= 60) {

            this->minutes = this->seconds / 60 + this->minutes;
            this->seconds = this->seconds - ((this->seconds / 60) * 60);

        }

        if (hours < 0 || hours > 24) {

            throw std::invalid_argument("Hours must be between 0 and 24");

        }

    }

    short getHour() const {

        return hours;

    }

    short getMinutes() const {

        return minutes;

    }

    short getSeconds() const {

        return seconds;

    }

    Clock add(const short h = 0, const short m = 0, const short s = 0) const {

        short newHours = this->hours + h;
        short newMinutes = this->minutes + m;
        short newSeconds = this->seconds + s;

        return Clock{newHours, newMinutes, newSeconds};

    }

    Clock difference(const Clock& cl) const {

        short hourDif = abs(this->hours - cl.hours);
        short minDif = abs(this->minutes - cl.minutes);
        short secDif = abs(this->seconds - cl.seconds);

        return Clock{hourDif, minDif, secDif};

    }

    void print() const {

        std::cout << hours << ":" << minutes << ":" << seconds << std::endl;

    }

};

std::ostream& operator <<(std::ostream& os, const Clock& cl) {

    os << cl.hours << ":" << cl.minutes << ":" << cl.seconds;
    return os;

}

int main() {

    Clock clock{14, 15, 35};
    std::cout << clock << std::endl;
    std::cout << clock.add(0, 0, 5) << std::endl;
    std::cout << clock.add(0, 0, 70) << std::endl;
    std::cout << clock.add(0, 140, 70) << std::endl;
    std::cout << clock.add(3, 155, 70) << std::endl;
    std::cout << "Time difference: " << clock.add(3, 155, 70).difference(clock) << std::endl;

    return 0;

}