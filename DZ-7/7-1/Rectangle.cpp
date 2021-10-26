#include "Shapes.h"

double Rectangle::getPerimeter() const
{
	return a * 2 + b * 2;
}
double Rectangle::getSquare() const
{
	return a * b;
}
void Rectangle::getInfo() const
{
	using std::cout;
	cout << "Name: Rectangle.\n";
	cout << "Large side is " << a << ".\n";
	cout << "Small side is " << b << ".\n";
	cout << "Perimeter is " << getPerimeter() << ".\n";
	cout << "Square is " << getSquare() << ".\n\n";
}