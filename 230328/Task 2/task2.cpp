#include <iostream>
#include <fstream>
#include <vector>

const char* studID = "0MI0648544";

struct StudentRecord {

    char studentID[10];
    char courseID[6];
    int note;

};

std::vector<int> getStudentNotes(const char* studentID) {

    std::ifstream fin("student_records.data", std::ios::in | std::ios::binary);
    if(!fin) throw std::invalid_argument("File not found!");

    std::vector<int> notes;

    StudentRecord r;
    while (fin.read((char*)&r, sizeof(r))) {

        if (!strncmp(r.studentID, studentID, 10)) {

            notes.push_back(r.note);

        }

    }

    fin.close();

    return notes;

}

std::vector<int> getCourseNotes(const char* courseID) {

    std::ifstream fin("student_records.data", std::ios::in | std::ios::binary);
    if(!fin) throw std::invalid_argument("File not found!");

    std::vector<int> notes;

    StudentRecord r;
    while (fin.read((char*)&r, sizeof(r))) {

        if (!strncmp(r.courseID, courseID, 6)) {

            notes.push_back(r.note);

        }

    }

    fin.close();

    return notes;

}

double getStudentAverage(const char* studentID) {

    std::vector<int> studNotes = getStudentNotes(studentID);
    double sum = 0;

    for (int note : studNotes) {

        sum += note;

    }

    return sum / studNotes.size();

}

double getCourseAverage(const char* courseID) {

    std::vector<int> courseNotes = getCourseNotes(courseID);
    double sum = 0;

    for (int note : courseNotes) {

        sum += note;

    }

    return sum / courseNotes.size();

}

int main() {

    for (int note : getStudentNotes(studID)) {

        std::cout << note << " ";

    }
    std::cout << std::endl << "---------------------" << std::endl;

    for (int note : getCourseNotes("MAT101")) {

        std::cout << note << " ";

    }

    std::cout << std::endl << "---------------------" << std::endl;
    std::cout << getStudentAverage(studID) << std::endl;
    
    std::cout << "---------------------" << std::endl;
    std::cout << getCourseAverage("MAT101") << std::endl;

    return 0;

}
