#include "Energy.h"
#include <map>
#include <string>

Energy::Energy(double value, Units unit)
{
	m_value = new double(value);
	m_unit = new Units(unit);
	isMemAllocated = true;
	return;
}

Energy::~Energy()
{
	if (isMemAllocated)
	{
		delete m_unit;
		m_unit = nullptr;
		delete m_value;
		m_value = nullptr;
	}
	return;
}

void Energy::convert(Units unit)
{
	if (*m_unit == unit) return;

	double tmp1 = Constants[unit]; 
	double tmp2 = Constants[*m_unit];
	double tmp = tmp1 / tmp2;

	*m_value *= tmp;

	*m_unit = unit;
}

std::ostream& operator<<(std::ostream& ostr, const Units& unit)
{
	std::string tmp;

	if (unit == Units::J) tmp = "J";
	if (unit == Units::CAL) tmp = "CAL";
	if (unit == Units::ERG) tmp = "ERG";
	if (unit == Units::eV) tmp = "eV";

	ostr << tmp;

	return ostr;
}

std::istream& operator>>(std::istream& istr, Units& unit)
{
	std::string tmp;
	istr >> tmp;

	if (tmp == "J") unit = Units::J;
	else if (tmp == "CAL") unit = Units::CAL;
	else if (tmp == "ERG") unit = Units::ERG;
	else if (tmp == "eV") unit = Units::eV;

	return istr;
}

std::ostream& operator<<(std::ostream& ostr, const Energy& en)
{
	ostr << *en.m_value << ' ' << *en.m_unit << '\n';
	return ostr;
}

std::istream& operator>>(std::istream& istr, Energy& en)
{
	double val;
	Units unit;

	istr >> val >> unit;

	en.m_value = new double(val);
	en.m_unit = new Units(unit);
	en.isMemAllocated = true;

	return istr;
}
