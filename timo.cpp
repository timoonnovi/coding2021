// timo.cpp : Переопределение операторов ввода/вывода для вектора типа int.
//

#ifndef TIMO_CPP
#define TIMO_CPP

#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

// Ïåðåîïðåäåëåíèå îïåðàòîðà âûâîäà äëÿ âåêòîðà òèïà int
std::ostream& operator<<(std::ostream& ostr,
    const std::vector<int>& nums) 
{
    for (auto i = 0u; i < nums.size(); i++) {
        ostr << nums[i] << ' ';
    }
    ostr << '\n';
    return ostr;
}

// Ïåðåîïðåäåëåíèå îïåðàòîðà ââîäà äëÿ âåêòîðà òèïà int
std::istream& operator>>(std::istream& istr, std::vector<int>& v) 
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Ââåäèòå âåêòîð:\n";

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
