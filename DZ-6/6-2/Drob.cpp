#include "Drob.h"
#include <iostream>
#include <string>

int Drob::gcd(int a, int b) 
{
    if (a % b == 0)
        return b;
    if (b % a == 0)
        return a;
    if (a > b)
        return gcd(a % b, b);
    return gcd(a, b % a);
}

void Drob::sokrat()
{
    int tmp1 = m_numerator / gcd(m_numerator, m_denominator);
    int tmp2 = m_denominator / gcd(m_numerator, m_denominator);
    m_numerator = tmp1;
    m_denominator = tmp2;
}

void Drob::obr()
{
    int tmp1 = m_numerator;
    int tmp2 = m_denominator;

    m_numerator = tmp2;
    m_denominator = tmp1;
}

double Drob::Drob_to_double(const Drob& d)
{
    return static_cast<double>(d.m_numerator / d.m_denominator);
}

std::ostream& operator<<(std::ostream& out, const Drob& d1)
{
    out << d1.m_numerator << "/" << d1.m_denominator;
    return out;
}

std::istream& operator>>(std::istream& istr, Drob& d)
{
    std::string str;
    std::cout << "Enter a fraction without spaces:\n";
    istr >> str;
    std::string s = str.substr(0, str.find('/'));
    int num = stoi(s);
    str.erase(0, str.find('/') + 1);
    int denum = stoi(str);
    d.m_numerator = num;
    d.m_denominator = denum;

    return istr;
}

Drob operator+(const Drob& d1, const Drob& d2)
{
    Drob d;
    d.m_denominator = d1.m_denominator * d2.m_denominator;
    d.m_numerator = d1.m_numerator * d2.m_denominator + d2.m_numerator * d1.m_denominator;
    d.sokrat();

    return d;
}

Drob operator-(const Drob& d1, const Drob& d2)
{
    Drob d;
    d.m_denominator = d1.m_denominator * d2.m_denominator;
    d.m_numerator = d1.m_numerator * d2.m_denominator - d2.m_numerator * d1.m_denominator;
    d.sokrat();

    return d;
}

Drob operator*(const Drob& d1, const Drob& d2)
{
    Drob d;
    d.m_denominator = d1.m_denominator * d2.m_denominator;
    d.m_numerator = d1.m_numerator * d2.m_numerator;
    d.sokrat();

    return d;
}

Drob operator/(const Drob& d1, const Drob& d2)
{
    Drob d;
    d.m_denominator = d1.m_denominator * d2.m_numerator;
    d.m_numerator = d1.m_numerator * d2.m_denominator;
    d.sokrat();

    return d;
}

Drob& operator+=(Drob& d1, const Drob& d2)
{
    int tmp1, tmp2;
    tmp2 = d1.m_denominator * d2.m_denominator;
    tmp1 = d1.m_numerator * d2.m_denominator + d2.m_numerator * d1.m_denominator;
    d1.m_numerator = tmp1;
    d1.m_denominator = tmp2;
    d1.sokrat();

    return d1;
}

Drob& operator-=(Drob& d1, const Drob& d2)
{
    int tmp1, tmp2;
    tmp2 = d1.m_denominator * d2.m_denominator;
    tmp1 = d1.m_numerator * d2.m_denominator - d2.m_numerator * d1.m_denominator;
    d1.m_numerator = tmp1;
    d1.m_denominator = tmp2;
    d1.sokrat();

    return d1;
}

Drob& operator*=(Drob& d1, const Drob& d2)
{
    int tmp1, tmp2;
    tmp2 = d1.m_denominator * d2.m_denominator;
    tmp1 = d1.m_numerator * d2.m_numerator;
    d1.m_numerator = tmp1;
    d1.m_denominator = tmp2;
    d1.sokrat();

    return d1;
}

Drob& operator/=(Drob& d1, const Drob& d2)
{
    int tmp1, tmp2;
    tmp2 = d1.m_denominator * d2.m_numerator;
    tmp1 = d1.m_numerator * d2.m_denominator;
    d1.m_numerator = tmp1;
    d1.m_denominator = tmp2;
    d1.sokrat();

    return d1;
}

Drob& operator-(Drob& d1)
{
    d1.m_numerator *= -1;
    return d1;
}