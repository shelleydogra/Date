/*
*   Class       -       Date Data Type
*	Description -		The plus (+) and the minus (-) operator have been overloaded in the Date class and used to add 
						number of days (int) to a given date in the object created by the constructor and the new date
						is displayed in several examples...

*/

#include <iostream>
#include "Date.h"
#include <cstdlib>


using std::cout;
using std::cin;

 Date::Date ()												// constructor definition
{
   month = day = year = 1;
}

Date::Date (int mo, int da, int yr)
{
  
	month = mo;
	day = da;
	year = yr;
    
}

void Date::display()
{
   static char *name[] = {"nothing", "January", "February", "March", "April",
						  "May", "June", "July", "August", "September", "October",
                          "November", "December" };

    cout <<  name[month] << ' ' << day << ", " << year << '\n';
   
}

Date::~Date()
{
  
}



int Date::GetMonth()
{
   return month;
}

void Date::SetMonth(int mo)
{
   month = mo;
}

int Date::GetDay()
{
   return day;
}

void Date::SetDay(int da)
{
   day = da;
}

int Date::GetYear()
{
   return year;
}

void Date::SetYear(int yr)
{
  year = yr;
}

void Date::setDate(int mo, int da, int yr) {
    year = yr;
    day  = da;
    month = mo;
}

/*
*	Check if the year is a leap year or not; takes in (int) year to check and returns a bool..
*/
bool Date:: leapYear(int year)
{
	return (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0));
}

/*
*	Plus (+) Operator overload to add days (int) to a data type of 
*	(class) Date.  While keeping track of the leap year and the right output
*	Returns the new calculated date by adding the days to original date.
*/

Date Date :: operator+ (int daysIn)
{
	static const int month_days [] = {0,31, 28, 31, 30, 31, 30 , 31, 31 , 30, 31, 30, 31};	//Max number of days in each month

	static const int leap_days  [] = {0,31, 29, 31, 30, 31, 30 , 31, 31 , 30, 31, 30, 31};	//Max days per month in leap years
	
	for (int i = 0; i < daysIn; i++)							//	for loop where daysIn is the amount of days to by added
	{															
		this->day++;											//	day incremented by one before more checking
		 
		if (!leapYear(this->year))								//	if block for only when not a leap year
		{
			if (this->day > month_days[this->month])			//	It uses a non-leap year array to check if the day after it was
			{													//	incremented bigger than the max days for the current month.
				this->day = 1;									//	if it was day is reset to the 1st of the month... and
				this->month++;									//	the month is incremented
			}
		
			if (this->month > 12)								//	After the month is incremented this is the check to see if it's
			{													//	bigger than 12 months...
				this->month = 1;								//	..and if it is reset the month to 1 (Jan) and 
				this->year++;									//	increment the year
			}
		}
		else													//	if block for when it is a leap year
		{
			if (this->day > leap_days[this->month])				//	It uses leap year array to check if the day after it was
			{													//	incremented bigger than the max days for the current month.
				this->day = 1;									//	if it was day is reset to the 1st of the month... and
				this->month++;									//	the month is incremented
			}
		
			if (this->month > 12)								//	After the month is incremented this is the check to see if it's
			{													//	bigger than 12 months...
				this->month = 1;								//	..and if it is reset the month to 1 (Jan) and 
				this->year++;									//	increment the year
			}
		}
	}

	return *this;												//	returns the new date
}


/*
*	Minus (-) Operator overload to subtract days (int) to a data type of 
*	(class) Date.  While keeping track of the leap year and the right output
*	Returns the new calculated date by subtracting the days from original date.
*/

Date Date :: operator- (int daysIn)
{
	const int month_days [] = {31, 31, 28, 31, 30, 31, 30 , 31, 31 , 30, 31, 30, 31};	//Max number of days in each month

	const int leap_days []  = {31, 31, 29, 31, 30, 31, 30 , 31, 31 , 30, 31, 30, 31};	//Max days per month in leap years
	
	Date date;													//	object date created using the default constructor

	for (int i = 0; i < daysIn; i++)							//	for loop where daysIn is the amount of days to by subtracted
	{ 
		this->day--;											//	day decremented by 1 before more checking

		if (!leapYear(this->year))								//	if block for only when NOT a leap year
		{
			if(this->day < 1)									//	if the day is < 1 (0) then the date need to be reset  
			{													//	day is reset to the max days of the previous month 
				this->day = month_days[this->month - 1];		//	(if it's in month_days[1] it goes to [0] which has been set 
				this->month--;									//	to 31 to imitate december)
			}													

			if(this->month < 1)									//	If the month is <= 1 then the month is reset to 12 and the 
			{													//	year is decremented
				this->month = 12;
				this->year--;
			}
		
		}
		else													//	if block for when it is a leap year
		{
			if(this->day < 1)									//	It uses leap year array to check if the day after it was
			{													//	decrement smaller than the 1st of the current month.
				this->day = leap_days[this->month - 1];			//	if it was day is reset max day of the previous month... and
				this->month--;									//	the month is decremented
			}

			if(this->month < 1)									//	After the month is decremented this is the check to see if it's
			{													//	smaller than one or equal...
				this->month = 12;								//	..and if it is reset the month to 12 and
				this->year--;									//	decrements the year
			}													//	(if it's in month_days[1] it goes to [0] which has been set 
		}														//	to 31 to imitate december)
	
	}

	date.day = this->day;
	date.month = this->month;
	date.year = this->year;

	return date;												//	returns the date object...
}


