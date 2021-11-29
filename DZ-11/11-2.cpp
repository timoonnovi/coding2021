// 11-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

constexpr bool isPrime(unsigned int p)
{
	for (unsigned int d = 2; d <= p / 2; ++d)
	{
		if (p % d == 0)
		{
			return false; // Найден делитель без остатка
		}
	}
	return (p > 1); // Такого делителя нет
}

constexpr int N_prime(int n)
{
	int count = 0;
	unsigned int tmp = 1u;
	while (count < n)
	{
		tmp++;
		if (isPrime(tmp)) count++;
	}
	return tmp;
}

int main()
{
	constexpr int N = 10;
	constexpr int num = N_prime(N);
	std::cout << "10th prime: " << num << '\n';
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
