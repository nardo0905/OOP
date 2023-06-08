#ifndef __VEHICLEDATABASE_H__
#define __VEHICLEDATABASE_H__
#include "Car.hpp"
#include "Truck.hpp"
#include "PickupTruck.hpp"
#include <string>
#include <fstream>

class VehicleDatabase {

private:

    std::vector<Vehicle*> vehicles; // masiv ot Vehice POINTERI, zashtoto Vehicle e abstrakten klas, toest ne mogat da se suzdavat instancii,
    // no mogat da se suzdavat obekti! moje da imame primerno Vehicle* veh = new Car{...}, vmesto car moje da stoi truck ili pickuptruck, no
    // vsichki sa ot tip Vehicle*. tova e vajno. trqbva ni golqma  chetvorka

    void copy(const VehicleDatabase& other) { // kopirame

        for (Vehicle* v : other.vehicles) {

            this->vehicles.push_back(v->clone());

        }

    }

    void deleteDB() { // triem

        for (Vehicle* v : vehicles) {

            delete v;

        }

    }

public:

    // golqma chetvorka
    VehicleDatabase() {}

    VehicleDatabase(const VehicleDatabase& other) {

        copy(other);

    }

    ~VehicleDatabase() {

        deleteDB();

    }

    VehicleDatabase& operator=(const VehicleDatabase& other) {

        if (this != &other) {

            deleteDB();
            copy(other);

        }

        return *this;

    }

    // dobavqme nov vehicle vuv vektora s vehicles
    void addVehicle(const Vehicle& veh) {

        // eto tuk polzvame clone, za da klonirame obekta, a da nqma spodelena pamet
        vehicles.push_back(veh.clone());

    }

    // tozi metod priema ime na fail
    void storeVehicles(std::string filename) {

        // otvarqme faila vuv failov potok
        std::ofstream fout(filename);
        if (!fout) throw "File not found!";

        // tuk izplzvame write funkciqta za da zapishem vseki ot vehicle-ite vuv faila
        for (Vehicle* v : vehicles) {

            v->write(fout);

        }

        fout.close(); // zatvarqme faila

    }

};

#endif // __VEHICLEDATABASE_H__