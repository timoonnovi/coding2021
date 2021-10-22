#include "SmartPtr.h"

SmartPtr::SmartPtr(double var)
{
	m_ptr = new double{ var };
	isMemAllocated = true;
	return;
}

SmartPtr::SmartPtr(double* ptr)
{
	m_ptr = new double{ *ptr };
	isMemAllocated = true;
	return;
}

SmartPtr::~SmartPtr()
{
	if (isMemAllocated)
	{
		delete m_ptr;
		m_ptr = nullptr;
	}
	return;
}

double& operator* (SmartPtr ptr)
{
	return *ptr.m_ptr;
}

std::ostream& operator<<(std::ostream& ostr, const SmartPtr& ptr)
{
	ostr << ptr.m_ptr;
	return ostr;
}
