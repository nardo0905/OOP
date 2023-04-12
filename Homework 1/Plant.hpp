#ifndef _PLANT_
#define _PLANT_
#include <iostream>
#include <cstring>

class Plant {

private:

    char* type;
    char env[3][256]; // 0 - sunny; 1 - neutral; 2 - shadow
    int envType; // 0, 1 or 2
    int wateringFrequency;

    void deletePlant() {

        delete[] this->type;

    }

    void copy(const Plant& other) {

        deletePlant();
        this->type = new char[strlen(other.type) + 1];
        strcpy(this->type, other.type);
        this->envType = other.envType;
        this->wateringFrequency = other.wateringFrequency;

    }

    void copyMove(Plant&& other) {

        this->type = other.type;
        this->envType = other.envType;
        this->wateringFrequency = other.wateringFrequency;

        other.type = nullptr;

    }

public:

    Plant(const char*);
    Plant(const Plant&);
    Plant(Plant&&);
    ~Plant();

    Plant& operator=(const Plant&);
    Plant& operator=(Plant&&);

    const char* getType() const;
    const char* getPref() const;
    int getEnvType() const;
    int getFreq() const;
    bool equalTypes(const Plant&) const;

    void setEnv(int env) {

        this->envType = env;

    }

    void setWatFreq(int freq) {

        this->wateringFrequency = freq;
        
    }

    bool operator<(const Plant&) const;

    friend std::istream& operator>>(std::istream&, Plant&);
    friend std::ostream& operator<<(std::ostream&, Plant&);

};

Plant::Plant(const char* type) : envType(-1), wateringFrequency(-1) {
    
    this->type = new char[strlen(type) + 1];
    strcpy(this->type, type);
    strcpy(env[0], "sunny");
    strcpy(env[1], "neutral");
    strcpy(env[2], "shadow");

}

Plant::Plant(const Plant& other) {

    this->type = new char[strlen(other.type) + 1];
    strcpy(this->type, other.type);
    this->envType = other.envType;
    this->wateringFrequency = other.wateringFrequency;
    
}

Plant::Plant(Plant&& other) {

    copyMove((Plant&&)other);
    
}

Plant::~Plant() {

    deletePlant();
    
}

Plant& Plant::operator=(const Plant& other) {

    if (this != &other) {

        copy(other);

    }

    return *this;
    
}

Plant& Plant::operator=(Plant&& other) {

    if (this != &other) {

        copyMove((Plant&&)other);

    }

    return *this;
    
}

const char* Plant::getType() const {

    return type;
    
}

const char* Plant::getPref() const {

    return this->env[envType];
    
}

int Plant::getEnvType() const {

    return envType;

}

int Plant::getFreq() const {

    return this->wateringFrequency;
    
}

bool Plant::equalTypes(const Plant& other) const {

    return !strcmp(this->type, other.type);

}

bool Plant::operator<(const Plant& other) const {

    return strcmp(this->type, other.type) < 0;
    
}

std::ostream& operator<<(std::ostream& os, Plant& obj) {

    os << strlen(obj.type) << ' ' << obj.type << ' ' << /* obj.getPref() */ obj.getEnvType() << ' ' << obj.wateringFrequency;

    return os;
    
}

std::istream& operator>>(std::istream& is, Plant& obj) {

    size_t len;
    is >> len;
    delete[] obj.type;
    obj.type = new char[len + 1];
    is.ignore();
    is.getline(obj.type, len + 1);

    return is;
    
}

#endif