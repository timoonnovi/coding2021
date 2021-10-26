#include "Shapes.h"
#include <cmath>

bool Triangle::check(double a, double b, double c)
{
	if ((a + b < c) || (a + c < b) || (b + c < a))
		return false;
	return true;
}

double Triangle::getPerimeter() const
{
	double p = 0;
	for (auto i = 0; i < 3; i++)
		p += Lines[i];
	return p;
}

double Triangle::getSquare() const
{
	double p = getPerimeter() * 0.5;
	double a = double((p - Lines[0]) * 100) / 100;
	double b = double((p - Lines[1]) * 100) / 100;
	double c = double((p - Lines[2]) * 100) / 100;

	a = double(a * p * 100) / 100;
	a = double(b * a * 100) / 100;
	a = double(c * a * 100) / 100;

	double s = pow(a, 0.5);
	return s;
}

void Triangle::getInfo() const
{
	using std::cout;
	cout << "Name: Triangle.\n";
	cout << "Lines are " << Lines[0] << ", " << Lines[1] << ", " << Lines[2] << ".\n";
	cout << "Perimeter is " << getPerimeter() << ".\n";
	cout << "Square is " << getSquare() << ".\n\n";
}