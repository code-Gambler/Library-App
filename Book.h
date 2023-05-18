/* Citation and Sources...
Final Project Milestone 5
Module: Book
Filename: Book.h
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
#ifndef SDDS_BOOK_H
#include<iostream>
#include"Publication.h"
namespace sdds {
	class Book:public Publication
	{
		char* m_authorName;
	public:
		//Default Constructor
		Book();

		//Rule of Three
		
		//Copy Constructor
		Book(const Book& src);

		//Copy Assignment
		Book& operator=(const Book& src);


		//Queries
		
		//Returns the author's name
		const char* authorName()const;

		//Returns the character 'B'
		virtual char type()const;

		//Reads from the console/file.
		std::istream& read(std::istream& istr);

		//Writes to the console/file.
		std::ostream& write(std::ostream& os) const;

		//sets the membership id and resets Date
		virtual void set(int member_id);

		//Returns true if authorname and publication is valid
		operator bool() const;

		//Destructor
		~Book();
	};
}
#endif // !SDDS_BOOK_H