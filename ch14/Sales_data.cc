#include "Sales_data.h"

Sales_data::Sales_data(std::istream &is): Sales_data() {
	is >> *this;
}

Sales_data& Sales_data::operator+= (const Sales_data &rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;

	return *this;
}

Sales_data& Sales_data::operator= (const string &s) {
	*this = Sales_data(s);
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Sales_data &item) {
	os << item.isbn() << " " << item.units_sold << " "
	   << item.revenue << " " << item.avg_price();
	return os;
}

std::istream& operator>>(std::istream& is, const Sales_data &item) {
	double price;
	is >> item.bookNo >> item.units_sold >> price;
	if (is)
		item.revenue = price * item.units_sold;
	else 
		item = Sales_data();

	return is;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data sum = lhs;
	sum += rhs;

	return sum;
}

bool operator==(const Sales_data &lhs, const Sales_data &rhs) {
	return (lhs.bookNo == rhs.bookNo) && (lhs.units_sold == rhs.units_sold) && (lhs.revenue == rhs.revenue);
}

bool operator!=(const Sales_data &lhs, const Sales_data &rhs) {
	return !(lhs == rhs);
}