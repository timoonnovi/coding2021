#include <vector>
#ifndef CHILDREN_VECTOR_H
#define CHILDREN_VECTOR_H

class Vector {
public:
    // Конструктор
    Vector() = default;

    // Перегрузки конструкторов
    Vector(const std::vector<double>& new_components,
           unsigned new_dimension):
            components(new_components), dimension(new_dimension) {}

    Vector(const std::vector<double>& new_components):
            components(new_components), dimension(new_components.size()) {}
    Vector(unsigned new_dimension):
            components(new_dimension), dimension(new_dimension) {}

    // Копи-конструктор
    Vector(const Vector& another):
            components(another.components),
            dimension(another.dimension)
    {}

    // Геттеры и сеттеры
    const std::vector<double>& get_components() const;

    unsigned get_dimension() const;

    void set_dimension(unsigned dimension);

    void set_components(const std::vector<double>& components);

private:
    std::vector<double> components;
    unsigned dimension;
};


#endif //CHILDREN_VECTOR_H
