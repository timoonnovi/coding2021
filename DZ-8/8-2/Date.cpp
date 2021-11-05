#include "Date.h"

int days_at_month(int month, int year = 1)
{
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
		break;
	case 2:
		if (year % 4 != 0)
			return 28;
		else
			return 29;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
		break;
	}
}

bool operator<(const Date& d1, const Date& d2)
{
	if (d1.m_year < d2.m_year) return true;
	if (d1.m_year > d2.m_year) return false;

	if (d1.m_month < d2.m_month) return true;
	if (d1.m_month > d2.m_month) return false;

	if (d1.m_day < d2.m_day) return true;
	else return false;
}

bool operator<=(const Date& d1, const Date& d2)
{
	if (d1.m_year < d2.m_year) return true;
	if (d1.m_year > d2.m_year) return false;

	if (d1.m_month < d2.m_month) return true;
	if (d1.m_month > d2.m_month) return false;

	if (d1.m_day <= d2.m_day) return true;
	else return false;
}

bool operator>(const Date& d1, const Date& d2)
{
	if (d1.m_year > d2.m_year) return true;
	if (d1.m_year < d2.m_year) return false;

	if (d1.m_month > d2.m_month) return true;
	if (d1.m_month < d2.m_month) return false;

	if (d1.m_day > d2.m_day) return true;
	else return false;
}

bool operator>=(const Date& d1, const Date& d2)
{
	if (d1.m_year > d2.m_year) return true;
	if (d1.m_year < d2.m_year) return false;

	if (d1.m_month > d2.m_month) return true;
	if (d1.m_month < d2.m_month) return false;

	if (d1.m_day >= d2.m_day) return true;
	else return false;
}

std::ostream& operator<<(std::ostream& ostr, const Date& d)
{
	if (d.m_day < 10) ostr << '0';
	ostr << d.m_day << '.';
	if (d.m_month < 10) ostr << '0';
	ostr << d.m_month << '.';
	if ((d.m_year >= 0) && (d.m_year < 10))
	{
		ostr << '0' << d.m_year << '\n';
		return ostr;
	}
	if ((d.m_year < 0) && (d.m_year > -10))
	{
		ostr << "-0" << -d.m_year << '\n';
		return ostr;
	}
	ostr << d.m_year << '\n';
	return ostr;
}

std::istream& operator>>(std::istream& istr, Date& d)
{
	std::string date;
	try
	{
		istr >> date;
		d.m_day = stoi(date.substr(0, date.find('.')));
		date.erase(0, date.find('.') + 1);
		d.m_month = stoi(date.substr(0, date.find('.')));
		date.erase(0, date.find('.') + 1);
		d.m_year = stoi(date.substr(0, date.find('.')));

		if ((d.m_month < 1) || (d.m_month > 12))
			throw DateException("Incorrect month number value.");
		if ((d.m_day < 0) || (d.m_day > days_at_month(d.m_month, d.m_year)))
			throw DateException("Incorrect day value.");
	}
	catch (...)
	{
		std::cerr << "Incorrect date input format or value.\n";
	}
	
	return istr;
}