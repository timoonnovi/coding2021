#include <iostream>
#include <vector>
#include <iomanip>
#include <bitset>

struct Vect{
    double x = 0;
    double y = 0, z = 0;
};

Vect operator*(Vect a, double lambda) {
    return {a.x * lambda, a.y * lambda, a.z * lambda};
}

Vect operator-(Vect a, Vect b) {
    Vect result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return result;
}

Vect operator-(Vect a) {
    return {-a.x, -a.y, -a.z};
}

struct Human {
    std::string name = "Niki";
    unsigned age = 12;
};

std::ostream& operator<<(std::ostream& ostr,
        const std::vector<int>& nums) {
    ostr << "[";
    for(auto i = 0u; i < nums.size(); i++) {
        ostr << nums[i];
        if (i != nums.size() - 1) ostr << ", ";
    }
    ostr << "]";
    return ostr;
}

std::istream& operator>>(std::istream& in, std::vector<int>& v) {
    for(auto& elem: v) {
        std::cin >> elem;
    }
    return in;
}

enum class Seasons {
    AUTUMN = 5,
    WINTER,
    SPRING = 7,
    SUMMER
};

int main(){
//    std::cout << "Input season: 5 for autumn, ..." << std::endl;
//    Seasons season;
//    int season_number;
//    std::cin >> season_number;
//    season = static_cast<Seasons>(season_number);
//    switch (season) {
//        case Seasons::AUTUMN:
//            std::cout << "Starting learning!" << std::endl;
//            break;
//        case Seasons::WINTER:
//            std::cout << "First session!" << std::endl;
//            break;
//        case Seasons::SPRING:
//            std::cout << "Keeping it going!" << std::endl;
//            break;
//        case Seasons::SUMMER:
//            std::cout << "Second session!" << std::endl;
//            break;
//        default:
//            std::cout << "Unknown season!" << std::endl;
//
//    }



//    Vect a{5, 6, 7};
//    std::cout << "-a is (" << -a.x << ", " <<
//              -a.y << ", " << -a.z << ")" << std::endl;
//    Vect b = a * 5;
//    std::cout << "b is (" << b.x << ", " <<
//        b.y << ", " << b.z << ")" << std::endl;
//    auto c = b - a;
//    std::cout << "b - a is (" << c.x << ", " <<
//        c.y << ", " << c.z << ")" << std::endl;


//    std::vector<int> numbers(5);
//    std::cin >> numbers;
//    std::cout << numbers << std::endl;



//    std::bitset<4> bools(0b1010);
//
//    std::cout << std::boolalpha;
//    std::cout << bools[0] << std::endl;
//    std::cout << bools[1] << std::endl;
//    std::cout << bools[2] << std::endl;
//    std::cout << bools[3] << std::endl;
//
//    bools[3] = false;
//    std::cout << bools << std::endl;
//

//
//    std::variant<int, double> var_var;
//    var_var = 5;
//    std::cout << std::get<int>(var_var) << std::endl;
//    var_var = 65.34;
//    std::cout << std::get<double>(var_var) << std::endl;

    int a = 5, b = 6;
    std::string op;
    std::cin >> op;


}
