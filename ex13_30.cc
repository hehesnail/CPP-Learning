#include <iostream>
#include <string>

using namespace std;

class HasPtr {
public:
	friend void swap(HasPtr&, HasPtr&);
	HasPtr(const string &s = string()):
		ps(new string(s)), i(0) { }
	HasPtr(const HasPtr&);
	HasPtr& operator=(const HasPtr&);
	HasPtr& operator=(HasPtr);
	string getString() const {
		return *ps;
	}
	void changeString(const string &s) {
		*ps = s;
	}
	~HasPtr() {delete ps;}
private:
	string *ps;
	int i;
};

HasPtr::HasPtr(const HasPtr &rhs) {
	ps = new string(*(rhs.ps));
	i = rhs.i;
}

HasPtr& 
HasPtr::operator=(const HasPtr &rhs) {
	// !Avoid self assign
	if (this->ps == rhs.ps)
		return *this;
	delete ps;
	ps = new string(*(rhs.ps));
	i = rhs.i;
	return *this;
}

inline
HasPtr& HasPtr::operator=(HasPtr rhs) {
	swap(*this, rhs);
	return *this;
}

inline
void swap(HasPtr &lhs, HasPtr &rhs) {

	cout << "swaping" << endl;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}

int main() {
	HasPtr p1("hello?");
	HasPtr p2("Yes!");
	
	cout << "p1: " << p1.getString() << endl;
	cout << "p2: " << p2.getString() << endl;

	swap(p1, p2);
	cout << "p1: " << p1.getString() << endl;
	cout << "p2: " << p2.getString() << endl;

	return 0;
}