#include "SmartPtr.h"

SmartPtr::SmartPtr(double var)
{
	m_ptr = new double{ var };
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
