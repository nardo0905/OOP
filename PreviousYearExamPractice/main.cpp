#include <iostream>
#include "StringPair.hpp"
#include "DatePair.hpp"
#include "TimePair.hpp"
#include "DateTimePair.hpp"
#include "FJSON.hpp"

int main() {

    StringPair sp1{"stringId", "Hello World!"};

    sp1.toString();

    Date dat1{5,6,2023};
    DatePair dp1{"my date", dat1};
    dp1.toString();

    Time time1{22, 35};
    TimePair tp1{"current time", time1};
    tp1.toString();

    DateTimePair dtp1{"curr" , dat1, time1};
    dtp1.toString();

    FJSON file{};
    file.addPair(sp1);
    file.addPair(dp1);
    file.addPair(tp1);
    file.addPair(dtp1);

    file.toString();

    return 0;

}