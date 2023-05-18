/* Citation and Sources...
Final Project Milestone 5
Module: Date
Filename: Date.cpp
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
// File  Date.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
#include<string>
#include"Utils.h"
#include "Date.h"
using namespace std;
namespace sdds {
    bool sdds_test = false;
    int sdds_year = 2022;
    int sdds_mon = 8;
    int sdds_day = 7;

   int Date::daysSince0001_1_1()const { // Rata Die day since 0001/01/01
      int ty = m_year;
      int tm = m_mon;
      if (tm < 3) {
         ty--;
         tm += 12;
      }
      return 365 * ty + ty / 4 - ty / 100 + ty / 400 + (153 * tm - 457) / 5 + m_day - 306;
   }

   bool Date::validate() {
      errCode(NO_ERROR);
      if (m_year < MIN_YEAR || m_year > m_CUR_YEAR + 1) {
         errCode(YEAR_ERROR);
      }
      else if (m_mon < 1 || m_mon > 12) {
         errCode(MON_ERROR);
      }
      else if (m_day < 1 || m_day > mdays()) {
         errCode(DAY_ERROR);
      }
      return !bad();
   }

   void Date::errCode(int readErrorCode) {
      m_ErrorCode = readErrorCode;
   }

   int Date::systemYear()const {
      int theYear = sdds_year;
      if (!sdds_test) {
         time_t t = time(NULL);
         tm lt = *localtime(&t);
         theYear = lt.tm_year + 1900;
      }
      return theYear;
   }

   bool Date::bad()const {
      return m_ErrorCode != 0;
   }

   int Date::mdays()const {
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
      int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
      mon--;
      return days[mon] + int((mon == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
   }


   void Date::setToToday() {
       if (sdds_test) {
           m_day = sdds_day;
           m_mon = sdds_mon;
           m_year = sdds_year;
       }
       else {
           time_t t = time(NULL);
           tm lt = *localtime(&t);
           m_day = lt.tm_mday;
           m_mon = lt.tm_mon + 1;
           m_year = lt.tm_year + 1900;
       }
       errCode(NO_ERROR);
   }


   Date::Date() :m_CUR_YEAR(systemYear()) {
      setToToday();
   }
   Date::Date(int year, int mon, int day) : m_CUR_YEAR(systemYear()) {
      m_year = year;
      m_mon = mon;
      m_day = day;
      validate();
   }

   int Date::errCode()const {
      return m_ErrorCode;
   }

   const char* Date::dateStatus()const {
      return DATE_ERROR[errCode()];
   }
   int Date::currentYear()const {
      return m_CUR_YEAR;
   }
   
   //Writes the date to the console/file
   std::ostream& Date::write(std::ostream& os) const
   {
       if (!bad()) {
           os << m_year << "/";
           os.fill('0');
           os.width(2);
           os << m_mon << "/";
           os.width(2);
           os << m_day;
           os.fill(' ');
           return os;
       }
       else {
           os << dateStatus();
           return os;
       }
   }
   
   //Comparison Operators
   bool Date::operator==(const Date& rightOperand)const
   {
       bool returnValue = false;
       if (daysSince0001_1_1() == rightOperand.daysSince0001_1_1())
       {
           returnValue = true;
       }
       return returnValue;
   }
   bool Date::operator!=(const Date& rightOperand)const
   {
       bool returnValue = false;
       if (daysSince0001_1_1() != rightOperand.daysSince0001_1_1())
       {
           returnValue = true;
       }
       return returnValue;
   }
   bool Date::operator>=(const Date& rightOperand)const
   {
       bool returnValue = false;
       if (daysSince0001_1_1() >= rightOperand.daysSince0001_1_1())
       {
           returnValue = true;
       }
       return returnValue;
   }
   bool Date::operator<=(const Date& rightOperand)const
   {
       bool returnValue = false;
       if (daysSince0001_1_1() <= rightOperand.daysSince0001_1_1())
       {
           returnValue = true;
       }
       return returnValue;
   }
   bool Date::operator<(const Date& rightOperand)const
   {
       bool returnValue = false;
       if (daysSince0001_1_1() < rightOperand.daysSince0001_1_1())
       {
           returnValue = true;
       }
       return returnValue;
   }
   bool Date::operator>(const Date& rightOperand)const
   {
       bool returnValue = false;
       if (daysSince0001_1_1() > rightOperand.daysSince0001_1_1())
       {
           returnValue = true;
       }
       return returnValue;
   }
   
   //Calculates the days between two dates
   int Date::operator-(const Date& rightOperand)const
   {
       return daysSince0001_1_1() - rightOperand.daysSince0001_1_1();
   }
   
   //Return true if date is valid
   Date::operator bool()const
   {
       return (!bad());
   }

   //Returns the year
   int Date::year() const
   {
       return m_year;
   }

   //Returns the month
   int Date::mon() const
   {
       return m_mon;
   }

   //Returns the day
   int Date::day() const
   {
       return m_day;
   }

   //Returns the Error Code
   int Date::ErrorCode() const
   {
       return m_ErrorCode;
   }

   //Returns the Current Year
   int Date::CUR_YEAR() const
   {
       return m_CUR_YEAR;
   }

   //Resets the date to today
   void Date::resetDate()
   {
       setToToday();
   }

   //Reads from the console/file.
   std::istream& Date::read(std::istream& is)
   {
       int day = 0;
       int month = 0;
       int year = 0;
       char delimiter;
       m_ErrorCode = NO_ERROR;
       is >> year >> delimiter >> month >> delimiter >> day;
       if (is.fail()) {
           m_ErrorCode = CIN_FAILED;
           is.clear();
           is.ignore(1000, '\n');
       }else{
           m_day = day;
           m_mon = month;
           m_year = year;
           validate();
       }
       return is;
   }

   //Copy Assignment
   Date& Date::operator=(const Date& rightOperand)
   {
       m_CUR_YEAR = rightOperand.CUR_YEAR();
       m_day = rightOperand.day();
       m_ErrorCode = rightOperand.ErrorCode();
       m_mon = rightOperand.mon();
       m_year = rightOperand.year();
       return *this;
   }

   int Date::calculateDays() const{
       return daysSince0001_1_1();
   }

   //Helper Functions

   //Insertion operator overoad for write function.
   ostream& operator<<(ostream& os, const Date& RO) {
      return RO.write(os);
   }

   //Insertion operator overoad for read function.
   istream& operator>>(istream& is, Date& RO) {
      return RO.read(is);
   }
}
