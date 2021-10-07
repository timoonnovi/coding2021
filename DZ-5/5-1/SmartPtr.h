#ifndef SMART_PTR
#define SMART_PTR

#include <iostream>

class SmartPtr
{
private:
	double* m_ptr;
	bool isMemAllocated = false;
public:
	// Êîíñòðóêòîðû
	SmartPtr() = default;
	SmartPtr(double* ptr) : m_ptr(ptr) {}
	SmartPtr(double);
	SmartPtr(const SmartPtr& another) : m_ptr(another.m_ptr) {}

	// Äåñòðóêòîð
	~SmartPtr();

	friend double& operator* (SmartPtr);
	friend std::ostream& operator<<(std::ostream&, const SmartPtr&);
};

#endif // SMART_PTR

