#include "Shapes.h"

double Square::getPerimeter() const
{
	return a * 4;
}
double Square::getSquare() const
{
	return a * a;
}
void Square::getInfo() const
{
	using std::cout;
	cout << "Name: Square.\n";
	cout << "Side is " << a << ".\n";
	cout << "Perimeter is " << getPerimeter() << ".\n";
	cout << "Square is " << getSquare() << ".\n\n";
}