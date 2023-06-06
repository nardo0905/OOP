#include "TrainSystem.hpp"

int main() {

    Station stat1{"Stz", 6};
    Station stat2{"Sofia", 10};

    Path path1{};
    path1.addStation(stat1);
    path1.addStation(stat2);

    std::vector<unsigned> timeToStation;
    timeToStation.push_back(3);
    timeToStation.push_back(2);

    Line line1{path1, 3, timeToStation};

    QuickTrain qt1{120, 10, &line1, 2};
    DirectTrain dt1{140, 8, &line1, 7};

    ExpressTrain exp1{120, 10, &line1, 2, 5};

    TrainSystem ts{};
    ts.addTrain(&qt1);
    ts.addTrain(&dt1);
    ts.addTrain(&exp1);
    ts.addLine(line1);

    return 0;

}