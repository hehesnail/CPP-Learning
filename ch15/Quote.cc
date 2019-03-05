#include <iostream>
#include <string>

using namespace std;

class Quote{
public:
	Quote()=default;
	Quote(const string& s, double p): bookNo(s), price(p) { }
	string isbn() const { return bookNo; }
	virtual double net_price(size_t n) const {
		return n*price;
	}

	virtual ~Quote()=default;

private:
	string bookNo;
protected:
	double price=0.0;
};

class BulkQuote: public Quote {
public:
	BulkQuote()=default;
	BulkQuote(const string &s, double p, size_t mq, double dis):
			Quote(s, p), min_qty(mq), discount(dis) { }
	double net_price(size_t n) const override;

private:
	size_t min_qty = 0;
	double discount = 0.0;
};

double BulkQuote::net_price(size_t n) const {
	if (n < min_qty)
		return price * n;
	return price * (1 - discount) * n;
}

double print_all(ostream &os, const Quote &item, size_t n) {
	double ret = item.net_price(n);

	os << "ISBN: " << item.isbn() << " Sold: " << ret << endl;
	return ret;
}

int main() {
	Quote q("fuck", 20);
	BulkQuote q1("training", 20, 10, 0.2);

	print_all(cout, q, 100);
	print_all(cout, q1, 30);

	return 0;
}