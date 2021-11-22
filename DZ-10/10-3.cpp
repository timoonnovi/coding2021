// 10-3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int size_in_bytes_1 = 0;

template<typename T>
void Size1(T arg)
{
    size_in_bytes_1 += sizeof(arg);
    return;
}

template<typename T, typename ... Types>
void Size1(T firstArg, Types... args)
{
    Size1(firstArg);
    Size1(args...);
    return;
}

int size_in_bytes_2 = 0;

template<typename ... Types>
auto Size2(Types... args)
{
    return (... + sizeof(args));
}

int main()
{
    int a = 1, b = 2, c = 5;
    Size1<int, int, int>(a, b, c);
    size_in_bytes_2 = Size2<int, int, int>(a, b, c);
    std::cout << "First method:  " << size_in_bytes_1 << " bytes." << '\n';
    std::cout << "Second method: " << size_in_bytes_2 << " bytes." << '\n';
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
