#include <iostream>
#include <string>

using namespace std;

//class Sales_data;
//istream& read(istream&, Sales_data&);

class Sales_data{
public:
	friend istream& read(istream& , Sales_data&);
	Sales_data(string s, unsigned cnt, double price):
			bookNo(s), units_sold(cnt), revenue(price * cnt) {
		cout << "Sales_data constructor 1" << endl;
	}
	Sales_data(): Sales_data("",0 ,0) { 
		cout << "Sales_data constructor 2" << endl;
	}
	explicit Sales_data(string s): Sales_data(s, 0, 0) {
		cout << "Sales_data constructor 3" << endl;
	}
	Sales_data(istream &is): Sales_data() {
		read(is, *this);
		cout << "Sales_data constructor 4" << endl;
	}
	Sales_data& combine(const Sales_data&);

private:
	string bookNo;
	unsigned units_sold;
	double revenue;
};

istream& read(istream& is, Sales_data& item) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	cout << "read" << endl;
	return is;
}

Sales_data& Sales_data::combine(const Sales_data& rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;

	return *this;
}

int main() {
	
	Sales_data s1("parallel", 10, 4.9);
	cout << endl;
	
	Sales_data s2;
	cout << endl;

	Sales_data s3("distributed");
	cout << endl;

	string null_book("9-999-9999");
	Sales_data s5(null_book);
	Sales_data s6("9-999-9999");
	cout << endl;

	Sales_data s4(cin);
	cout << endl;
	//string null_book = "99999";
	//s1.combine(null_book);

	return 0;
}