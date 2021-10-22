#ifndef SMART_PTR
#define SMART_PTR

#include <iostream>
#include <utility>

class SmartPtr
{
private:
	double* m_ptr;
	bool isMemAllocated = false;
public:
	// Конструкторы
	SmartPtr() = default;
	SmartPtr(double* ptr);
	SmartPtr(double);
	SmartPtr(const SmartPtr& another)
	{
		m_ptr = new double;
		isMemAllocated = true;
		*m_ptr = *another.m_ptr;
	}
	SmartPtr(SmartPtr&& another) : m_ptr(another.m_ptr)
	{
		another.m_ptr = nullptr;
		return;
	}

	// Деструктор
	~SmartPtr();

	friend double& operator* (SmartPtr);
	friend std::ostream& operator<<(std::ostream&, const SmartPtr&);
};

#endif // SMART_PTR
