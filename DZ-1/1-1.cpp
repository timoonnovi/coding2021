#include <iostream>
#include <iomanip>

int main() {
    std::string name;
    int price, temperature;
    bool hasCashback;
    std::cout << "Product's name: ";
    std::cin >> name;
    std::cout << "Product's price: ";
    std::cin >> price;
    std::cout << "Is cash-back available for this product? (true/false) ";
    std::cin.setf(std::ios::boolalpha);
    std::cin >> hasCashback;
    std::cin.unsetf(std::ios::boolalpha);
    std::cout << "Maximum storing temperature: ";
    std::cin >> temperature;

    std::cout << '\n' << "*************** OUTPUT ***************" << "\n\n";

    std::cout << name << '\n';

    std::cout.setf(std::ios::left);
    std::cout << std::setw(17) << std::setfill('.') << "Price:";

    std::cout.unsetf(std::ios::dec);
    std::cout.setf(std::ios::hex);
    std::cout.setf(std::ios::uppercase);
    std::cout.unsetf(std::ios::left);
    std::cout.setf(std::ios::right);
    std::cout << std::setw(8) << std::setfill('0') << price << '\n';

    std::cout.unsetf(std::ios::hex);
    std::cout.unsetf(std::ios::uppercase);
    std::cout.unsetf(std::ios::right);
    std::cout.setf(std::ios::dec);
    std::cout.setf(std::ios::left);
    std::cout << "Has cash-back:";
    std::cout.setf(std::ios::boolalpha);
    std::cout.unsetf(std::ios::left);
    std::cout.setf(std::ios::right);
    std::cout << std::setw(11) << std::setfill('.') << hasCashback << '\n';

    std::cout.unsetf(std::ios::boolalpha);
    std::cout.unsetf(std::ios::right);
    std::cout.setf(std::ios::left);
    std::cout.setf(std::ios::showpos);
    std::cout << "Max temperature:";
    std::cout.unsetf(std::ios::left);
    std::cout.setf(std::ios::right);
    std::cout << std::setw(9) << std::setfill('.') << temperature << '\n';

    return 0;
}