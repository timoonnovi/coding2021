// 3-3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Введите массив чисел через пробелы:\n";
    string s;
    getline(cin, s);

    s += ' ';

    vector <int> v;

    while (s.length() > 0)
    {
        string tmp = s.substr(0, s.find(' '));
        s.erase(0, s.find(' ') + 1);
        v.push_back(stoi(tmp));
    }

    // по убыванию
    cout << "Массив, отсортированный по убыванию:\n";
    sort(v.begin(), v.end(), [](int a, int b) { return a > b; });
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';

    cout << endl;

    // по возрастанию
    cout << "Массив, отсортированный по возрастанию:\n";
    sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';

    cout << endl;

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
