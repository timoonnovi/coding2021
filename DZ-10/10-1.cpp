// 10-1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

template<typename RT, typename... Types>
RT func1(Types ... args)
{
    RT tmp = (args + ...);
    return tmp;
}

template<typename RT, typename... Types>
void func2(RT f, Types ... args)
{
    std::cout << f(args...);
}

int func3(int a, int b)
{
    std::cout << a + b;
    return a + b;
}

int main()
{
    int a = 10;
    int b = 20;
    func2<int (*)(int, int), int, int>(func1<int, int>, a, b);
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
