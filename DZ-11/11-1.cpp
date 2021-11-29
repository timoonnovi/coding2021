// 11-1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

constexpr double e = 2.7182818284;

constexpr double exp1(unsigned int x)
{
	if (x > 0)
		return e * exp1(x - 1);
	else
		return 1;
}

int main()
{
	constexpr int tmp1 = 10;
	constexpr double tmp2 = exp1(tmp1);
	std::cout << "e^10 = " << tmp2 << '\n';
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
