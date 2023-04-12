#include <iostream>
#include <string>
#include <vector>
#include "User.hpp"
#include "Student.hpp"
#include "Teacher.hpp"
using std::string, std::vector;

int main() {

    Student s{"pesho", "pesho123"};
    s.addCourse("OOP");
    s.addCourse("Calculus 2");
    s.addNote(5);
    s.addNote(6);

    std::cout << s.getUsername() << " " << s.getPassword() << std::endl;
    for (string s : s.getCourseList()) {

        std::cout << s << std::endl;

    }

    return 0;

}