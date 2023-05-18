/* Citation and Sources...
Final Project Milestone 5
Module: LibApp
Filename: LibApp.h
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
#ifndef LibApp_H
#define LibApp_H
#include"Menu.h"
#include"Publication.h"
namespace sdds {
	class LibApp {
        char m_fileName[256 + 1]{};
        Publication* m_PPA[SDDS_LIBRARY_CAPACITY]{};
        int m_loadedPub;
        int m_LLRN;
        Menu m_PublicationType = { "Choose the type of publication:" };
		bool m_changed;
		Menu m_mainMenu = {"Seneca Library Application"};
		Menu m_exitMenu = {"Changes have been made to the data, what would you like to do?"};
    public:
        LibApp(const char* filename);

        //Asks the User for confirmation where the question is the passed arg
		bool confirm(const char* message)const;
        void load(const char* filename);  // prints: "Loading Data"<NEWLINE>
        void save();  // prints: "Saving Data"<NEWLINE>
        int search(int mode);  // prints: "Searching for publication"<NEWLINE>

        //Returns the Publication
        void returnPub();  /*  Calls the search() method.
                               prints "Returning publication"<NEWLINE>
                               prints "Publication returned"<NEWLINE>
                               sets m_changed to true;
                           */

        //Adds a new Publiction
        void newPublication();

        //Removes a new Publication
        void removePublication();

        //Checks out a Publication
        void checkOutPub();

        //Driver Function
        void run();

        Publication* getPub(int libRef);

        ~LibApp();
	};
}
#endif // !LibApp_H
