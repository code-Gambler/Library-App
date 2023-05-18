/* Citation and Sources...
Final Project Milestone 5
Module: Menu & MenuItem
Filename: Menu.cpp
Version 1.1
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
#include<iostream>
#include<ctype.h>
#include<string>
#include<string.h>
#include"Menu.h"
#include"Utils.h"
using namespace std;
namespace sdds {
	//MenuItem module
	MenuItem::MenuItem(const char* cstring)
	{
		if (cstring != nullptr) {
			m_content = new char[strlen(cstring)];
			strcpy(m_content, cstring);
		}
		else {
			m_content = nullptr;
		}
	}
	std::ostream& MenuItem::display(std::ostream& ostr)const
	{
		if (operator bool()) {
			ostr << m_content;
		}
		return ostr;
	}
	MenuItem::operator bool()const
	{
		bool returnValue = true;
		if (m_content == nullptr) {
			returnValue = false;
		}
		return returnValue;
	}
	MenuItem::operator const char* ()const
	{
		return m_content;
	}

	MenuItem::~MenuItem()
	{
		delete[] m_content;
	}

	//Menu Module
	Menu::Menu(const char* title)
	{
		if (title != nullptr) {
			strcpy(m_title, title);
		}
		else {
			strcpy(m_title, "");
		}
		m_dynObjects = 0;
	}
	ostream& Menu::displaytitle(ostream& ostr)const
	{
		if (m_title) {
			ostr << m_title;
		}
		return ostr;
	}
	ostream& Menu::display(ostream& ostr)const
	{
		int i;
		if (!(m_title[0] == '\0')) {
			displaytitle() << endl;
		}
		for (i = 0; i < m_dynObjects; i++) {
			ostr.width(2);
			ostr.setf(ios::right);
			ostr << i + 1; 
			ostr.unsetf(ios::right);
			ostr << "- ";
			m_menu[i].display(ostr) << endl;
		}
		ostr << " 0- Exit" << endl;
		ostr << "> ";
		return ostr;
	}

	Menu::operator unsigned int()const
	{
		return m_dynObjects;
	}

	Menu::operator int()const
	{
		return m_dynObjects;
	}

	Menu::operator bool()const
	{
		bool returnValue = false;
		if (m_dynObjects >= 1) {
			returnValue = true;
		}
		return returnValue;
	}

	const char* Menu::operator[](const int index) const
	{
		return m_menu[index % m_dynObjects].operator const char*();
	}

	unsigned int Menu::run()
	{
		char selection[10 + 1];
		int value;
		bool invalid;
		display();
		do {
			invalid = false;
				cin >> selection;
			if (isNumber(selection)) {
				value = stoi(selection);
				if ((value > m_dynObjects) || (value < 0)) {
					cout << "Invalid Selection, try again: ";
					invalid = true;
					cin.clear();
					cin.ignore(1000, '\n');
				}
			}
			else{
				cout << "Invalid Selection, try again: ";
				invalid = true;
				cin.clear();
				cin.ignore(1000, '\n');
			}
		} while (invalid);
		strcpy(selection, "");
		return value;
	}

	unsigned int Menu::operator~()
	{
		return run();
	}

	Menu& Menu::operator<<(const char* menuitemContent)
	{
		if (m_dynObjects < MAX_MENU_ITEMS) {
			m_menu[m_dynObjects].m_content = new char[strlen(menuitemContent)+1];
			strcpy(m_menu[m_dynObjects].m_content, menuitemContent);
			m_dynObjects++;
		}
		return *this;
	}

	//Helper Function
	ostream& operator<<(ostream& ostr, const Menu& menu)
	{
		menu.displaytitle();
		return ostr;
	}
}