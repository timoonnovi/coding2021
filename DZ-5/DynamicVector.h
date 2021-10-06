//
// Created by Nikita on 02.10.2021.
//

#include <iostream>
#include <vector>

#ifndef CHILDREN_DYNAMICVECTOR_H
#define CHILDREN_DYNAMICVECTOR_H

class DynamicVector {
public:
    // Конструктор
    DynamicVector(unsigned dimension);

    // Деструктор
    ~DynamicVector();

    // Функции-друзья
    friend std::ostream& operator<<(
            std::ostream&, const DynamicVector&);
    friend std::istream& operator>>(
            std::istream&, DynamicVector&);

    // Сеттер
    void set_components(const std::vector<double>& components);


    // Геттеры
    const double* get_components() const {
        return components;
    }

    const unsigned* get_dimension() const {
        return dimension;
    }

private:
    double* components;
    unsigned* dimension;
};



#endif //CHILDREN_DYNAMICVECTOR_H
