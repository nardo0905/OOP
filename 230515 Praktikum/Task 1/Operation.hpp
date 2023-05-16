#ifndef __OPERATION_H__
#define __OPERATION_H__
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class Operation {

public:

    template <typename T>
    static void create(const T& obj, std::string file);

    template <typename T>
    static T read(std::string file, size_t index);

    template <typename T>
    static void update(std::string file, const T& obj, size_t index);

    template <typename T>
    static void deleteObj(std::string file, size_t index);

};

template<typename T>
void Operation::create(const T& obj, std::string file) {

    std::ofstream fout(file, std::ios::app | std::ios::out | std::ios::binary);
    if (!fout) throw "File not found";

    fout.write((char*)&obj, sizeof(obj));

    fout.close();
    
}

template <typename T>
T Operation::read(std::string file, size_t index) {

    std::ifstream fin(file, std::ios::in | std::ios::binary);
    if (!fin) throw "File not found!";

    T temp;
    fin.seekg(sizeof(T) * index);
    fin.get((char*)&temp, sizeof(temp));

    fin.close();

    return temp;
    
}

template<typename T>
void Operation::update(std::string file, const T& obj, size_t index) {

    std::ofstream fout(file, std::ios::out | std::ios::binary);
    if (!fout) throw "File not found";

    fout.seekp(fout.beg);
    fout.seekp(sizeof(T)*index);
    fout.write((char*)&obj, sizeof(obj));

    fout.close();
    
}

// template<typename T>
// void Operation::deleteObj(std::string file, size_t index) {

//     std::ofstream fout(file, std::ios::out | std::ios::binary);
//     if (!fout) throw "File not found";

//     std::vector<T> temp;

//     T tempObj;
    
// }

#endif // __OPERATION_H__
