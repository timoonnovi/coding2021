#include <iostream>>
#include <cmath>

using namespace std;

int main() {
	double a, b, c;

	setlocale(LC_ALL, "Russian");

	cout << "Квадратное уравнение имеет вид ах^2 + bx + c = 0" << endl;
	cout << "Введите коэффициент а : ";
	cin >> a;
	cout << "Введите коэффициент b: ";
	cin >> b;
	cout << "Введите коэффициент c: ";
	cin >> c;

	cout << '\n';

	if (a == 0)
	{
		if ((b == 0) && (c != 0))
		{
			cout << "Нет решений";
			return 0;
		}
		if (b == 0)
		{
			cout << "Бесконечность решений, х = любое вещественное число";
			return 0;
		}
		cout << "Уравнение линейное и имеет одно решение: х = ";
		cout << -c / b;
		return 0;
	}

	double D = b * b - (4 * a * c);

	if (D < 0) cout << "Уравнение не имеет решений в действительных числах";
	else {
		if (D == 0) {
			cout << "Уравнение имеет одно решение: х = ";
			cout << -b / (2 * a);
		}
		else {
			cout << "Уравнение имеет два решения: х1 = ";
			cout << (-b + pow(D, 0.5)) / (2 * a);
			cout << ", х2 = ";
			cout << (-b - pow(D, 0.5)) / (2 * a);
		}
	}

	return 0;
}