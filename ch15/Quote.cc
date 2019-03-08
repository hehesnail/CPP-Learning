#include <iostream>
#include <string>

using namespace std;

class Quote{
	friend bool operator!=(const Quote&, const Quote&);
public:
	Quote() {
		cout << "Quote default" << endl;
	}
	Quote(const string& s, double p): bookNo(s), price(p) {
		cout << "Quote constructor using 2 parameters" << endl;
	}

	Quote(const Quote& q): bookNo(q.bookNo), price(q.price) {
		cout << "Quote copy constructor" << endl;
	}

	Quote& operator=(const Quote &rhs) {
		if (*this != rhs) {
			this->bookNo = rhs.bookNo;
			this->price = rhs.price;
		}

		cout << "Quote copy assignment" << endl;
		return *this;
	}

	Quote(Quote&& q) noexcept : bookNo(std::move(q.bookNo)), price(std::move(q.price)) { 
		cout << "Quote move constructor" << endl;
	}

	Quote& operator=(Quote &&rhs) {
		if (*this != rhs) {
			this->bookNo = std::move(rhs.bookNo);
			this->price = std::move(rhs.price);
		}
		cout << "Quote move assignment" << endl;

		return *this;
	}

	string isbn() const { return bookNo; }
	virtual double net_price(size_t n) const {
		return n*price;
	}

	virtual void debug() const {
		cout << "BookNo: " << bookNo << " price: " << price << endl;
	}

	virtual ~Quote() {
		cout << "Quote deconstructor" << endl;
	}

private:
	string bookNo;
protected:
	double price=0.0;
};

inline
bool operator!=(const Quote &lhs, const Quote &rhs) {
	return !(lhs.bookNo == rhs.bookNo && lhs.price == rhs.price);
}

class DiscQuote: public Quote {
public:
	DiscQuote() {
		cout << "Disc default" << endl;
	}
	DiscQuote(const string &s, double p, size_t q, double dis):
			Quote(s, p), quntatity(q), discount(dis) {
		cout << "Disc two paramters" << endl;
	}
	virtual double net_price(size_t) const = 0;
	virtual void debug() const = 0;
protected:
	size_t quntatity = 0;
	double discount = 0.0;
};

class BulkQuote: public DiscQuote {
public:
	BulkQuote() {
		cout << "BulkQuote default" << endl;
	}
	BulkQuote(const string &s, double p, size_t mq, double dis):
			DiscQuote(s, p, mq, dis){ 
		cout << "BulkQuote two paramters" << endl;
	}
	BulkQuote(const BulkQuote& bq): DiscQuote(bq) {
		cout << "BulkQuote copy constructor" << endl;
	}

	BulkQuote& operator=(const BulkQuote& rhs) {
		DiscQuote::operator=(rhs);
		cout << "BulkQuote copy assignment" << endl;
		return *this;
	}

	BulkQuote(BulkQuote &&bq) noexcept : DiscQuote(std::move(bq)) {
		cout << "BulkQuote move constructor" << endl;
	}

	BulkQuote& operator=(BulkQuote &&rhs) {
		DiscQuote::operator=(rhs);
		cout << "BulkQuote move assignment" << endl;
		return *this;
	}

	double net_price(size_t n) const override;
	void debug() const override;
};

double BulkQuote::net_price(size_t n) const {
	if (n < quntatity)
		return price * n;
	return price * (1 - discount) * n;
}

void BulkQuote::debug() const {
	Quote::debug();
	cout << "min_qty: " << quntatity << " discount: " << discount << endl;
}

double print_all(ostream &os, const Quote &item, size_t n) {
	double ret = item.net_price(n);

	os << "ISBN: " << item.isbn() << " Sold: " << ret << endl;
	return ret;
}

int main() {
	Quote q("fuck", 20);
	cout << endl;

	BulkQuote bq("training", 20, 10, 0.2);
	cout << endl;

	BulkQuote bq1 = bq;
	cout << endl;

	BulkQuote bq2 = std::move(bq);
	cout << endl;

	BulkQuote bq3;
	cout << endl;
	
	bq3 = bq1;

	return 0;
}