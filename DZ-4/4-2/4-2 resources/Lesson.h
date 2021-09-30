#pragma once
#include <vector>
#include <string>

struct Lesson;

#include "Student.h"

struct Lesson
{
    std::vector<Student*> student_list;
    std::string name;

    Lesson(std::string name_) : name(name_) {}

    void add_student(Student* tmp);
};