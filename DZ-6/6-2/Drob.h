#ifndef DROB_H
#define DROB_H

#include <iostream>

class Drob
{
private:
    int m_numerator;
    int m_denominator;

    int gcd(int a, int b);

public:
    Drob(int numerator = 0, int denominator = 1) :
        m_numerator(numerator), m_denominator(denominator)
    {
        if (m_denominator == 0)
        {
            std::cout << "Error: denominator can't be zero.\n";
        }
    }

    friend std::ostream& operator<<(std::ostream& out, const Drob& d1);
    friend std::istream& operator>>(std::istream& istr, Drob& d);

    friend Drob operator+(const Drob& d1, const Drob& d2);
    friend Drob operator-(const Drob& d1, const Drob& d2);
    friend Drob operator*(const Drob& d1, const Drob& d2);
    friend Drob operator/(const Drob& d1, const Drob& d2);

    friend Drob& operator+=(Drob& d1, const Drob& d2);
    friend Drob& operator-=(Drob& d1, const Drob& d2);
    friend Drob& operator*=(Drob& d1, const Drob& d2);
    friend Drob& operator/=(Drob& d1, const Drob& d2);
    friend Drob& operator-(Drob& d1);

    void obr();
    void sokrat();
    double Drob_to_double(const Drob& d);

    int get_num() { return m_numerator; }
    int get_denum() { return m_denominator; }

};

#endif // DROB_H