// 4-3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Chronos {
    unsigned short Day         : 5;
    unsigned short Month       : 4;
    unsigned short Year        : 7;
    unsigned short Hour        : 5;
    unsigned short Minute      : 6;
    unsigned short Second      : 6;
    unsigned short Millisecond : 10;
};

int main()
{
    Chronos d;
    int a;

    setlocale(LC_ALL, "Russian");

    std::cout << "Введите день (1-31):";
    std::cin >> a;
    d.Day = a;
    std::cout << "Введите месяц (1-12):";
    std::cin >> a;
    d.Month = a;
    std::cout << "Введите год (00-99):";
    std::cin >> a;
    d.Year = a;
    std::cout << "Введите час (0-23):";
    std::cin >> a;
    d.Hour = a;
    std::cout << "Введите минуты (0-59):";
    std::cin >> a;
    d.Minute = a;
    std::cout << "Введите секунды (0-59):";
    std::cin >> a;
    d.Second = a;
    std::cout << "Введите миллисекунды (0-999):";
    std::cin >> a;
    d.Millisecond = a;

    std::cout << std::endl << "Дата: " << d.Day << ".";
    if (d.Month < 10) std::cout << "0";
    std::cout << d.Month << ".";
    std::cout << "20";
    if (d.Year < 10) std::cout << "0";
    std::cout << d.Year << " ";
    std::cout << d.Hour << ":";
    if (d.Minute < 10) std::cout << "0";
    std::cout << d.Minute << ":";
    if (d.Second < 10) std::cout << "0";
    std::cout << d.Second << ",";
    if (d.Millisecond < 100) std::cout << "0";
    if (d.Millisecond < 10) std::cout << "0";
    std::cout << d.Millisecond << std::endl;

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
