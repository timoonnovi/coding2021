#pragma once
#include <vector>
#include <string>

struct Student;

#include "Lesson.h"

struct Student
{
    std::vector<Lesson*> lesson_list;
    std::string name;

    Student(std::string name_) : name(name_) {}

    void add_lesson(Lesson* tmp);
};