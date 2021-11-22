// 10-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <new>

template<typename OT, typename ... Types>
OT* ChronoCreate(Types... args)
{
    OT* ptr = new OT(args...);
    return ptr;
}

class Chrono
{
private:
    int hours;
    int minutes;
    int seconds;
public:
    Chrono(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}
    ~Chrono() {}

    friend std::ostream& operator<<(std::ostream& ostr, const Chrono& time)
    {
        if (time.hours < 10) ostr << '0';
        ostr << time.hours << ':';
        if (time.minutes < 10) ostr << '0';
        ostr << time.minutes << ':';
        if (time.seconds < 10) ostr << '0';
        ostr << time.seconds << '\n';

        return ostr;
    }
};

int main()
{
    int a = 20, b = 14, c = 5;
    Chrono* time1 = ChronoCreate<Chrono, int, int, int>(a, b, c);
    std::cout << (*time1);
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
