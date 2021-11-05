#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <exception>
#include <string>

int days_at_month(int month, int year);

class DateException : public std::exception
{
private:
    std::string m_error;

public:
    DateException(std::string error) : m_error(error) {}

    const char* what() const noexcept { return m_error.c_str(); }
};

class Date
{
private:
	int m_year;
	int m_month;
	int m_day;

public:
    Date(int day = 0, int month = 1, int year = 1) : m_year(year), m_month(month), m_day(day)
    {
        try {
            if ((month < 1) || (month > 12))
                throw DateException("Incorrect month number value.");
            if ((day < 0) || (day > days_at_month(month, year)))
                throw DateException("Incorrect day value.");

            m_year = year;
            m_month = month;
            m_day = day;
        }
        catch (DateException& exception)
        {
            std::cerr << "Error: DateException has been caught: " << exception.what() << '\n';
        }
    }

    friend bool operator<(const Date& d1, const Date& d2);
    friend bool operator<=(const Date& d1, const Date& d2);
    friend bool operator>(const Date& d1, const Date& d2);
    friend bool operator>=(const Date& d1, const Date& d2);

    friend std::ostream& operator<<(std::ostream&, const Date&);
    friend std::istream& operator>>(std::istream&, Date&);

    int get_year() { return m_year; }
    int get_month() { return m_month; }
    int get_day() { return m_day; }
};

#endif // !DATE_H