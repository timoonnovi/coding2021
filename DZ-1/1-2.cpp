#include <iostream>
#include <iomanip>

#define C 29979245800

using namespace std;

int main() {
	int a;
	double b;
	setlocale(LC_ALL, "Russian");

	cout << "Перевод из СИ в СГСЭ.\nВыберите перевод:\n\t1 - Кл -> Фр\n\t2 - А -> статА\n\t3 - В -> статВ\n";
	cin >> a;

	if (a == 1) {
		cout << "Введите величину: ";
		cin >> b;
		cout << 10 * b / C << " Фр";
		return 0;
	}
	if (a == 2) {
		cout << "Введите величину: ";
		cin >> b;
		cout << b * 10 / C << " статА";
		return 0;
	}
	if (a == 3) {
		cout << "Введите величину: ";
		cin >> b;
		cout << b * C / 100000000 << " статВ";
		return 0;
	}

	cout << "Выбранного перевода не существует.";

	return 0;
}