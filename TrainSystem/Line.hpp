#ifndef __LINE_H__
#define __LINE_H__
#include "Path.hpp"

class Line {

private:

    Path path;
    unsigned beginHour;
    std::vector<unsigned> timeToEveryStation;

public:

    Line(const Path& path, const unsigned bh, const std::vector<unsigned>& ttes) : path(path), beginHour(bh), timeToEveryStation(ttes){}

    const Path& getPath() const {

        return path;

    }

    unsigned getBeginHour() const {

        return beginHour;

    }

    const std::vector<unsigned>& getTimeToEveryStation() const {

        return timeToEveryStation;

    }

};

#endif // __LINE_H__