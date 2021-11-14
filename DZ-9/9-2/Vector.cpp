#include "Vector.h"
#include <cmath>

// Функция расчёта модуля вектора.
template<typename T>
double Vector<T>::abs()
{
	double tmp = 0;
	for (auto item : components)
	{
		tmp += pow(item, 2);
	}

	tmp = pow(tmp, 0.5);

	return tmp;
}

// Вывод вектора. 
// Сначала размерность, затем компоненты.
template<typename T>
std::ostream& operator<<(std::ostream& ostr,
	const Vector<T>& vec)
{
	setlocale(LC_ALL, "Russian");
	ostr << "Размерность вектора: " << vec.dim << '\n';
	ostr << "Компоненты вектора:  ";

	for (auto i = 0u; i < vec.components.size(); i++) {
		ostr << vec.components[i] << ' ';
	}
	ostr << '\n';
	return ostr;
}

// Ввод вектора.
// Сначала размерность, затем компоненты.
template<typename T>
std::istream& operator>>(std::istream& istr, Vector<T>& v)
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Введите размерность вектора: ";
	istr >> v.dim;
	std::cout << "Введите компоненты вектора:  ";

	for (unsigned int i = 0u; i < v.dim; i++)
	{
		T tmp;
		istr >> tmp;
		v.components.push_back(tmp);
	}

	std::cout << '\n';

	return istr;
}

// Умножение вектора на число.
template<typename T>
Vector<T> operator*(const Vector<T>& v, const T& num)
{
	Vector<T> tmp;
	tmp.dim = v.dim;
	for (auto item : v.components)
	{
		tmp.components.push_back(item * num);
	}

	return tmp;
}

// Умножение вектора на число.
template<typename T>
Vector<T>& operator*=(Vector<T>& v, const T& num)
{
	for (auto& item : v.components)
	{
		item *= num;
	}

	return v;
}

// Умножение числа на вектор.
template<typename T>
Vector<T> operator*(const T& num, const Vector<T>& v)
{
	Vector<T> tmp;
	tmp.dim = v.dim;
	for (auto item : v.components)
	{
		tmp.components.push_back(item * num);
	}

	return tmp;
}

// Сложение векторов.
template<typename T>
Vector<T> operator+(const Vector<T>& v1, const Vector<T>& v2)
{
	if (v1.dim != v2.dim)
	{
		setlocale(LC_ALL, "Russian");
		std::cout << "Ошибка: невозможно сложить векторы разных размерностей.\n";
		Vector<T> tmp;
		return tmp;
	}

	Vector<T> tmp;
	tmp.dim = v1.dim;

	for (unsigned int i = 0u; i < v1.dim; i++)
	{
		tmp.components.push_back(v1.components[i] + v2.components[i]);
	}

	return tmp;
}

// Тоже сложение векторов.
template<typename T>
Vector<T>& operator+=(Vector<T>& v1, const Vector<T>& v2)
{
	if (v1.dim != v2.dim)
	{
		setlocale(LC_ALL, "Russian");
		std::cout << "Ошибка: невозможно сложить векторы разных размерностей.\n";
		Vector<T> tmp;
		return tmp;
	}

	for (unsigned int i = 0u; i < v1.dim; i++)
	{
		v1.components[i] += v2.components[i];
	}

	return v1;
}

// Вычитание векторов.
template<typename T>
Vector<T> operator-(const Vector<T>& v1, const Vector<T>& v2)
{
	if (v1.dim != v2.dim)
	{
		setlocale(LC_ALL, "Russian");
		std::cout << "Ошибка: невозможно сложить векторы разных размерностей.\n";
		Vector<T> tmp;
		return tmp;
	}

	Vector<T> tmp;
	tmp.dim = v1.dim;

	for (unsigned int i = 0u; i < v1.dim; i++)
	{
		tmp.components.push_back(v1.components[i] - v2.components[i]);
	}

	return tmp;
}

// Тоже вычитание векторов.
template<typename T>
Vector<T>& operator-=(Vector<T>& v1, const Vector<T>& v2)
{
	if (v1.dim != v2.dim)
	{
		setlocale(LC_ALL, "Russian");
		std::cout << "Ошибка: невозможно сложить векторы разных размерностей.\n";
		Vector<T> tmp;
		return tmp;
	}

	for (unsigned int i = 0u; i < v1.dim; i++)
	{
		v1.components[i] -= v2.components[i];
	}

	return v1;
}

// Обращение вектора. В язычество. Во славу Сварога.
template<typename T>
Vector<T>& operator-(Vector<T>& v)
{
	for (auto& item : v.components)
	{
		item = -item;
	}

	return v;
}

// Функция скалярного произведения векторов.
template<typename T>
T scalar(const Vector<T>& v1, const Vector<T>& v2)
{
	if (v1.dim != v2.dim)
	{
		setlocale(LC_ALL, "Russian");
		std::cout << "Ошибка: невозможно получить скалярное произведение векторов разной размерности.";
		return -228;
	}

	T result = 0;

	for (unsigned int i = 0u; i < v1.dim; i++)
	{
		result += v1.components[i] * v2.components[i];
	}

	return result;
}
