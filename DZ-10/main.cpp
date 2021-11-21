#include <iostream>
#include <vector>

// Âàðèàòèâíûå øàáëîíû -- ïðèíèìàþò â ñåáÿ íåîïðåäåë¸ííîå êîëè÷åñòâî ïàðàìåòðîâ
// Ïàêåò ïàðàìåòðîâ øàáëîíà
// Âûðàæåíèÿ ñâ¸ðòêè -- ïîçâîëÿþò ïðèìåíÿòü áèíàðíûå îïåðàòîðû ê ýëåìåíòàì ïàêåòà
// 1) ... OPERATOR args <=> ((arg1 OPERATOR arg2) OPERATOR arg3) OPERATOR arg4 è òàê äàëåå
// 2) args OPERATOR ... <=> arg1 OPERATOR (arg2 OPERATOR (arg3 OPERATOR arg4))
// 3) special_arg OPERATOR ... OPERATOR args <=> ((special_arg OPERATOR arg1) OPERATOR arg2) OPERATOR arg3
// 4) args OPERATOR ... OPERATOR special_arg <=> arg1 OPERATOR (arg2 OPERATOR (arg3 OPERATOR special_arg))

// Ñòàòè÷åñêèé è äèíàìè÷åñêèé ïîëèìîðôèçì
// ×åðåç êëàññè÷åñêîå íàñëåäîâàíèå -- äèíàìè÷åñêèé ïîëèìîðôèçì
// perimeter, area, info -- virtual
// ×åðåç øàáëîíû -- ñòàòè÷åñêèé ïîëèìîðôèçì

// Ñòàòè÷åñêèé ï-ì
template<typename Figure>
auto perimeter(Figure& figure) {
    return figure.perimeter();
}

// Ïåðâàÿ ðåàëèçàöèÿ ôóíêöèè print ÷åðåç ðåêóðñèâíóþ ãåíåðàöèþ
// Ôóíêöèÿ -- óñëîâèå îñòàíîâêè ðåêóðñèè
template<typename T>
void print_first_realization(T first_argument) {
    std::cout << first_argument << ' ';
}

// Ïåðâàÿ ðåàëèçàöèÿ ôóíêöèè print ÷åðåç ðåêóðñèâíóþ ãåíåðàöèþ
// Îñíîâíàÿ ôóíêöèÿ
template<typename T, typename... Types>
void print_first_realization(T first_argument, Types... arguments) {
    print_first_realization(first_argument);
    print_first_realization(arguments...);
}

// Ôóíêöèÿ, âîçâðàùàþùàÿ êîëè÷åñòâî àðãóìåíòîâ â ïàêåòå
template<typename... Types>
auto get_amount_of_arguments(Types... arguments) {
    return sizeof...(arguments);
}

// Âòîðàÿ ðåàëèçàöèÿ print -- ÷åðåç if constexpr
template<typename T, typename... Types>
void print_second_realization(T first_argument, Types... arguments) {
    std::cout << first_argument << ' ';
    if constexpr(sizeof...(arguments) > 0) {
        print_second_realization(arguments...);
    }
}

// Ôóíêöèÿ ñóììû âñåõ àðãóìåíòîâ ÷åðåç âûðàæåíèå ñâ¸ðòêè
template <typename... Types>
auto sum(Types... arguments) {
    auto result = (arguments + ...);
    return result;
}

// Ôóíêöèÿ ïîî÷åð¸äíîãî äåëåíèÿ ÷åðåç âûðàæåíèå ñâ¸ðòêè
template <typename... Types>
auto divide(Types... arguments) {
//    return (... / arguments);
    return (arguments / ...);
}

// Êëàññ, äîáàâëÿþùèé ðàçäåëèòåëü äëÿ òðåòüåé ðåàëèçàöèè print
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

// Òðåòüÿ ðåàëèçàöèÿ ôóíêöèè print ÷åðåç âûðàæåíèå ñâ¸ðòêè
template<typename... Types>
void print(Types... arguments) {
    (std::cout << ... << SeparatorAdder(arguments));
}

// Ôóíêöèÿ ïîëó÷åíèÿ i-ãî àðãóìåíòà
template <size_t needed_index, typename T, typename... Types>
auto get(T first_argument, Types... arguments) {
    if constexpr(needed_index == 0) {
        return first_argument;
    } else {
        return get<needed_index - 1>(arguments...);
    }
}

// Îïðåäåëåíèå øàáëîííîé ôóíêöèè âûâîäà âåêòîðà
template <typename Element>
std::ostream& operator<<(std::ostream& ostr, const std::vector<Element>& elements) {
    for(const auto& item: elements) {
        ostr << item << ' ';
    }
    return ostr;
}

// CRTP -- curiosly recurring template pattern
// Ôóíêöèîíàë, àíàëîãè÷íûé íàñëåäîâàíèþ, íî áåç åãî ìèíóñîâ

// Áàçîâûé êëàññ -- â êà÷åñòâå øàáëîíà ïðèíèìàåò ïðîèçâîäíûé
template <typename DerivedClass>
class Base {
public:
    auto virtual_function_analog() {
        // Âûçîâ ôóíêöèè ïðîèçâîäíîãî êëàññà ñ ïîìîùüþ
        // êàñòà this ê óêàçàòåëþ íà ïðîèçâîäíûé êëàññ

        static_cast<DerivedClass*>(this)->virtual_function_analog();
    }
};

// Ïðîèçâîäíûé êëàññ -- óêàçûâàåò ñåáÿ êàê ïàðàìåòð øàáëîíà
// áàçîâîãî ïðè íàñëåäîâàíèè îò íåãî

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
