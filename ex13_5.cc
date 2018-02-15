#include <iostream>
#include <string>

using namespace std;

class HasPtr {
public:
	HasPtr(const string &s = string()):
		ps(new string(s)), i(0) { }
	HasPtr(const HasPtr &rhs);
	string getString() const {
		return *ps;
	}
	void changeString(const string &s) {
		*ps = s;
	}
private:
	string *ps;
	int i;
};
HasPtr::HasPtr(const HasPtr &rhs) {
	ps = new string(*(rhs.ps));
	i = rhs.i;
}

int main() {
	HasPtr p1("hello?");
	HasPtr p2 = p1;
	
	cout << "p1: " << p1.getString() << endl;
	cout << "p2: " << p2.getString() << endl;
	cout << "change p2" << endl;
	
	p2.changeString("world");

	cout << "p1: " << p1.getString() << endl;
	cout << "p2: " << p2.getString() << endl;

	return 0;
}