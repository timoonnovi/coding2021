// 4-4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

enum class Months
{
    JANUARY = 1,
    FEBRUARY = 2,
    MARCH = 3,
    APRIL = 4,
    MAY = 5,
    JUNE = 6,
    JULY = 7,
    AUGUST = 8,
    SEPTEMBER = 9,
    OCTOBER = 10,
    NOVEMBER = 11,
    DECEMBER = 12
};

int days_at_month(Months month)
{
    switch (month)
    {
    case Months::JANUARY:
    case Months::MARCH:
    case Months::MAY:
    case Months::JULY:
    case Months::AUGUST:
    case Months::OCTOBER:
    case Months::DECEMBER:
        return 31;
        break;
    case Months::FEBRUARY:
        return 28;
        break;
    case Months::APRIL:
    case Months::JUNE:
    case Months::SEPTEMBER:
    case Months::NOVEMBER:
        return 30;
        break;

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
