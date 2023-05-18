/* Citation and Sources...
Final Project Milestone 5
Module: Publication
Filename: Publication.h
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
#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H
#include<iostream>
#include"Lib.h"
#include"Date.h"
#include"Streamable.h"
namespace sdds {
	class Publication:public Streamable
	{
		char* m_title;
		char m_shelfId[SDDS_SHELF_ID_LEN + 1];
		int m_membership;
		int m_libRef;
		Date m_date;
	public:
		//Default Constructer
		Publication();

		//Copy Constructer
		Publication(const Publication& obj);

		//Copy Assignment
		virtual Publication& operator=(const Publication& obj);

		//Modifiers

		// Sets the membership attribute to either zero or a five-digit integer.
		virtual void set(int member_id);

		// Sets the **libRef** attribute value
		void setRef(int value);

		// Sets the date to the current date of the system.
		void resetDate();

		//reads from the console/file
		std::istream& read(std::istream& istr);

		//Queries
		
		//Returns the character 'P' to identify this object as a "Publication object"
		virtual char type()const;

		//Returns true is the publication is checkout (membership is non-zero)
		bool onLoan()const;

		//Returns the date attribute
		Date checkoutDate()const;

		//Returns true if the argument title appears anywhere in the title of the 
		//publication. Otherwise, it returns false; (use strstr() function in <cstring>)
		bool operator==(const char* title)const;

		//Returns the title attribute
		operator const char* ()const;

		//Returns the libRef attirbute.
		int getRef()const;

		//Returns If the object is in a valid State or not
		operator bool() const;

		//Returns true if the incoming object is console object
		bool conIO(std::ios& io)const;

		//Returns the shelf Id
		const char* shelfId()const;

		//Returns the membership id
		int membership()const;

		//writes to console/file
		std::ostream& write(std::ostream& os) const;

		void setMembership(int membershipId);

		//Destructor
		~Publication();
	};

	//Helper Functions
	
	//Extraction operator overload for read
	std::istream& operator>>(std::istream& istr, Publication& src);

	//Insertion operator overload for write
	std::ostream& operator<<(std::ostream& ostr, const Publication& src);
}
#endif // !SDDS_PUBLICATION_H



