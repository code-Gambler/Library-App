/* Citation and Sources...
Final Project Milestone 5
Module: BookTester
Filename: BookTester.cpp
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
//#include <iostream>
//#include <fstream>
//#include "Publication.h"
//#include "Book.h"
//#include "Utils.h"
//using namespace std;
//using namespace sdds;
//int main() {
//   Book bk;
//   cout << ">" << bk << "<" << endl;
//   ofstream fileout("Books.txt",ios::app);
//   cout << "Enter the Book infomation to be added to the file:" << endl;
//   cin >> bk;
//   cout << bk << endl;
//   if (bk) {
//      cout << "added to the file" << endl;
//      fileout << bk << endl;
//   }
//   fileout.close();
//   cout << endl << "Contents of the file:" << endl;
//   ifstream filein("Books.txt");
//   char pType{};
//   for (int row = 1; filein; row++) {
//      filein >> pType;
//      if (pType != 'B') {
//         cout << "The Record type signature is supposed to be B, but it is: " << pType << endl;
//         filein.setstate(ios::failbit);
//      }
//      filein.ignore();
//      filein >> bk;
//      filein.ignore(1000, '\n');
//      if (filein) {
//         cout << "| ";
//         cout.width(4);
//         cout.fill(' ');
//         cout.setf(ios::right);
//         cout << row << " ";
//         cout.unsetf(ios::right);
//         cout << bk << endl;
//      }
//   }
//   return 0;
//}