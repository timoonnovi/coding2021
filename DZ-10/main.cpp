#include <iostream>
#include <vector>

// Вариативные шаблоны -- принимают в себя неопределённое количество параметров
// Пакет параметров шаблона
// Выражения свёртки -- позволяют применять бинарные операторы к элементам пакета
// 1) ... OPERATOR args <=> ((arg1 OPERATOR arg2) OPERATOR arg3) OPERATOR arg4 и так далее
// 2) args OPERATOR ... <=> arg1 OPERATOR (arg2 OPERATOR (arg3 OPERATOR arg4))
// 3) special_arg OPERATOR ... OPERATOR args <=> ((special_arg OPERATOR arg1) OPERATOR arg2) OPERATOR arg3
// 4) args OPERATOR ... OPERATOR special_arg <=> arg1 OPERATOR (arg2 OPERATOR (arg3 OPERATOR special_arg))

// Статический и динамический полиморфизм
// Через классическое наследование -- динамический полиморфизм
// perimeter, area, info -- virtual
// Через шаблоны -- статический полиморфизм

// Статический п-м
template<typename Figure>
auto perimeter(Figure& figure) {
    return figure.perimeter();
}

// Первая реализация функции print через рекурсивную генерацию
// Функция -- условие остановки рекурсии
template<typename T>
void print_first_realization(T first_argument) {
    std::cout << first_argument << ' ';
}

// Первая реализация функции print через рекурсивную генерацию
// Основная функция
template<typename T, typename... Types>
void print_first_realization(T first_argument, Types... arguments) {
    print_first_realization(first_argument);
    print_first_realization(arguments...);
}

// Функция, возвращающая количество аргументов в пакете
template<typename... Types>
auto get_amount_of_arguments(Types... arguments) {
    return sizeof...(arguments);
}

// Вторая реализация print -- через if constexpr
template<typename T, typename... Types>
void print_second_realization(T first_argument, Types... arguments) {
    std::cout << first_argument << ' ';
    if constexpr(sizeof...(arguments) > 0) {
        print_second_realization(arguments...);
    }
}

// Функция суммы всех аргументов через выражение свёртки
template <typename... Types>
auto sum(Types... arguments) {
    auto result = (arguments + ...);
    return result;
}

// Функция поочерёдного деления через выражение свёртки
template <typename... Types>
auto divide(Types... arguments) {
//    return (... / arguments);
    return (arguments / ...);
}

// Класс, добавляющий разделитель для третьей реализации print
template<typename T>
class SeparatorAdder {
public:
    explicit SeparatorAdder(T& argument) : argument(argument) {}

    friend std::ostream& operator<<(std::ostream& os, const SeparatorAdder& wrapper) {
        return os << wrapper.argument << ' ';
    }

private:
    T& argument;
};

// Третья реализация функции print через выражение свёртки
template<typename... Types>
void print(Types... arguments) {
    (std::cout << ... << SeparatorAdder(arguments));
}

// Функция получения i-го аргумента
template <size_t needed_index, typename T, typename... Types>
auto get(T first_argument, Types... arguments) {
    if constexpr(needed_index == 0) {
        return first_argument;
    } else {
        return get<needed_index - 1>(arguments...);
    }
}

// Определение шаблонной функции вывода вектора
template <typename Element>
std::ostream& operator<<(std::ostream& ostr, const std::vector<Element>& elements) {
    for(const auto& item: elements) {
        ostr << item << ' ';
    }
    return ostr;
}

// CRTP -- curiosly recurring template pattern
// Функционал, аналогичный наследованию, но без его минусов

// Базовый класс -- в качестве шаблона принимает производный
template <typename DerivedClass>
class Base {
public:
    auto virtual_function_analog() {
        // Вызов функции производного класса с помощью
        // каста this к указателю на производный класс

        static_cast<DerivedClass*>(this)->virtual_function_analog();
    }
};

// Производный класс -- указывает себя как параметр шаблона
// базового при наследовании от него

class Derived : public Base<Derived> {
public:
    auto virtual_function_analog() {
        std::cout << "Hello from derived!" << std::endl;
    }
};

int main() {
//    print_first_realization(1, true, "Niki", 8.85);
//    std::cout << get_amount_of_arguments(1, true, "Niki", 8.85) << std::endl;
//    print_second_realization(1, 5.6, "MIPT");
//    std::cout << sum(1, 2, 3, 4, 5);
//    std::cout << std::endl;
//    std::cout << divide(6, 3, 2);
//    print(5, "Third Print!", 322);
//    std::cout << get<2>(1, 2, 3, 4, 5);

//    std::vector<int> numbers{1, 3, 5, 42};
//    std::cout << numbers;

    Derived derived;
    Base<Derived>* base_derived_ptr = &derived;
    base_derived_ptr->virtual_function_analog();
    return 0;

}