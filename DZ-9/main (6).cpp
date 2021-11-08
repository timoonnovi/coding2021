#include <iostream>
#include <cmath>
#include <array>
#include <vector>


template <typename T_1, typename T_2>
auto max(T_1 lhs, T_2 rhs) { // Шаблон функции
    return (lhs < rhs) ? rhs : lhs;
}

template <typename T> // Шаблон переменной
T e = static_cast<T>(2.718281828459045);

template <typename T> // Шаблон типа
using matrix_t = std::vector<std::vector<T>>;

template <typename T> // Шаблон класса
class multiplier_by_two {
public:
    auto operator()(T value) {
        return value * 2;
    }
};

template <> // Частичная специализация шаблона класса
class multiplier_by_two<std::string> {
public:
    auto operator()(std::string value) {
        return value + value;
    }
};


int main() {


    int left = 5;
    unsigned right = 6;
    std::cout << max(left, right) << std::endl; // Использование шаблонной функции,
                                                // компилятор сам определяет тип
    std::cout << max<long long, long long>(left, right) << std::endl; // Использование шаблонной функции,
                                                                      // указываем тип

    auto multiplier = multiplier_by_two<std::string>(); // Использование частичной специализации
    std::cout << multiplier("5") << std::endl;     // шаблона класса

    matrix_t<double> matrix; // Использование шаблона типа

    std::array<int, 10> numbers_as_array{}; // Передача нетипового параметра шаблона
    numbers_as_array[5] = 10;               // в класс array для создания массива
    for(auto i : numbers_as_array) {        // фиксированной длины
        std::cout << i << ' ';
    }

}