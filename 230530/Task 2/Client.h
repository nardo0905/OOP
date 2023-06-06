#ifndef __CLIENT_H__
#define __CLIENT_H__
#include "Restaurant.h"
#include <string>

class Client {

private:

    std::string email, password, phone;
    Restaurant& subscribedRest;

public:

    void subscribe(const Restaurant& restaurant);

};

#endif // __CLIENT_H__