#ifndef __DATE__H
#define __DATE__H

#include <iostream>
using namespace std;

class Date
{
protected:
	int day;
	int month;
	int year;

public:
	Date();
	Date(int day, int month, int year);
	Date(const Date& other);
	Date(Date&& other) noexcept;
	~Date();

	const Date& operator=(const Date& other);
	const Date& operator=(Date&& other) noexcept;

	int getDay() const { return day; }
	int getMonth() const { return month; }
	int getYear() const { return year; }

	char* createDateString(const Date* pDate);
	int equalDate(const Date* pDate1, const Date* pDate2);

	friend ostream& operator<<(ostream& os, const Date& date);
	bool       operator==(const Date& other);
	bool       operator>(const Date& other);
};

#endif // !__DATE__H



