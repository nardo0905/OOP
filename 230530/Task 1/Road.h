#ifndef __ROAD_H__
#define __ROAD_H__
#include <string>

class Road {

private:

    std::string roadName;
    unsigned length;
    std::string beginPoint, endPoint;

public:

    Road(const std::string& roadName, unsigned length, const std::string& beginPoint, const std::string& endPoint);

    virtual int getSpeedLimit() const = 0;
    virtual Road* clone() const = 0;
    virtual ~Road();

};

#endif // __ROAD_H__