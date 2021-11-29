#include <iostream>
#include <cmath>

// Если дадут аргументы, известные на этапе компиляции, функция будет вычислена на этапе компиляции.
constexpr auto compute_coefficient(double e, double m_e, double h, double c) {
    return e * h / m_e / c;
}

auto compute_answer(double coefficient, double x) {
    return coefficient * x;
}

// constexpr -- constant expression
// могут быть функции и переменные

// очевидно, что на constexpr-переменные накладываются некоторые ограничения
// constexpr-фукнция не обязательно вычисляется на этапе компиляции

// Ограничения на constexpr-переменные и функции
// Переменные:
// 1. Переменная имеет скалярный тип
// 2. Переменная является указателем
// 3. Переменная является объектом с constexpr-конструктором или без конструктора; имеет в качестве
// полей только скалярные типы; имеет деструктор по умолчанию.
// 4. Переменная является статическим массивом.

// Функции:
// 1. Не имеет ассемблерных вставок
// 2. Не имеет goto-выражений
// 3. Использует внутри себя только другие constexpr-функции и выражения

// более точно и подробно можно почитать вот тут:
// https://habr.com/ru/post/228181/
// ВНИМАНИЕ! Там описано и для C++11, и для C++14, просмотрите статью целиком. Для C++11 ограничений больше.

constexpr auto factorial(unsigned n) {
    unsigned result = 1;
    for(auto i = 1u; i <= n; i++) {
        result *= i;
    }
    return result;
}


int main() {
    constexpr double e = 1.6e-19;
    constexpr double m_e = 9.1e-31;
    constexpr double h = 6.63e-34;
    constexpr double c = 3e8;
    // коэффициент вычисляется во время компиляции
    constexpr auto coefficient = compute_coefficient(e, m_e, h, c); // работает потому, что
                                                                    // аргументы constexpr
    // можно ещё чиселки передавать, тоже будет constexpr
    double x;
    std::cin >> x;
    std::cout << compute_answer(coefficient, x) << std::endl;

    // вычисляется во время компиляции -- иначе присвоить constexpr-переменной было бы нельзя
    constexpr auto result = factorial(5);
    std::cout << result;
}