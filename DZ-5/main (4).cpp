#include <vector>
#include <iostream>
#include "Vector.h"
#include "DynamicVector.h"

int main() {
    // Работа с DynamicVector

    // Создание
    DynamicVector dynamicVector(2);

    // Задание компонент
    dynamicVector.set_components({5, 42, 43, 517, 322});

    // Вывод и ввод через перегруженные операторы
    std::cout << dynamicVector << std::endl;
    std::cin >> dynamicVector;
    std::cout << dynamicVector << std::endl;

    // Работа с Vector

    // Задание
    Vector v{{1, 2, 3}, 3};

    // Вывод
    std::cout << "Our Vector:\nDimension is " << v.get_dimension()
    << ", components are [";
    for(auto& element : v.get_components()) {
        std::cout << element << ", ";
    }
    std::cout << ']' << std::endl;

    // Проверка сеттера
    v.set_components({1, 2, 3, 4, 42});

    // Копипаста вывода
    std::cout << "Our Vector:\nDimension is " << v.get_dimension()
              << ", components are [";
    for(auto element : v.get_components()) {
        std::cout << element << ", ";
    }
    std::cout << ']' << std::endl;

}