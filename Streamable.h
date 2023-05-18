/* Citation and Sources...
Final Project Milestone 5
Module: Streamable
Filename: Streamable.h
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
#ifndef SDDS_STREAMABLECLASS_H
#define SDDS_STREAMABLECLASS_H
#include<iostream>
namespace sdds {
	class Streamable
	{
	public:
		virtual std::ostream& write(std::ostream& ostr)const = 0;
		virtual std::istream& read(std::istream& istr) = 0;
		virtual bool conIO(std::ios& ios)const = 0;
		virtual operator bool()const = 0;
		virtual ~Streamable();
		virtual std::ostream& operator<<(std::ostream& ostr)const;
		virtual std::istream& operator>>(std::istream& istr);
	};
}
#endif // !SDDS_STREAMABLECLASS_H



