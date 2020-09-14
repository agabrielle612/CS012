#include <iostream>
#include <string>

using namespace std;

class Date {
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

 public:
   // creates the date January 1st, 2000.
   Date();


   /* parameterized constructor: month number, day, year 
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message: 

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
   */
   Date(unsigned m, unsigned d, unsigned y);


   /* parameterized constructor: month name, day, year
      - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message: 

       Invalid month name: the Date was set to 1/1/2000.
       (with a newline at the end).
 
       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor. 

       This constructor will recognize both "december" and "December"
       as month name.
   */
   Date(const string &mn, unsigned d, unsigned y);


   /* Outputs to the console (cout) a Date exactly in the format "3/15/2012". 
      Does not output a newline at the end.
   */
   void printNumeric() const;


   /* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end.
   */
   void printAlpha() const;

 private:

   /* Returns true if the year passed in is a leap year, otherwise returns false.
   */
   bool isLeap(unsigned y) const;


   /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter.
   */
   unsigned daysPerMonth(unsigned m, unsigned y) const;

   /* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
   string name(unsigned m) const;

   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
   unsigned number(const string &mn) const;
};


// Implement the Date member functions here
//Constructors
// creates the date January 1st, 2000.
Date::Date() {
   //cout << "Date()" << endl;
   monthName = "January";
   month = number(monthName);
   day = 1;
   year = 2000;
}

/* parameterized constructor: month number, day, year 
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message: 

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
   */
Date::Date(unsigned m, unsigned d, unsigned y) {   
   monthName = name(m);
   month = number(monthName);
   year = y;
   day = d;
   //unsigned tempDay = daysPerMonth(m,y);

   if (m > 12 || m < 1 || d > daysPerMonth(m,y) || d < 1) {
      if (m < 1) {
         month = 1;
      }
      else {
         if (m > 12) {
            month = 12;
         }
      }
      monthName = name(month);
      if (d > daysPerMonth(month, y)){

         day = daysPerMonth(month, y);
      }
      else {
         if (d < 1) {
            day = 1;
         }
      }
      cout << "Invalid date values: Date corrected to " << month << '/' << day <<'/' << year << '.' << endl;
   }
}
   
/* parameterized constructor: month name, day, year
      - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message: 

       Invalid month name: the Date was set to 1/1/2000.
       (with a newline at the end).
 
       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor. 

       This constructor will recognize both "december" and "December"
       as month name.
   */
Date::Date(const string &mn, unsigned d, unsigned y) {
   //cout << "Date(mn,d,y)" << endl;
   month = number(mn);
   monthName = name(month);
   day = d;
   year = y;
   unsigned tempDay = daysPerMonth(month,y);
   //cout << tempDay << endl;

   if (month == 13) {
      month = 1;
      monthName = "January";
      day = 1;
      year = 2000;
      cout << "Invalid month name: the Date was set to 1/1/2000." << endl;
   }

   else if (d < 1 || d > 30) {
      //check if dayspermonth corresponds to user input
      //unsigned tempDay = daysPerMonth(month,y);
      if (d < 1) {
         day = 1;
         cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
      }     
      else if (d > tempDay) {
         day = tempDay;
         cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
      }
   }

   else if (month == 2) {
      if (d > tempDay) {
         day = tempDay;
         cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
      }
   }

}

/* Outputs to the console (cout) a Date exactly in the format "3/15/2012". 
      Does not output a newline at the end.
   */
void Date::printNumeric() const {
   cout << month << "/" << day << "/" << year;
}
   
/* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end.
   */
void Date::printAlpha() const {
   cout << monthName << " " << day << ", " << year;
}

/* Returns true if the year passed in is a leap year, otherwise returns false.
   */
bool Date::isLeap(unsigned y) const {
   if (y % 4 == 0) {
      if (y % 100 == 0) {
         return false;
      }
      if (y % 400 == 0) {
         return true;
      }
      return true;
   }
   else {
      return false;
   }
}

 /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter.
   */
unsigned Date::daysPerMonth(unsigned m, unsigned y) const {
   if (m == 2) {
      if (isLeap(y)) {
         return 29;
      }
      else {
         return 28;
      }
   }
   else if (m == 4 || m == 6 || m == 9 || m == 11) {
      return 30;
   }
   else {
      return 31;
   }
}
/* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
string Date::name(unsigned m) const {
   //cout << "Date::name(m)" << endl;
   if (m == 1) {
      return "January";
   }
   else if (m == 2) {
      return "February";
   }
   else if (m == 3) {
      return "March";
   }
   else if (m == 4) {
      return "April";
   }
   else if (m == 5) {
      return "May";
   }
   else if (m == 6) {
      return "June";
   }
   else if (m == 7) {
      return "July";
   }
   else if (m == 8) {
      return "August";
   }
   else if (m == 9) {
      return "September";
   }
   else if (m == 10) {
      return "October";
   }
   else if (m == 11) {
      return "November";
   }
   else if (m == 12) {
      return "December";
   }
   else {
      return "Invalid";
   }
}

   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
unsigned Date::number(const string &mn) const {
   string t_mn = mn;
   t_mn.at(0) = toupper(mn.at(0));
   
   if (t_mn == "January") {
      return 1;
   }
   else if (t_mn == "February") {
     return 2;
   }
   else if (t_mn == "March") {
      return 3;
   }
   else if (t_mn == "April"){
      return 4;
   }
   else if (t_mn == "May") {
      return 5;
   }
   else if (t_mn == "June") {
     return 6;
   }
   else if (t_mn == "July") {
      return 7;
   }
   else if (t_mn == "August") {
      return 8;
   }
   else if (t_mn == "September") {
      return 9;
   }
   else if (t_mn == "October") {
     return 10;
   }
   else if (t_mn == "November") {
      return 11;
   }
   else if (t_mn == "December") {
     return 12;
   }
   else {
      return 13;  
   }
}

// Don't change the code below this line.
// You may comment them out if you want to build your own test harness
// while in develope mode, but you will need these to pass tests in submit mode.

Date getDate();

int main() {
   
   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;
   
   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}
