// timo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#ifndef TIMO_CPP
#define TIMO_CPP

#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

// Переопределение оператора вывода для вектора типа int
std::ostream& operator<<(std::ostream& ostr,
    const std::vector<int>& nums) 
{
    for (auto i = 0u; i < nums.size(); i++) {
        ostr << nums[i] << ' ';
    }
    ostr << '\n';
    return ostr;
}

// Переопределение оператора ввода для вектора типа int
std::istream& operator>>(std::istream& istr, std::vector<int>& v) 
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Введите вектор:\n";

    std::string s;
    getline(std::cin, s);

    s += ' ';

    while (s.length() > 0)
    {
        std::string tmp = s.substr(0, s.find(' '));
        s.erase(0, s.find(' ') + 1);
        v.push_back(stoi(tmp));
    }

    return istr;
}

#endif // !TIMO_CPP


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
