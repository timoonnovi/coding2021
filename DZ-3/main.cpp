#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

inline bool is_leap(int year) {
    return (year % 4 == 0) && (year % 400 == 0 || year % 100 != 0);
}

auto inc(int& i) {
    i += 1;
}

int fact(int num) {
    if (num == 0) return 1;
    return fact(num - 1) * num;
}

auto exec(const std::function<bool(int)>& f, int arg) {
    auto res = f(arg);
    return res;
}


auto add (auto x) {
    return x + x;
}

int main() {
    std::vector<int> numbers = {143, 245, 524, 25, 235, 1'132'424};
    std::function<int(int, int)> power = [](int num, int deg) {
        auto current_degree = 1;
        for(auto i = 0; i < deg; i++) {
            current_degree *= num;
        }
        return current_degree;
    };
//    std::cout << power(5, 4) << std::endl;
//    std::cout << add(std::string("5.4")) << std::endl;
    std::cout << fact(6) << std::endl;
}