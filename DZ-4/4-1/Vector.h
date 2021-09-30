#pragma once
#include <vector>
#include <iostream>

// Это вектор из линейной алгебры. 
// Имеет 2 поля – собственно компоненты вектора и размерность пространства.
struct Vector
{
	std::vector<double> components;
	unsigned int dim;

	// Функция расчёта модуля вектора.
	double abs();
};

// Вывод вектора. 
// Сначала размерность, затем компоненты.
std::ostream& operator<<(std::ostream& ostr,
	const Vector& vec);

// Ввод вектора.
// Сначала размерность, затем компоненты.
std::istream& operator>>(std::istream& istr, Vector& v);

// Умножение вектора на число.
Vector operator*(const Vector& v, const double& num);

// Умножение вектора на число.
Vector& operator*=(Vector& v, const double& num);

// Умножение числа на вектор.
Vector operator*(const double& num, const Vector& v);

// Сложение векторов.
Vector operator+(const Vector& v1, const Vector& v2);

// Тоже сложение векторов.
Vector& operator+=(Vector& v1, const Vector& v2);

// Вычитание векторов.
Vector operator-(const Vector& v1, const Vector& v2);

// Тоже вычитание векторов.
Vector& operator-=(Vector& v1, const Vector& v2);

// Обращение вектора. В язычество. Во славу Сварога.
Vector& operator-(Vector& v);

// Функция скалярного произведения векторов.
double scalar(const Vector& v1, const Vector& v2);