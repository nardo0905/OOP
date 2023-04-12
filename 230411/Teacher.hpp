#ifndef __TEACHER_H__
#define __TEACHER_H__
#include "User.hpp"
#include <string>
#include <vector>
using std::string, std::vector;

class Teacher : public User {

    vector<string> courses;

public:

    Teacher(const string& username, const string& password) : User(username, password) {};

    void addCourse(const string& course) {

        courses.push_back(course);

    }

    vector<string> getCourses() const {

        return courses;

    }

};

#endif // __TEACHER_H__