#include "Shapes.h"

const double pi = 3.141592653589793238;

double Circle::getPerimeter() const
{
	return 2 * pi * r;
}

double Circle::getSquare() const
{
	return pi * r * r;
}

void Circle::getInfo() const
{
	using std::cout;
	cout << "Name: Circle.\n";
	cout << "Radius is " << r << ".\n";
	cout << "Perimeter is " << getPerimeter() << ".\n";
	cout << "Square is " << getSquare() << ".\n\n";
}