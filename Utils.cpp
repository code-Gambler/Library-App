/* Citation and Sources...
Final Project Milestone 5
Module: Utils
Filename: Utils.h
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
/***********************************************************************
// OOP244 Utils Module:
// File  utils.cpp
// Version 1.0
// Date 23/07/2022
// Author Steven David Pillay
// Description Utils Module
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Utils.h"
using namespace std;
namespace sdds {
    //Checks if the passed argument string is a number
    bool isNumber(const string& str)
    {
        bool returnValue = true;
        for (char const& c : str) {
            if (isdigit(c) == 0) {
                returnValue = false;
            }
        }
        return returnValue;
    }
}