/* Citation and Sources...
Final Project Milestone 5
Module: Publication
Filename: Publication.cpp
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
#include "Publication.h"
#include"Lib.h"
#include<iostream>
#include<iomanip>
#include<string>
#include<string.h>
#include<cstring>
using namespace std;
namespace sdds {
	//Default Constructer
	Publication::Publication()
	{
		m_title = nullptr;
		strcpy(m_shelfId, "");
		m_membership = 0;
		m_libRef = -1;
		m_date.resetDate();
	}

	//Copy Constructer
	Publication::Publication(const Publication& obj) {

		if (obj.operator const char *() == nullptr) {
			m_title = nullptr;
		}
		else {
			m_title = new char[strlen(obj.operator const char* ()) + 1];
			strcpy(m_title, obj.operator const char* ());
		}
		strcpy(m_shelfId, obj.shelfId());
		m_membership = obj.membership();
		m_libRef = obj.getRef();
		m_date = obj.checkoutDate();
	}


	//Copy Assignment
	Publication& Publication::operator=(const Publication& obj)
	{
		delete[] m_title;
		if (obj.operator const char* () == nullptr) {
			m_title = nullptr;
		}
		else {
			m_title = new char[strlen(obj.m_title) + 1];
			strcpy(m_title, obj.operator const char* ());
		}
		strcpy(m_shelfId, obj.shelfId());
		m_membership = obj.membership();
		m_libRef = obj.getRef();
		m_date = obj.checkoutDate();
		return *this;
	}

	// Sets the membership attribute to either zero or a five-digit integer.
	void Publication::set(int member_id)
	{
		if (member_id > 9999) {
			m_membership = member_id;
		}
		else {
			m_membership = 0;
		}
	}

	// Sets the **libRef** attribute value
	void Publication::setRef(int value)
	{
		m_libRef = value;
	}

	// Sets the date to the current date of the system.
	void Publication::resetDate()
	{
		m_date.resetDate();
	}

	//reads from the console/file
	istream& Publication::read(istream& istr)
	{
		delete[] m_title;
		strcpy(m_shelfId, "");
		m_membership = 0;
		m_libRef = -1;
		m_date.resetDate();

		char title[255 + 1]={""};
		char shelfId[10 + 1]={""};
		int membership = 0;
		int libRef = -1;
		Date date;
		if (conIO(istr)) {
			cout << "Shelf No: ";
			istr >> shelfId;
			if (strlen(shelfId) != SDDS_SHELF_ID_LEN) {
				istr.setstate(ios_base::failbit);
			}
			cout << "Title: ";
			if (!(istr.fail())) {
				istr.ignore(1000, '\n');
				istr.getline(title, 256);
			}
			cout << "Date: ";
			if (!(istr.fail())) {
				istr >> date;
			}
		}
		else {
			istr >> libRef >> shelfId;
			istr.ignore();
			istr.getline(title, 256, '\t') >> membership >> date;
		}
		if (date.errCode()) {
			istr.setstate(ios_base::failbit);
		}
		if (!(istr.fail())) {
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
			strcpy(m_shelfId, shelfId);
			m_membership = membership;
			m_date = date;
			m_libRef = libRef;
		}
		return istr;
	}

	//Queries

	//Returns the character 'P' to identify this object as a "Publication object"
	char Publication::type() const
	{
		return 'P';
	}

	//Returns true is the publication is checkout (membership is non-zero)
	bool Publication::onLoan() const
	{
		return m_membership != 0;
	}

	//Returns the date attribute
	Date Publication::checkoutDate() const
	{
		return m_date;
	}
	
	//Returns true if the argument title appears anywhere in the title of the 
	bool Publication::operator==(const char* title) const
	{
		return strstr(m_title, title);
	}
	
	//Returns the title attribute
	Publication::operator const char* () const
	{
		return m_title;
	}
	
	//Returns the libRef attirbute.
	int Publication::getRef() const
	{
		return m_libRef;
	}
	
	//Returns If the object is in a valid State or not
	Publication::operator bool() const{
		return (m_shelfId && m_title);
	}

	//Returns true if the incoming object is console object
	bool Publication::conIO(ios& io) const{
		return (&io == &cin)|| (&io == &cout);
	}

	//Returns the shelf Id
	const char* Publication::shelfId()const {
		return m_shelfId;
	}

	//Returns the membership id
	int Publication::membership()const {
		return m_membership;
	}
	
	//writes to console/file
	ostream& Publication::write(ostream& os) const
	{
		char title[SDDS_TITLE_WIDTH + 1] = {""};
		if (conIO(os)) {
			strncpy(title, m_title, SDDS_TITLE_WIDTH);
			os << "| " << m_shelfId << " | ";
			os.setf(ios::left);
			os.fill('.');
			os << setw(SDDS_TITLE_WIDTH);
			os << title;
			os.unsetf(ios::left);
			os.fill(' ');
			os << " | ";
			if (m_membership) {
				os.width(5);
				os << m_membership;
			}
			else {
				os << " N/A ";
			}
			os << " | ";
			os << m_date << " |";
		}
		else{
			os << type() << "\t";
			os << m_libRef << "\t";
			os << m_shelfId << "\t";
			os << m_title << "\t";
			os << m_membership << "\t";
			os << m_date;
		}
		strcpy(title, "");
		return os;
	}


	void Publication::setMembership(int membershipId) {
		m_membership = membershipId;
	}

	//Destructor
	Publication::~Publication() {
		delete[] m_title;
		m_title = nullptr;
	}
	//Helper Functions

	//Extraction operator overload for read
	istream& operator>>(istream& istr, Publication& src) {
		return src.read(istr);
	}

	//Extraction operator overload for read
	ostream& operator<<(ostream& ostr, const Publication& src){
		if (src.operator const char *() != nullptr) {
			src.write(ostr);
		}
		return ostr;
	}
}