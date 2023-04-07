#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

struct Date {

    // 01/01/1981,20.7
    int day, month, year;
    double temperature;

};

std::istream& operator>>(std::istream& is, Date& obj) {

    is >> obj.day;
    is.ignore(1, '/');
    is >> obj.month;
    is.ignore(1, '/');
    is >> obj.year;
    is.ignore(1, ',');
    is >> obj.temperature;
    is.ignore(-1u, '\n');

    return is;

}

std::ostream& operator<<(std::ostream& os, Date& obj) {

    os << obj.day << "/" << obj.month << "/" << obj.year << "," << obj.temperature;

    return os;

}

struct Year {
    
    int year;
    double sum;
    size_t count;
    Date min;
    Date max;

};

int main() {

    std::ifstream fin("temperature.csv");
    std::ofstream fout("temperature_results.csv");
    fout << "Year," << "Measurements Count," << "Avg. Temp," << "Date recorded," << "Min. temp.," << "Date recorded," << "Max. temp." << std::endl;

    if (!fin || !fout) {

        std::cerr << "File not found!" << std::endl;
        return 1;

    }

    fin.ignore(-1u, '\n'); // ignores header lines

    Date date;
    while (fin >> date) {

        int currYear = date.year;
        Year current{currYear, date.temperature, 0, date, date};
        current.count++;

        // std::cout << date << std::endl;
        while (date.year == current.year) {

            current.sum += date.temperature;
            if (date.temperature <= current.min.temperature) {

                current.min = date;

            }
            if (date.temperature >= current.max.temperature) {

                current.max = date;

            }

            current.count++;
            fin >> date;

        }

        double yearAvg = current.sum / current.count;

        //add output to csv file
        fout << current.year << "," << current.count << "," << yearAvg << "," << current.min << "," << current.max << std::endl;

    }

    fin.close();
    fout.close();

    return 0;

}
