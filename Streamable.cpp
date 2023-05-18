/* Citation and Sources...
Final Project Milestone 5
Module: Streamable
Filename: Streamable.cpp
Version 1.0
Author	Steven David Pillay
Revision History
-----------------------------------------------------------
Date      Reason
2022/08/07  First Submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#include "Streamable.h"
namespace sdds {
	Streamable::~Streamable()
	{

	}
	std::ostream& Streamable::operator<<(std::ostream& ostr) const
	{
		return ostr;
	}
	std::istream& Streamable::operator>>(std::istream& istr)
	{
		return istr;
	}
}