#include <iostream>
#include "Car.hpp"
#include "Truck.hpp"
#include "PickupTruck.hpp"
#include "VehicleDatabase.hpp"

int main() {

    Car car1{"Porsche Taycan", 500, 5};
    std::cout << car1 << std::endl;

    const char* p1 = "Doncho";
    const char* p2 = "Deni";
    const char* p3 = "Kuche";
    car1.addPassenger(p1);
    car1.addPassenger(p2);
    car1.addPassenger(p3);

    for (const char* p : car1.getPassengerList()) {

        std::cout << p << std::endl;

    }

    std::cout << "Max range: " << car1.getMaxRange() << std::endl;

    car1.removePassenger("Kuche");
    std::cout << "------------------------" << std::endl;

    for (const char* p : car1.getPassengerList()) {

        std::cout << p << std::endl;

    }

    std::cout << "------------------------" << std::endl;

    Truck truck1{"MAN", 1000, 200};
    std::cout << truck1 << std::endl;
    truck1.load(50);
    std::cout << "Current load: " << truck1.getCurrentLoad() << std::endl;
    truck1.unload(30);
    std::cout << "Current load: " << truck1.getCurrentLoad() << std::endl;

    std::cout << "------------------------" << std::endl;

    PickupTruck pt1{"Ford 150", 700, 3, 300};
    std::cout << pt1 << std::endl;
    pt1.setSchedule("vzemi durva");
    pt1.setSchedule("otidete s deni na razhodka");
    pt1.setSchedule("karai burzo");
    pt1.addPassenger(p1);
    pt1.addPassenger(p2);
    pt1.load(40);

    std::cout << "Next task: " << pt1.getNextTask() << std::endl;
    std::cout << "Next task: " << pt1.getNextTask() << std::endl;

    VehicleDatabase vdb{};
    vdb.addVehicle(car1);
    vdb.addVehicle(truck1);
    vdb.addVehicle(pt1);
    vdb.storeVehicles("vehiclesDB.txt");

    return 0;

}