// 4-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include "Lesson.h"
#include "Student.h"

std::vector<Student> s;
std::vector<Lesson> l;

int main()
{
    setlocale(LC_ALL, "Russian");

    s.push_back(Student("Ваня"));
    s.push_back(Student("Сергей"));

    l.push_back(Lesson("Математика"));
    l.push_back(Lesson("Физика"));

    s[0].add_lesson(&l[0]);
    s[0].add_lesson(&l[1]);
    s[1].add_lesson(&l[0]);

    std::cout << "Математика: ";
    for (int i = 0; i < l[0].student_list.size(); ++i) 
    {
        std::cout << l[0].student_list[i]->name;
        if (i != l[0].student_list.size() - 1) std::cout << ", ";
    }

    std::cout << '\n';

    std::cout << "Ваня: ";
    for (int i = 0; i < s[0].lesson_list.size(); ++i) 
    {
        std::cout << s[0].lesson_list[i]->name;
        if (i != s[0].lesson_list.size() - 1) std::cout << ", ";
    }

    std::cout << '\n';

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
