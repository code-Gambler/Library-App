/* Citation and Sources...
Final Project Milestone 5
Module: Date
Filename: Date.h
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
// Final Project Milestone 1
// Date Module
// File  Date.h
// Version 1.0
// Author   Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#ifndef SDDS_DATE_H_
#define SDDS_DATE_H_
#include <iostream>
namespace sdds {
   const int NO_ERROR = 0;
   const int CIN_FAILED = 1;
   const int YEAR_ERROR = 2;
   const int MON_ERROR = 3;
   const int  DAY_ERROR = 4;
   const char DATE_ERROR[5][16] = {
      "No Error",
      "cin Failed",
      "Bad Year Value",
      "Bad Month Value",
      "Bad Day Value"
   };
   const int  MIN_YEAR = 1500;
   class Date {
   private:
      int m_year;
      int m_mon;
      int m_day;
      int m_ErrorCode;
      int m_CUR_YEAR;
      int daysSince0001_1_1()const; // returns number of days passed since the date 0001/1/1

      bool validate();             /* validates the date setting the error code and then returning the result
                                    true, if valid, and false if invalid.*/

      void errCode(int);           // sets the error code

      int systemYear()const;       // returns the current system year

      bool bad()const;             // return true if

      int mdays()const;            // returns the number of days in current month

      void setToToday();           // sets the date to the current date (system date)
   public:
      Date();                      // creates a date with current date

      Date(int year, int mon, int day); /* create a date with assigned values
                                         then validates the date and sets the
                                         error code accordingly */

      int errCode()const;         // returns the error code or zero if date is valid

      const char* dateStatus()const;  // returns a string corresponding the current status of the date

      int currentYear()const;         // returns the m_CUR_YEAR value;

      //Queries
      
      //Writes the date to the console/file
      std::ostream& write(std::ostream& os = std::cout)const;

      //Comparison Operators
      bool operator==(const Date& rightOperand)const;
      bool operator!=(const Date& rightOperand)const;
      bool operator>=(const Date& rightOperand)const;
      bool operator<=(const Date& rightOperand)const;
      bool operator<(const Date& rightOperand)const;
      bool operator>(const Date& rightOperand)const;

      //Calculates the days between two dates
      int operator-(const Date& rightOperand)const;

      //Return true if date is valid
      operator bool()const;

      //Returns the year
      int year()const;

      //Returns the month
      int mon()const;

      //Returns the day
      int day()const;

      //Returns the Error Code
      int ErrorCode()const;

      //Returns the Current Year
      int CUR_YEAR()const;

      //Resets the date to today
      void resetDate();

      //Reads from the console/file.
      std::istream& read(std::istream& is = std::cin);

      //Copy Assignment
      Date& operator=(const Date& rightOperand);

      int calculateDays()const;

   };

   //Helper Operators

   //Insertion operator overoad for write function.
   std::ostream& operator<<(std::ostream& os, const Date& RO);

   //Insertion operator overoad for read function.
   std::istream& operator>>(std::istream& is, Date& RO);

   extern bool sdds_test;
   extern int sdds_year;
   extern int sdds_mon;
   extern int sdds_day;
}
#endif