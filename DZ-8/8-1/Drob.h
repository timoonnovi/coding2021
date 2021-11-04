#ifndef DROB_H
#define DROB_H

#include <iostream>
#include <stdexcept>

class BadDenominator : public std::exception
{
private:
    std::string m_error;

public:
    BadDenominator(std::string error) : m_error(error) {}

    const char* what() const noexcept { return m_error.c_str(); }
};

class Drob
{
private:
    int m_numerator;
    int m_denominator;

    int gcd(int a, int b) const;

public:
    // Конструктор по умолчанию
    Drob(int numerator = 0, int denominator = 1) :
        m_numerator(numerator), m_denominator(denominator)
    {
        if (m_denominator == 0)
        {
            throw BadDenominator("Denominator cannot be zero.");
        }
    }

    // Копирующий конструктор
    Drob(const Drob&);

    // Ввод-вывод
    friend std::ostream& operator<<(std::ostream& out, const Drob& d1);
    friend std::istream& operator>>(std::istream& istr, Drob& d);

    // Бинарные математические операторы
    friend Drob operator+(const Drob& d1, const Drob& d2);
    friend Drob operator-(const Drob& d1, const Drob& d2);
    friend Drob operator*(const Drob& d1, const Drob& d2);
    friend Drob operator/(const Drob& d1, const Drob& d2);

    // Унарные математические операторы
    friend Drob& operator+=(Drob& d1, const Drob& d2);
    friend Drob& operator-=(Drob& d1, const Drob& d2);
    friend Drob& operator*=(Drob& d1, const Drob& d2);
    friend Drob& operator/=(Drob& d1, const Drob& d2);
    friend Drob& operator-(Drob& d1);

    // Операторы сравнения
    friend bool operator==(const Drob& d1, const Drob& d2);
    friend bool operator!=(const Drob& d1, const Drob& d2);
    friend bool operator>(const Drob& d1, const Drob& d2);
    friend bool operator<(const Drob& d1, const Drob& d2);
    friend bool operator>=(const Drob& d1, const Drob& d2);
    friend bool operator<=(const Drob& d1, const Drob& d2);

    // Операторы присваивания (копирующий и перемещающий)
    Drob& operator=(const Drob& d);
    Drob& operator()(Drob& d);

    // Операторы инкремента и декремента
    Drob& operator++();
    Drob& operator--();
    Drob operator++(int);
    Drob operator--(int);

    // Возведение в -1 степень
    Drob obr() const;

    // Сокращение
    Drob sokrat() const;

    // Конвертация в double
    double Drob_to_double() const;

    int get_num() { return m_numerator; }
    int get_denum() { return m_denominator; }

};

#endif // DROB_H