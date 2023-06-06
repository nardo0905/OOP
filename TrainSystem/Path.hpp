#ifndef __PATH_H__
#define __PATH_H__
#include "Station.hpp"
#include <vector>

class Path {

private:

    std::vector<Station> stations;

public:

    Path() {}

    void addStation(const Station&);
    void removeStation(const size_t);

    const std::vector<Station>& getStations() const {

        return stations;

    }

};

void Path::addStation(const Station& station) {

    stations.push_back(station);

}

void Path::removeStation(const size_t index) {

    if (index < 0 || index >= stations.size()) throw "Invalid index!";
    stations.erase(stations.begin() + index);

}

#endif // __PATH_H__