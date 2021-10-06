#include "Vector.h"

const std::vector<double>& Vector::get_components() const {
    return components;
}

unsigned Vector::get_dimension() const {
    return dimension;
}

void Vector::set_dimension(unsigned dimension) {
    this->dimension = dimension;
    components.resize(dimension);
}

void Vector::set_components(const std::vector<double>& components) {
    this->components = components;
    dimension = components.size();
}