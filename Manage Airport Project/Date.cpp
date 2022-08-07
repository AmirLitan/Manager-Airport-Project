#include "Date.h"
#include <time.h>

Date::Date()
{
	this->day = 0;
	this->month = 0;
	this->year = 0000;
}

Date::Date(int day, int month, int year) 
{
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::Date(const Date& other)
{
	this->day = other.day;
	this->month = other.month;
	this->year = other.year;
}

Date::Date(Date&& other) noexcept
{
	this->day = other.day;
	this->month = other.month;
	this->year = other.year;

	other.day = 0;
	other.month = 0;
	other.year = 0;
}

Date::~Date() 
{
}

const Date& Date::operator=(const Date& other)
{
	this->day = other.day;
	this->month = other.month;
	this->year = other.year;
	return *this;
}

const Date& Date::operator=(Date&& other) noexcept
{
	if (this != &other) 
	{
		this->day = other.day;
		this->month = other.month;
		this->year = other.year;

		other.day = 0;
		other.month = 0;
		other.year = 0;
	}
	return *this;
}

char* Date::createDateString(const Date* pDate) 
{
	char date[12];
	/*
	struct tm* day;
	struct tm* month;
	struct tm* year;
	day->tm_mday = this->day;
	month->tm_mon = this->month;
	year->tm_year = this->year;

	strftime(date, 12, "%d", day);
	*/
	return date;
}

int Date::equalDate(const Date* pDate1, const Date* pDate2)
{
	if ((pDate1->day == pDate2->day)	 &&
		(pDate1->month == pDate2->month) &&
		(pDate1->year == pDate2->year))
	{
		return 1;
	}
	return 0;
}

ostream& operator<<(ostream& os, const Date& date)
{
	os << "Date: " << date.day << "/" << date.month << "/" << date.year << endl;
	return os;
}

bool Date::operator==(const Date& other) 
{
	return equalDate(this, &other);
}
bool Date::operator>(const Date& other) 
{
	bool isBiger = true;
	if (this->year < other.year)
	{
		isBiger = false;
	}
	else if (this->month < other.month)
	{
		isBiger = false;
	}
	else if (this->day < other.day)
	{
		isBiger = false;
	}
	return isBiger;
}