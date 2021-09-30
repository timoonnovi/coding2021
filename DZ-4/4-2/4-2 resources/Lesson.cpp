#include "Lesson.h"
#include "Student.h"

void Lesson::add_student(Student* tmp)
{
    student_list.push_back(tmp);
    tmp->lesson_list.emplace_back(this);
}