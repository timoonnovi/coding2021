// 9-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vector.h"

int main()
{
	Vector<int> v;

	setlocale(LC_ALL, "Russian");

	std::cout << "¬ведите вектор v (размерность и компоненты):\n";
	std::cin >> v;
	std::cout << '\n';
	std::cout << "ћодуль вектора v: ";
	std::cout << v.abs() << "\n\n";
	std::cout << "ќбращЄнный вектор v:\n";
	std::cout << -v << '\n';

	int a;

	std::cout << "¬ведите число:\n";
	std::cin >> a;
	std::cout << "\nv * a =\n" << v * a << '\n';
	std::cout << "¬ведите второй вектор u:\n";

	Vector<int> u;

	std::cin >> u;
	std::cout << "v + u =\n" << v + u << '\n';
	std::cout << "v - u =\n" << v - u << '\n';
	std::cout << "—кал€рное произведение (v, u) = " << scalar(v, u) << '\n';

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
