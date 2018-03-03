#include <iostream>
#include <string>

using namespace std;

class HasPtr {
public:
	HasPtr(const string &s = string()):
		ps(new string(s)), i(0), use(new size_t(1)) { }
	HasPtr(const HasPtr &p):
		ps(p.ps), i(p.i), use(p.use) { ++*use; }
	HasPtr& operator= (const HasPtr&);
	const string& getString()const { return *ps; }
	void setString(const string& s) { *ps = s; }
	~HasPtr();
private:
	string *ps;
	int i;
	size_t *use;
};

HasPtr& HasPtr::operator= (const HasPtr &rhs) {
	++*rhs.use;
	if (--*use == 0) {
		delete ps;
		delete use;
	}
	ps = rhs.ps;
	i = rhs.i;
	use = rhs.use;

	return *this;
}

HasPtr::~HasPtr() {
	if (--*use == 0) {
		delete ps;
		delete use;
	}
}

int main() {

	HasPtr p1 = string("hello");
	HasPtr p2("world");

	cout << p1.getString() << " " << p2.getString() << endl;

	HasPtr p3(p2);
	cout << p3.getString() << endl;

	p1 = p2;
	cout << p1.getString() << " " << p2.getString() << endl;
	p3.setString("Ops....");
	cout << p1.getString() << " " << p2.getString() << " " << p3.getString() << endl;

	return 0;
}