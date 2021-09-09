#include <iostream>>
#include <cmath>

using namespace std;

int main() {
	double a, b, c;

	setlocale(LC_ALL, "Russian");

	cout << " вадратное уравнение имеет вид ах^2 + bx + c = 0" << endl;
	cout << "¬ведите коэффициент а : ";
	cin >> a;
	cout << "¬ведите коэффициент b: ";
	cin >> b;
	cout << "¬ведите коэффициент c: ";
	cin >> c;

	double D = b * b - (4 * a * c);

	if (D < 0) cout << "”равнение не имеет решений в действительных числах";
	else {
		if (D == 0) {
			cout << "”равнение имеет одно решение: х = ";
			cout << -b / (2 * a);
		}
		else {
			cout << "”равнение имеет два решени€: х1 = ";
			cout << (-b + pow(D, 0.5)) / (2 * a);
			cout << ", х2 = ";
			cout << (-b - pow(D, 0.5)) / (2 * a);
		}
	}

	return 0;
}