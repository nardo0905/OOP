#ifndef __STUDENT_H__
#define __STUDENT_H__
#include "User.hpp"
#include <string>
#include <vector>
using std::string, std::vector;

class Student : public User {

    vector<string> courses;
    vector<double> notes;

public:

    Student(const string& username, const string& password) : User(username, password) {};

    void addCourse(const string& course) {

        courses.push_back(course);

    }

    void addNote(const double note) {

        notes.push_back(note);

    }

    vector<string> getCourseList() const {

        return courses;

    }

    vector<double> getNotes() const {

        return notes;

    }

};

#endif // __STUDENT_H__