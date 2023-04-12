#include <iostream>
#include <fstream>
#include "Reservation.hpp"
#include "Car.hpp"

int main() {

    std::ofstream fout("test_car_out.db");

    Car testCar{1, "Porsche", 2022};
    Date start1{1,2,2022};
    Date end1{2,3,2022};
    Reservation res1{start1, end1};
    Date start2{23,4,2022};
    Date end2{26,6,2022};
    Reservation res2{start2, end2};
    testCar.addReservation(res1);
    testCar.addReservation(res2);

    Car testCar2{2, "Lexus LFA", 2012};
    Date start3{5,4,2023};
    Date end3{23,4,2023};
    Reservation res3{start3, end3};
    Date start4{31,6,2023};
    Date end4{14,7,2023};
    Reservation res4{start4, end4};
    testCar2.addReservation(res3);
    testCar2.addReservation(res4);

    fout << testCar << std::endl;
    fout << testCar2 << std::endl;

    fout.close();

    std::ifstream fin("test_car_out.db");

    Car porsche;
    fin >> porsche;
    std::cout << porsche << std::endl;

    fin.close();

    return 0;

}