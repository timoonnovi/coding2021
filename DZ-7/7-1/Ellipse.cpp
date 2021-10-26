#include "Shapes.h"

const double pi = 3.141592653589793238;

double Ellipse::getPerimeter() const
{
	return (a - b != 0) ? (pi * (a + b) * (1 + (3 * (pow((a - b) / (a + b), 2)) / (10 + pow((4 - 3 * pow((a - b) / (a + b), 2)), 0.5))))) : 0;
}

double Ellipse::getSquare() const
{
	return a * b * pi;
}

void Ellipse::getInfo() const
{
	using std::cout;
	cout << "Name: Ellipse.\n";
	cout << "Large semi-axis is " << a << ".\n";
	cout << "Small semi-axis is " << b << ".\n";
	cout << "Perimeter is " << getPerimeter() << ".\n";
	cout << "Square is " << getSquare() << ".\n\n";
}