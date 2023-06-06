#ifndef __STATION_H__
#define __STATION_H__
#include <string>

class Station {

private:

    std::string name;
    short priority;

public:

    Station(const std::string& name, const short prio) : name(name), priority(prio) {}

    const std::string& getName() const {

        return name;

    }

    short getPriority() const {

        return priority;

    }

};

#endif // __STATION_H__