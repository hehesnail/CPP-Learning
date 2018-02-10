#ifndef __MYDATE__
#define __MYDATE__

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>

class Date
{
public:
	Date(int y = 1900, int m = 1, int d = 1)
	 :year(y), month(m), day(d){}
	int getY() const {return year;}
	int getM() const {return month;}
	int getD() const {return day;}
	bool operator > (const Date&) const;
	bool operator < (const Date&) const;
	bool operator == (const Date&) const;
	void print() const;

private:
	int year, month, day;
};

inline bool Date::operator > (const Date& d) const
{
	if (this->year == d.getY())
	{
		if (this->month == d.getM())
		{
			return this->day > d.getD();
		}
		return this->month > d.getM();
	}
	else
	{
		return this->year > d.year;
	}
}

inline bool Date::operator < (const Date& d) const
{
	if (this->year == d.getY())
	{
		if (this->month == d.getM())
		{
			return this->day < d.getD();
		}
		return this->month < d.getM();
	}
	else
	{
		return this->year < d.year;
	}
}

inline bool Date::operator == (const Date& d) const
{
	return (this->year == d.getY()) &&
		   (this->month == d.getM()) &&
		   (this->day == d.getD());
}

inline void Date::print() const
{
	std::cout << this->year << '-' << this->month 
				<< '-' << this->day << std::endl;
}

inline std::vector<Date> CreatePoints()
{
	std::vector<Date> temp(10);

	static std::default_random_engine e(time(0));
	static std::uniform_int_distribution<unsigned> y(1900,2018);
	static std::uniform_int_distribution<unsigned> m(1,12);
	static std::uniform_int_distribution<unsigned> d(1,30);

	for (size_t i = 0; i != 10; i++)
	{
		temp[i] = Date(y(e), m(e), d(e));
	}

	return temp;
}

inline bool isless(const Date& d1, const Date& d2)
{
	return d1 < d2;
}

inline void Sort(std::vector<Date>& dv)
{
	std::sort(dv.begin(), dv.end(), isless);
}

#endif