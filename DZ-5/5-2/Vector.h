#ifndef VECTOR_H
#define VECTOR_H
#include <vector>
#include <iostream>

// Это вектор из линейной алгебры. 
// Имеет 2 поля – собственно компоненты вектора и размерность пространства.
class Vector
{
private:
	std::vector<double> components;
	unsigned int dim;

public:
	// Функция расчёта модуля вектора.
	double abs();

	// Вывод вектора. 
	// Сначала размерность, затем компоненты.
	friend std::ostream& operator<<(std::ostream& ostr,
		const Vector& vec);

	// Ввод вектора.
	// Сначала размерность, затем компоненты.
	friend std::istream& operator>>(std::istream& istr, Vector& v);

	// Умножение вектора на число.
	friend Vector operator*(const Vector& v, const double& num);

	// Умножение вектора на число.
	friend Vector& operator*=(Vector& v, const double& num);

	// Умножение числа на вектор.
	friend Vector operator*(const double& num, const Vector& v);

	// Сложение векторов.
	friend Vector operator+(const Vector& v1, const Vector& v2);

	// Тоже сложение векторов.
	friend Vector& operator+=(Vector& v1, const Vector& v2);

	// Вычитание векторов.
	friend Vector operator-(const Vector& v1, const Vector& v2);

	// Тоже вычитание векторов.
	friend Vector& operator-=(Vector& v1, const Vector& v2);

	// Обращение вектора. В язычество. Во славу Сварога.
	friend Vector& operator-(Vector& v);

	// Функция скалярного произведения векторов.
	friend double scalar(const Vector& v1, const Vector& v2);
};

#endif // VECTOR_H