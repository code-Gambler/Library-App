/* Citation and Sources...
Final Project Milestone 5
Module: Book
Filename: Book.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"
#include"Lib.h"
#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
namespace sdds {
	//Default Constructor
	Book::Book()
	{
		m_authorName = nullptr;
	}

	//Rule of Three

	//Copy Constructor
	Book::Book(const Book& src):Publication(src)
	{
		if (src.authorName() != nullptr) {
			m_authorName = new char[strlen(src.authorName())+1];
			strcpy(m_authorName, src.authorName());
		}
		else {
			m_authorName = nullptr;
		}
	}

	//Copy Assignment
	Book& Book::operator=(const Book& src)
	{
		if (src.authorName() != nullptr) {
			delete[] m_authorName;
			Publication::operator=(src);
			(Publication&)*this = src;
			m_authorName = new char[strlen(src.authorName()) + 1];
			strcpy(m_authorName, src.authorName());
		}
		return *this;
	}


	//Queries

	//Returns the author's name
	const char* Book::authorName()const
	{
		return m_authorName;
	}

	//Returns the character 'B'
	char Book::type() const
	{
		return 'B';
	}

	//Reads from the console/file.
	std::istream& Book::read(std::istream& istr)
	{
		char authorName[256 + 1] = {""};
		Publication::read(istr);
		delete[] m_authorName;
		if (Publication::conIO(istr)) {
			istr.ignore();
			cout << "Author: ";
			istr.get(authorName, 256, '\n');
		}
		else{
			istr.ignore();
			istr.get(authorName, 256, '\n');
		}
		if (!istr.fail()) {
			m_authorName = new char[strlen(authorName) + 1];
			strcpy(m_authorName, authorName);
		}
		return istr;
	}

	//Writes to the console/file.
	std::ostream& Book::write(std::ostream& os) const
	{
		char authorName[SDDS_AUTHOR_WIDTH + 1] = {""};
		Publication::write(os);
		if (Publication::conIO(os)) {
			strncpy(authorName, m_authorName, SDDS_AUTHOR_WIDTH);
			os << " ";
			os.setf(ios::left);
			os << setw(SDDS_AUTHOR_WIDTH);	
			os << authorName;
			os.unsetf(ios::left);
			os << " |";
		}
		else {
			os << "\t";
			os << m_authorName;
		}
		return os;
	}

	//sets the membership id and resets Date
	void Book::set(int member_id)
	{
		Publication::set(member_id);
		Publication::resetDate();
	}

	//Returns true if authorname and publication is valid
	Book::operator bool() const
	{
		bool returnValue = false;
		if (Publication::operator bool() && m_authorName) {
			returnValue = true;
		}
		return returnValue;
	}
	//Destructor
	Book::~Book()
	{
		delete[] m_authorName;
		m_authorName = nullptr;
	}

}
