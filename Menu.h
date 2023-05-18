/* Citation and Sources...
Final Project Milestone 5
Module: Menu & MenuItem
Filename: Menu.h
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
#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include<iostream>
namespace sdds {
	//MenuItem
	class MenuItem {
	private:
		char* m_content;
		MenuItem(const MenuItem& obj) = delete;
		MenuItem& operator=(const MenuItem& obj) = delete;
		MenuItem(const char* cstring = nullptr);
		std::ostream& display(std::ostream& ostr = std::cout)const;
		operator bool()const;
		operator const char* ()const;
		~MenuItem();
		friend class Menu;
	};

	//Menu
	const int MAX_MENU_ITEMS = 20;
	class Menu {
		char m_title[128 + 1]{};
		MenuItem m_menu[MAX_MENU_ITEMS]	;
		int m_dynObjects{};
		Menu(const Menu& obj) = delete;
		Menu& operator=(const Menu& obj) = delete;
	public:
		Menu(const char* title = nullptr);
		std::ostream& displaytitle(std::ostream& ostr = std::cout)const;
		std::ostream& display(std::ostream& ostr = std::cout)const;
		operator unsigned int()const;
		operator int()const;
		operator bool()const;
		const char* operator[](const int index)const;
		unsigned int run();
		unsigned int operator~();
		Menu& operator<<(const char* menuitemConent);
	};

	//Helper Operator
	std::ostream& operator<<(std::ostream& ostr, const Menu& menu);
}
#endif // !SDDS_MENU_H