bool intValidated(int intToBeValidated, int rangeBegin, int rangeEnd);

Date dateInput();


int main()
{
	
    cout << "\n\tDemonstration of plus (+) and minus (-) overloaded operators.\n\n";
   

//   Date xmas (12, 25, 2012);													//	object instantiated with constructor that takes in (mm, dd, yyyy)
//   cout << "\n\tOriginal date: \t";			        xmas.display();				//	display original 
//   cout << "\n\t\tAdding 15 days : \t";      (xmas + 15).display();				//	adds or subracts form the object and displays the new date.
//   cout << endl;
//
//   Date feb29 (2, 29, 2012);
//   cout << "\n\tOriginal date: \t";			      feb29.display();				//	object instantiated with constructor that takes in (mm, dd, yyyy)
//   cout << "\n\t\tSubtracting 1 day : \t";	(feb29 - 1).display();				//	display original
//   cout << endl;																//	adds or subracts form the object and displays the new date.
//
//   Date mar1 (3, 1, 2013);														//	object instantiated with constructor that takes in (mm, dd, yyyy)
//   cout << "\n\tOriginal date: \t";			        mar1.display();				//	display original
//   cout << "\n\t\tSubtracting 1 day : \t";	  (mar1 - 1).display();				//	adds or subracts form the object and displays the new date.
//   cout << endl;
//
//   Date ind (7, 4, 2013);														//	object instantiated with constructor that takes in (mm, dd, yyyy)
//   cout << "\n\tOriginal date: \t";			            ind.display();			//	display original
//   cout << "\n\t\tSubtracting 365 day : \t";	(ind - 365).display();			//	adds or subracts form the object and displays the new date.
//   cout << endl;
//
//   Date dec5 (12, 5, 2013);														//	object instantiated with constructor that takes in (mm, dd, yyyy)
//   cout << "\n\tOriginal date: \t";			           dec5.display();			//	display original
//   cout << "\n\t\tSubtracting 366 days : \t";	(dec5 - 366).display();			//	adds or subracts form the object and displays the new date.
//   cout << endl;
//
//   Date newyr (1, 1, 2014);														//	object instantiated with constructor that takes in (mm, dd, yyyy)
//   cout << "\n\tOriginal date: \t";			        newyr.display();			//	display original
//   cout << "\n\t\tAdding 31 days : \t";	     (newyr + 31).display();			//	adds or subracts form the object and displays the new date.
//   cout << endl;
//   
    Date dob;
    int year  = 0;
    int month = 0;
    int day   = 0;

    
    cout << "Enter dob year: ";
    cin  >> year;
    cout << "Enter dob month: ";
    cin  >> month;
    cout << "Enter dob day: ";
    cin  >> day;
    
    while (!intValidated(year, 1900, 2020)) {
        cout << "Invalid Entry, Please try again!\n";
        cout << "Enter dob YEAR (ex. 2012): ";
        cin  >> year;
    }

    while (!intValidated(month, 1, 12)) {
        cout << "Invalid Entry, Please try again!\n";
        cout << "Enter dob Month (ex. 12 for December): ";
        cin  >> month;
    }
    
    while (!intValidated(day, 1, 31)) {
        cout << "Invalid Entry, Please try again!\n";
        cout << "Enter dob DAY (1-31): ";
        cin  >> day;
    }
    
    dob.setDate(month, day, year);
    
    dob.display();
    
    
    
    

   cout << "\n\n\n\n";
   return 0;
}

bool intValidated(int intToBeValidated, int rangeBegin, int rangeEnd) {
  
    return (intToBeValidated >= rangeBegin && intToBeValidated <= rangeEnd);
}

Date dateInput() {
    Date date;
    
    return date;
}
