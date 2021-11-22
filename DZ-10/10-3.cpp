// 10-3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

template<typename RT, typename ... Types>
RT Size1(RT firstArg, Types... args)
{
    if constexpr (sizeof...(args) > 0)
    {
        return Size1(firstArg) + Size1(args...);
    }
    else
    {
        return sizeof(firstArg);
    }
}

template<typename T, typename... Types>
void print_second_realization(T first_argument, Types... arguments) {
    std::cout << first_argument << ' ';
    if constexpr (sizeof...(arguments) > 0) {
        print_second_realization(arguments...);
    }
}

template<typename ... Types>
auto Size2(Types... args)
{
    return (... + sizeof(args));
}

int main()
{
    int a = 1, b = 2, c = 5;
    int size_in_bytes_1, size_in_bytes_2;

    size_in_bytes_1 = Size1<int, int, int>(a, b, c);
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
