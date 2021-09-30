#include "Student.h"
#include "Lesson.h"

void Student::add_lesson(Lesson* tmp)
{
    lesson_list.push_back(tmp);
    tmp->student_list.push_back(this);
}