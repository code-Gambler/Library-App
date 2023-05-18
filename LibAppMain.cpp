/* Citation and Sources...
Final Project Milestone 5
Module: Main
Filename: LibAppMain.cpp
Version 1.0
Author	Steven David Pillay
Revision History
-----------------------------------------------------------
Date      Reason
2022/08/07  First Submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*///// Final Project Milestone 5
//// LipApp Main
//// Version 1.0
//// Author	Fardad Soleimanloo
//// Revision History
//// -----------------------------------------------------------
//// Name               Date                 Reason
///////////////////////////////////////////////////////////////////
//
//#include "LibApp.h"
//#include "Date.h"
//int main() {
//   sdds::sdds_day = 10;
//   sdds::sdds_mon = 12;
//   sdds::sdds_year = 2021;
//   sdds::sdds_test = true;
//   sdds::LibApp theApp("LibRecs.txt");
//   theApp.run();
//   return 0;
//}
#include <iostream>
#include <fstream>
#include "LibApp.h"
#include "Date.h"
void runLibApp(const char* filename) {
    char ch{};
    sdds::LibApp theApp(filename);
    theApp.run();
    std::ifstream file(filename);
    while (file) {
        if (file.get(ch)) std::cout << ch;
    }
}
int main() {
    sdds::sdds_day = 10;
    sdds::sdds_mon = 8;
    sdds::sdds_year = 2022;
    sdds::sdds_test = true;
    runLibApp("LibRecsSmall.txt");
    return 0;
}
