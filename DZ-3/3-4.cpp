// 3-4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <functional>
#include <cmath>

using namespace std;

vector<function<double(double, double)>> fnStorage;

double calculate(double a, double b, function<double(double, double)>& f)
{
    return f(a, b);
}

int main()
{
    fnStorage.push_back([](double x, double y) { return x + y; });                      // сложение
    fnStorage.push_back([](double x, double y) { return x - y; });                      // вычитание
    fnStorage.push_back([](double x, double y) { return x * y; });                      // умножение
    fnStorage.push_back([](double x, double y) { return static_cast<double>(x / y); }); // деление
    fnStorage.push_back([](double x, double y) { return pow(x, y); });                  // возведение в степень

    double a, b;
    setlocale(LC_ALL, "Russian");
    cout << "Введите два числа\n";
    cin >> a >> b;

    vector<char> oper = { '+', '-', '*', '/', '^'};

    for (int i = 0; i < fnStorage.size(); i++)
        cout << a << ' ' << oper[i] << ' ' << b << ' ' << '=' << ' ' << calculate(a, b, fnStorage[i]) << endl;

    cout << "Расчёт окончен.\n\n";
    
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
