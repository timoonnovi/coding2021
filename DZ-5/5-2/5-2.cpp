#include <iostream>
#include <vector>
#include "Vector.h"

int main()
{
	Vector v;

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

	Vector u;

	std::cin >> u;
	std::cout << "v + u =\n" << v + u << '\n';
	std::cout << "v - u =\n" << v - u << '\n';
	std::cout << "—кал€рное произведение (v, u) = " << scalar(v, u) << '\n';

	return 0;
}
