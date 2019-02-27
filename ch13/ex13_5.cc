// !ex13.5, ex13.8, ex13.11
#include <iostream>
#include <string>

using namespace std;

class HasPtr {
public:
	HasPtr(const string &s = string()):
		ps(new string(s)), i(0) { }
	HasPtr(const HasPtr&);
	HasPtr& operator=(const HasPtr&);
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

int main() {
	HasPtr p1("hello?");
	HasPtr p2 = p1;
	HasPtr p3("No!");
	
	cout << "p1: " << p1.getString() << endl;
	cout << "p2: " << p2.getString() << endl;
	cout << "change p2" << endl;
	
	p2.changeString("world");

	cout << "p1: " << p1.getString() << endl;
	cout << "p2: " << p2.getString() << endl;

	p2 = p3;
	cout << "p3: " << p3.getString() << endl;
	cout << "p2: " << p2.getString() << endl;
	cout << "change p2" << endl;
	p2.changeString("Yes!");
	cout << "p3: " << p3.getString() << endl;
	cout << "p2: " << p2.getString() << endl;

	return 0;
}