#ifndef ENERGY_H
#define ENERGY_H

#include <iostream>
#include <map>
#include <cmath>

enum class Units
{
	J,
	ERG,
	CAL,
	eV
};

std::ostream& operator<<(std::ostream&, const Units&);
std::istream& operator>>(std::istream&, Units&);

static std::map <Units, double> Constants = { {Units::J, 1}, {Units::ERG, pow(10, 7)}, 
	{Units::CAL, 0.24}, {Units::eV, 6.24 * pow(10, 18)} };

class Energy
{
private:
	bool isMemAllocated = false;
	double* m_value;
	Units* m_unit;
	
public:
	Energy() : m_value(nullptr), m_unit(nullptr) {}
	Energy(double, Units);
	Energy(const Energy& another) : m_value (another.m_value), m_unit (another.m_unit) {}
	~Energy();

	void convert(Units unit);

	// Геттеры
	double getValue() { return *m_value; }
	Units getUnit() { return *m_unit; }

	// Сеттеры
	void setValue(double tmp) { *m_value = tmp; }
	void setUnit(Units tmp) { *m_unit = tmp; }

	// Ввод-вывод
	friend std::ostream& operator<<(std::ostream&, const Energy&);
	friend std::istream& operator>>(std::istream&, Energy&);
};

#endif // ENERGY_H
