/* Citation and Sources...
Final Project Milestone 5
Module: LibApp
Filename: LibApp.cpp
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
#include<iostream>
#include<fstream>
#include <cstring>
#include "LibApp.h"
#include"Streamable.h"
#include"Menu.h"
#include"Publication.h"
#include"PublicationSelector.h"
#include"Book.h"
#include"Date.h"

using namespace std;
namespace sdds {
    char typeOf;
    LibApp::LibApp(const char* filename)
    {
        strcpy(m_fileName, filename);
        m_loadedPub = 0;
        m_LLRN = 0;
        m_changed = false;
        m_loadedPub = 0;
        m_PublicationType << "Book" << "Publication";
        m_mainMenu << "Add New Publication"
            << "Remove Publication"
            << "Checkout publication from library"
            << "Return publication to library";
        m_exitMenu << "Save changes and exit"
            << "Cancel and go back to the main menu";
        load(filename);
    }

    //Asks the User for confirmation where the question is the passed arg
    bool LibApp::confirm(const char* message)const //use this
    {
        bool returnValue = false;
        Menu tempQues(message);
        tempQues << "Yes";
        if (tempQues.run() == 1) {
            returnValue = true;
        }
        return returnValue;
    }

    // Loads the datafiles.
    void LibApp::load(const char* filename)
    {
        char type = 0;
        cout << "Loading Data" << endl;
        ifstream fileread;
        fileread.open(filename);
        while (fileread >> type) {
            fileread.ignore();
            if (type == 'P') {
                m_PPA[m_loadedPub] = new Publication;
            }
            else if (type == 'B') {
                m_PPA[m_loadedPub] = new Book;
            }
            fileread >> *m_PPA[m_loadedPub];
            m_loadedPub++;
        }
        fileread.close();
        m_LLRN = m_PPA[m_loadedPub-1]->getRef();
    }

    // Saves the data
    void LibApp::save()
    {
        int i;
        cout << "Saving Data" << endl;
        ofstream  filewrite(m_fileName);
        for (i=0;i<m_loadedPub;i++) {
            if (m_PPA[i]->getRef()) {
                filewrite << *m_PPA[i] << endl;
            }
        }
        filewrite.close();
    }

    // Searchs for records
    int LibApp::search(int mode)
    {
        int returningRef = 0;
        int i;
        PublicationSelector results;
        char searchTitle[256 + 1] = {""};
        switch (m_PublicationType.run()) {
        case 1:
            typeOf = 'B';
            break;
        case 2:
            typeOf = 'P';
            break;
        }
        cout << "Publication Title: ";
        cin.ignore(1000, '\n');
        cin.getline(searchTitle, 256, '\n');
        for (i = 0; i < m_loadedPub; i++) {
            if (*m_PPA[i] == searchTitle && m_PPA[i]->type() == typeOf) {
                if (mode == 0) {
                    results << m_PPA[i];
                }
                else if (mode == 1 && m_PPA[i]->membership() != 0) {
                    results << m_PPA[i];
                }
                else if (mode == 2 && m_PPA[i]->membership() == 0) {
                    results << m_PPA[i];
                }
            }
        }

        if (!results.noOfPubs()) {
            cout << "No matches found!" << endl;
            returningRef = -1;
        }
        else {
            cout << "Select one of the following found matches:" << endl;
            results.sort();
            returningRef = results.run();
            cout << *getPub(returningRef) << endl;
        }
        return returningRef;
    }

    //Returns the Publication
    void LibApp::returnPub()
    {
        Date today{};
        double penalty = 0;
        int days = 0;
        int libReference = 0;
        cout << "Return publication to the library" << endl;
        libReference = search(1);
        if (libReference != -1 && libReference != 0) {
            if (confirm("Return Publication?")) {
                days = today.calculateDays() - getPub(libReference)->checkoutDate().calculateDays();
                if (days > 15) {
                    penalty = (days - 15) * 0.5;
                    cout << "Please pay $";
                    cout.setf(ios::fixed);
                    cout.precision(2);
                    cout << penalty << " penalty for being " << days - 15 << " days late!" << endl;
                }
                getPub(libReference)->setMembership(0);
                if (typeOf == 'B') {
                    getPub(libReference)->resetDate();
                }
                m_changed = true;
                cout << "Publication returned" << endl;
            }
            else {
                cout << "Aborted!" << endl;
            }
        }
    }

    //Adds a new Publiction
    void LibApp::newPublication(){
        bool abort = false;
        Publication* temp = nullptr;
        if (m_loadedPub == SDDS_LIBRARY_CAPACITY) {
            cout << "Library is at its maximum capacity!" << endl;
        }
        else {
            cout << "Adding new publication to the library" << endl;
            switch (m_PublicationType.run()) {
            case 1:
                delete temp;
                temp = new Book;
                break;
            case 2:
                delete temp;
                temp = new Publication;
                break;
            case 0:
                abort = true;
                cout << "Aborted!" << endl;
            }
            if (!abort) {
                cin >> *temp;
                m_LLRN++;
                temp->setRef(m_LLRN);
                if (!(cin.fail())) {
                    if (confirm("Add this publication to the library?")) {
                        m_PPA[m_loadedPub] = temp;
                        m_loadedPub++;
                        m_changed = true;
                        cout << "Publication added" << endl;
                    }
                    else {
                        abort = true;
                    }
                }
                else {
                    cout << "Aborted!";
                    m_LLRN--;
                    delete temp;
                }
                if (!(getPub(m_LLRN)->operator bool()) && !abort) {
                    cout << "Failed to add publication!";
                    m_LLRN--;
                    m_loadedPub--;
                    delete m_PPA[m_loadedPub];
                }
            }
        }
    }

    //Removes a new Publication
    void LibApp::removePublication()
    {
        int libreference = 0;
        cout << "Removing publication from the library" << endl;
        libreference = search(0);
        if (libreference != -1 && libreference != 0) {
            if (confirm("Remove this publication from the library?")) {
                m_changed = true;
                getPub(libreference)->setRef(0);
                cout << "Publication removed" << endl;
            }
            else if (libreference) {
                cout << "Aborted!" << endl;
            }
        }
        else {
            cout << "Aborted!" << endl;
        }
    }

    //Checks out a Publication
    void LibApp::checkOutPub()
    {
        bool invalid;
        int libReferece = 0;
        int membershipId;
        cout << "Checkout publication from the library" << endl;
        libReferece = search(2);
        if (libReferece != -1 && libReferece != 0) {
            if (confirm("Check out publication?")) {
                cout << "Enter Membership number: ";
                do {
                    invalid = false;
                    cin >> membershipId;
                    if (membershipId < 9999) {
                        invalid = true;
                        cout << "Invalid membership number, try again: ";
                    }
                } while (invalid);
                getPub(libReferece)->setMembership(membershipId);
                m_changed = true;
                cout << "Publication checked out" << endl;
            }
        }
        else {
            cout << "Aborted!" << endl;
        }
    }

    //Driver Function
    void LibApp::run()
    {
        bool done = true;
        do {
            switch (m_mainMenu.run()) {
            case 1:
                newPublication();
                break;
            case 2:
                removePublication();
                break;
            case 3:
                checkOutPub();
                break;
            case 4:
                returnPub();
                break;
            case 0:
                if (m_changed) {
                    switch (m_exitMenu.run()) {
                    case 1:
                        done = false;
                        save();
                        break;
                    case 2:
                        break;
                    case 0:
                        if (confirm("This will discard all the changes are you sure?")) {
                            done = false;
                        }
                    }
                }
                else {
                    done = false;
                }
            }
            cout << endl;
        } while (done);

        cout << "-------------------------------------------" << endl
            << "Thanks for using Seneca Library Application" << endl;
    }

    //Gets the publication reference using library reference
    Publication* LibApp::getPub(int libRef)
    {
        int i;
        Publication* returnObjAdd = nullptr;
        for (i = 0; i < m_loadedPub; i++) {
            if (m_PPA[i]->getRef() == libRef) {
                returnObjAdd = m_PPA[i];
            }
        }
        return returnObjAdd;
    }

    //Destructer
    LibApp::~LibApp()
    {
        int i;
        for (i = 0; i < (m_loadedPub); i++) {
            delete m_PPA[i];
        }
    }
}

