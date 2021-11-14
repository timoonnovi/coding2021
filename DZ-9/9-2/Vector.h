#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
#include <iostream>

// Это вектор из линейной алгебры. 
// Имеет 2 поля – собственно компоненты вектора и размерность пространства.
template<typename T>
class Vector
{
private:
	std::vector<T> components;
	unsigned int dim;

public:
	// Функция расчёта модуля вектора.
	double abs();

	// Вывод вектора. 
	// Сначала размерность, затем компоненты.
	friend std::ostream& operator<<(std::ostream& ostr,
		const Vector<T>& vec);

	// Ввод вектора.
	// Сначала размерность, затем компоненты.
	friend std::istream& operator>>(std::istream& istr, Vector<T>& v);

	// Умножение вектора на число.
	friend Vector operator*(const Vector<T>& v, const T& num);

	// Умножение вектора на число.
	friend Vector& operator*=(Vector<T>& v, const T& num);

	// Умножение числа на вектор.
	friend Vector operator*(const T& num, const Vector<T>& v);

	// Сложение векторов.
	friend Vector operator+(const Vector<T>& v1, const Vector<T>& v2);

	// Тоже сложение векторов.
	friend Vector& operator+=(Vector<T>& v1, const Vector<T>& v2);

	// Вычитание векторов.
	friend Vector operator-(const Vector<T>& v1, const Vector<T>& v2);

	// Тоже вычитание векторов.
	friend Vector& operator-=(Vector<T>& v1, const Vector<T>& v2);

	// Обращение вектора. В язычество. Во славу Сварога.
	friend Vector& operator-(Vector<T>& v);

	// Функция скалярного произведения векторов.
	friend T scalar(const Vector<T>& v1, const Vector<T>& v2);
};

#endif // VECTOR_H