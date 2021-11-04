#include "Drob.h"
#include <iostream>
#include <string>

Drob::Drob(const Drob& d)
{
    m_numerator = d.m_numerator;
    m_denominator = d.m_denominator;
}

int Drob::gcd(int a, int b) const
{
    if (a % b == 0)
        return b;
    if (b % a == 0)
        return a;
    if (a > b)
        return gcd(a % b, b);
    return gcd(a, b % a);
}

Drob Drob::sokrat() const
{
    Drob tmp;
    tmp.m_numerator = m_numerator / gcd(m_numerator, m_denominator);
    tmp.m_denominator = m_denominator / gcd(m_numerator, m_denominator);
    if (tmp.m_denominator < 0)
    {
        tmp.m_denominator *= -1;
        tmp.m_numerator *= -1;
    }
    return tmp;
}

Drob Drob::obr() const
{
    Drob d;
    int tmp1 = m_numerator;
    int tmp2 = m_denominator;

    d.m_numerator = tmp2;
    d.m_denominator = tmp1;

    return d;
}

double Drob::Drob_to_double() const
{
    double tmp1 = static_cast<double>(m_numerator);
    double tmp2 = static_cast<double>(m_denominator);
    double tmp = tmp1 / tmp2;
    return tmp;
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
    d = d.sokrat();

    return d;
}

Drob operator-(const Drob& d1, const Drob& d2)
{
    Drob d;
    d.m_denominator = d1.m_denominator * d2.m_denominator;
    d.m_numerator = d1.m_numerator * d2.m_denominator - d2.m_numerator * d1.m_denominator;
    d = d.sokrat();

    return d;
}

Drob operator*(const Drob& d1, const Drob& d2)
{
    Drob d;
    d.m_denominator = d1.m_denominator * d2.m_denominator;
    d.m_numerator = d1.m_numerator * d2.m_numerator;
    d = d.sokrat();

    return d;
}

Drob operator/(const Drob& d1, const Drob& d2)
{
    Drob d;
    d.m_denominator = d1.m_denominator * d2.m_numerator;
    d.m_numerator = d1.m_numerator * d2.m_denominator;
    d = d.sokrat();

    return d;
}

Drob& operator+=(Drob& d1, const Drob& d2)
{
    int tmp1, tmp2;
    tmp2 = d1.m_denominator * d2.m_denominator;
    tmp1 = d1.m_numerator * d2.m_denominator + d2.m_numerator * d1.m_denominator;
    d1.m_numerator = tmp1;
    d1.m_denominator = tmp2;
    d1 = d1.sokrat();

    return d1;
}

Drob& operator-=(Drob& d1, const Drob& d2)
{
    int tmp1, tmp2;
    tmp2 = d1.m_denominator * d2.m_denominator;
    tmp1 = d1.m_numerator * d2.m_denominator - d2.m_numerator * d1.m_denominator;
    d1.m_numerator = tmp1;
    d1.m_denominator = tmp2;
    d1 = d1.sokrat();

    return d1;
}

Drob& operator*=(Drob& d1, const Drob& d2)
{
    int tmp1, tmp2;
    tmp2 = d1.m_denominator * d2.m_denominator;
    tmp1 = d1.m_numerator * d2.m_numerator;
    d1.m_numerator = tmp1;
    d1.m_denominator = tmp2;
    d1 = d1.sokrat();

    return d1;
}

Drob& operator/=(Drob& d1, const Drob& d2)
{
    int tmp1, tmp2;
    tmp2 = d1.m_denominator * d2.m_numerator;
    tmp1 = d1.m_numerator * d2.m_denominator;
    d1.m_numerator = tmp1;
    d1.m_denominator = tmp2;
    d1 = d1.sokrat();

    return d1;
}

Drob& operator-(Drob& d1)
{
    d1.m_numerator *= -1;
    return d1;
}

bool operator==(const Drob& d1, const Drob& d2)
{
    return d1.Drob_to_double() == d2.Drob_to_double();
}

bool operator!=(const Drob& d1, const Drob& d2)
{
    return d1.Drob_to_double() != d2.Drob_to_double();
}

bool operator>(const Drob& d1, const Drob& d2)
{
    return d1.Drob_to_double() > d2.Drob_to_double();
}

bool operator<(const Drob& d1, const Drob& d2)
{
    return d1.Drob_to_double() < d2.Drob_to_double();
}

bool operator>=(const Drob& d1, const Drob& d2)
{
    return d1.Drob_to_double() >= d2.Drob_to_double();
}

bool operator<=(const Drob& d1, const Drob& d2)
{
    return d1.Drob_to_double() <= d2.Drob_to_double();
}

Drob& Drob::operator=(const Drob& d)
{
    if (this != &d)
    {
        m_numerator = d.m_numerator;
        m_denominator = d.m_denominator;
    }
    return *this;
}

Drob& Drob::operator()(Drob& d)
{
    *this = d;
    return *this;
}

Drob& Drob::operator++()
{
    m_numerator += m_denominator;
    return *this;
}

Drob& Drob::operator--()
{
    m_numerator -= m_denominator;
    return *this;
}

Drob Drob::operator++(int)
{
    Drob tmp(m_numerator, m_denominator);
    ++(*this);
    return tmp;
}

Drob Drob::operator--(int)
{
    Drob tmp(m_numerator, m_denominator);
    --(*this);
    return tmp;
}