#ifndef TIMO_H
#define TIMO_H

#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

// Переопределение оператора вывода для вектора типа int
std::ostream& operator<<(std::ostream& ostr,
    const std::vector<int>& nums);

// Переопределение оператора ввода для вектора типа int
std::istream& operator>>(std::istream& istr, std::vector<int>& v);

#endif // !TIMO_H
