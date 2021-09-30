#include <iostream>
#include <vector>

// Это вектор из линейной алгебры. 
// Имеет 2 поля – собственно компоненты вектора и размерность пространства.
struct Vector
{
	std::vector<double> components;
	unsigned int dim;

	// Функция расчёта модуля вектора.
	double abs(const Vector& v)
	{
		double tmp = 0;
		for (auto item : v.components)
		{
			tmp += pow(item, 2);
		}

		tmp = pow(tmp, 0.5);

		return tmp;
	}
};

// Вывод вектора. 
// Сначала размерность, затем компоненты.
std::ostream& operator<<(std::ostream& ostr,
	const Vector& vec)
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
std::istream& operator>>(std::istream& istr, Vector& v)
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Введите размерность вектора: ";
	istr >> v.dim;
	std::cout << "Введите компоненты вектора:  ";

	for (unsigned int i = 0u; i < v.dim; i++)
	{
		double tmp;
		istr >> tmp;
		v.components.push_back(tmp);
	}

	std::cout << '\n';

	return istr;
}

// Умножение вектора на число.
Vector operator*(const Vector& v, const double& num)
{
	Vector tmp;
	tmp.dim = v.dim;
	for (auto item : v.components)
	{
		tmp.components.push_back(item * num);
	}

	return tmp;
}

// Умножение вектора на число.
Vector& operator*=(Vector& v, const double& num)
{
	for (auto& item : v.components)
	{
		item *= num;
	}

	return v;
}

// Умножение числа на вектор.
Vector operator*(const double& num, const Vector& v)
{
	Vector tmp;
	tmp.dim = v.dim;
	for (auto item : v.components)
	{
		tmp.components.push_back(item * num);
	}

	return tmp;
}

// Сложение векторов.
Vector operator+(const Vector& v1, const Vector& v2)
{
	if (v1.dim != v2.dim)
	{
		setlocale(LC_ALL, "Russian");
		std::cout << "Ошибка: невозможно сложить векторы разных размерностей.\n";
		Vector tmp;
		return tmp;
	}

	Vector tmp;
	tmp.dim = v1.dim;

	for (unsigned int i = 0u; i < v1.dim; i++)
	{
		tmp.components.push_back(v1.components[i] + v2.components[i]);
	}

	return tmp;
}

// Тоже сложение векторов.
Vector& operator+=(Vector& v1, const Vector& v2)
{
	if (v1.dim != v2.dim)
	{
		setlocale(LC_ALL, "Russian");
		std::cout << "Ошибка: невозможно сложить векторы разных размерностей.\n";
		Vector tmp;
		return tmp;
	}

	for (unsigned int i = 0u; i < v1.dim; i++)
	{
		v1.components[i] += v2.components[i];
	}

	return v1;
}

// Вычитание векторов.
Vector operator-(const Vector& v1, const Vector& v2)
{
	if (v1.dim != v2.dim)
	{
		setlocale(LC_ALL, "Russian");
		std::cout << "Ошибка: невозможно сложить векторы разных размерностей.\n";
		Vector tmp;
		return tmp;
	}

	Vector tmp;
	tmp.dim = v1.dim;

	for (unsigned int i = 0u; i < v1.dim; i++)
	{
		tmp.components.push_back(v1.components[i] - v2.components[i]);
	}

	return tmp;
}

// Тоже вычитание векторов.
Vector& operator-=(Vector& v1, const Vector& v2)
{
	if (v1.dim != v2.dim)
	{
		setlocale(LC_ALL, "Russian");
		std::cout << "Ошибка: невозможно сложить векторы разных размерностей.\n";
		Vector tmp;
		return tmp;
	}

	for (unsigned int i = 0u; i < v1.dim; i++)
	{
		v1.components[i] -= v2.components[i];
	}

	return v1;
}

// Обращение вектора. В язычество. Во славу Сварога.
Vector& operator-(Vector& v)
{
	for (auto& item : v.components)
	{
		item *= -1;
	}

	return v;
}

// Функция скалярного произведения векторов.
double scalar_multiply(const Vector& v1, const Vector& v2)
{
	if (v1.dim != v2.dim)
	{
		setlocale(LC_ALL, "Russian");
		std::cout << "Ошибка: невозможно получить скалярное произведение векторов разной размерности.";
		return -228;
	}

	double result = 0;

	for (unsigned int i = 0u; i < v1.dim; i++)
	{
		result += v1.components[i] * v2.components[i];
	}

	return result;
}

int main()
{
	Vector v;

	setlocale(LC_ALL, "Russian");

	std::cout << "Введите вектор v:\n";
	std::cin >> v;
	std::cout << '\n';
	std::cout << "Модуль вектора v:\n";
	std::cout << v.abs() << '\n';
	std::cout << "Обращённый вектор v:\n";
	std::cout << -v;

	int a;

	std::cout << "Введите число:\n";
	std::cin >> a;
	std::cout << "v * a = " << v * a << '\n';
	std::cout << "Введите второй вектор u:\n";

	Vector u;

	std::cin >> u;
	std::cout << "v + u =\n" << v + u << '\n';
	std::cout << "v - u =\n" << v - u << '\n';
	std::cout << "Скалярное произведение (v, u) = " << scalar(v, u) << '\n';

	return 0;
}
