#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <cctype>

class Registration {

    char regNum[9];

public:

    Registration(const char* reg);

    Registration& operator=(const char*);
    bool operator==(const Registration&) const;

    const char* toString() const;

};

Registration::Registration(const char* reg) {

    if (!isalpha(reg[0])) throw std::exception();
    if (!isdigit(reg[2]) && !isdigit(reg[3]) && !isdigit(reg[4]) && !isdigit(reg[5])) throw std::exception();
    if (!isalpha(reg[6]) && !isalpha(reg[7])) throw std::exception();

    strcpy(regNum, reg);
    
}

Registration& Registration::operator=(const char* reg) {

    if (!isalpha(reg[0])) throw std::exception();
    if (!isdigit(reg[2]) && !isdigit(reg[3]) && !isdigit(reg[4]) && !isdigit(reg[5])) throw std::exception();
    if (!isalpha(reg[6]) && !isalpha(reg[7])) throw std::exception();

    if (strcmp(regNum, reg)) {

        strcpy(regNum, reg);

    }

    return *this;

}

bool Registration::operator==(const Registration& other) const {

    return !strcmp(regNum, other.regNum);
    
}

const char* Registration::toString() const {

    return regNum;

}

class Vehicle {

public:

    const Registration reg;
    std::string description;

    Vehicle(const char* regnum, const char* desc) : reg(regnum) {

        description = desc;

    }

};

class VehicleList {

    Vehicle** vehicles;
    size_t cap;
    int count;

    void deleteList() {

        for (size_t i = 0; i < count; i++) {

            delete vehicles[i];

        }

        delete[] vehicles;

    }

    void copy(const VehicleList& other) {

        vehicles = new Vehicle*[other.cap];
        this->cap = other.cap;
        this->count = other.count;

        for (size_t i = 0; i < other.count; i++) {

            vehicles[i] = new Vehicle{*other.vehicles[i]};

        }
        
    }

    bool exists(const char* regnum) {

        for (size_t i = 0; i < count; i++) {

            if (!strcmp(vehicles[i]->reg.toString(), regnum)) return true;

        }

        return false;

    }

public:

    VehicleList(size_t size = 0);
    VehicleList(const VehicleList&);
    VehicleList& operator=(const VehicleList&);
    ~VehicleList();

    void insert(const char*, const char*);
    const Vehicle& at(const size_t) const;
    
    const Vehicle& operator[](const size_t) const;

    bool empty() const;
    size_t capacity() const;
    size_t size() const;
    const Vehicle* find(const Registration&) const;

};

VehicleList::VehicleList(size_t size) {

    this->cap = size;
    vehicles = new Vehicle*[cap];

}

VehicleList::VehicleList(const VehicleList& other) {

    copy(other);

}

VehicleList::~VehicleList() {

    deleteList();

}

VehicleList& VehicleList::operator=(const VehicleList& other) {

    if (this != &other) {

        deleteList();
        copy(other);

    }

    return *this;

}

void VehicleList::insert(const char* regnum, const char* desc) {

    if (exists(regnum)) throw std::exception();
    if (count + 1 > cap) throw std::exception();

    vehicles[count] = new Vehicle{regnum, desc};
    count++;

}

const Vehicle& VehicleList::at(const size_t pos) const {

    if (pos < 0 || pos >= cap) throw std::exception();

    return *vehicles[pos];

}

const Vehicle& VehicleList::operator[](const size_t pos) const {

    return *vehicles[pos];

}

bool VehicleList::empty() const {

    return count == 0;

}

size_t VehicleList::capacity() const {

    return cap;

}

size_t VehicleList::size() const {

    return count;

}

const Vehicle* VehicleList::find(const Registration& regnum) const {

    for (size_t i = 0; i < count; i++) {

        if (vehicles[i]->reg == regnum) {

            return vehicles[i];

        }

    }

    return nullptr;

}

int main() {

    Registration reg1{"C1234AB"};
    std::cout << reg1.toString() << std::endl;
    // Registration regerr{"A12312312312"};
    reg1 = "XY1111YX";
    std::cout << reg1.toString() << std::endl;

    Vehicle vec{"CT1234AB", "Golf"};
    std::cout << vec.reg.toString() << " " << vec.description << std::endl;

    return 0;

}