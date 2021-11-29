#include <iostream>
#include <vector>
#include <type_traits>

template <typename T>
auto get_argument_and_do_something(T&& argument) { // универсальная ссылка, принимает и lvalue, и rvalue
    do_something(std::forward<T>(argument)); // если lvalue -- просто передача,
                                             // если rvalue -- std::move
}

// по умолчанию используем передачу по значению
// по ссылке -- только если это необходимо

// SFINAE -- substitution failure is not an error
// Ошибка подстановки ошибкой не является

template <typename T, typename = std::enable_if_t<std::is_convertible_v<T, double>>>
auto multiply_by_three(T argument) {
    return argument * 3;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vector) {
    for(const auto& item : vector) {
        os << item << ' ';
    }
    return os;
}


int main() {
    std::vector<int> numbers;
    std::cout << numbers; // так как мы определили оператор вывода, ошибки нет
    // иначе будет ошибка о том, что подходящей функции не найдено -- ошибка подстановки
    std::cout << multiply_by_three(5) << std::endl;
    std::cout << multiply_by_three("NIKI") << std::endl; // не работает, нет подходящей функции
    // произошла ошибка подстановки, и ошибки в функции поэтому нет -- со строкой она просто
    // не проверяется
}