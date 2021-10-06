#include "DynamicVector.h"

DynamicVector::DynamicVector(unsigned dimension) {
    std::cout << "Hi there from constructor" << std::endl;
    this->dimension = new unsigned(dimension);
    this->components = new double[dimension];
    for(auto i = 0u; i < dimension; i++) {
        this->components[i] = 0.;
    }
}

void DynamicVector::set_components(const std::vector<double>& components) {
    *(this->dimension) = components.size();
    double* new_components = new double[components.size()];
    for(auto i = 0u; i < components.size(); i++) {
        new_components[i] = components[i];
    }
    delete[] this->components;
    this->components = new_components;
}

DynamicVector::~DynamicVector() {
    std::cout << "Hi there from destructor" << std::endl;
    delete dimension;
    delete[] components;
}

std::ostream& operator<<(
        std::ostream& out, const DynamicVector& dynamicVector) {
    out << "Our Vector:\nDimension is " << *dynamicVector.get_dimension()
        << ", components are [";
    for(auto i = 0u; i < *dynamicVector.get_dimension(); i++) {
        out << dynamicVector.get_components()[i] << ", ";
    }
    out << ']';
    return out;
}

std::istream& operator>>(std::istream& in, DynamicVector& dynamicVector) {
    in >> *dynamicVector.dimension;
    std::vector<double> new_components(*dynamicVector.dimension);
    for(auto& item: new_components) {
        in >> item;
    }
    dynamicVector.set_components(new_components);
    return in;
}


