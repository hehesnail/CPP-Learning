#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class HasPtr {
public:
	friend void swap(HasPtr&, HasPtr&);
	HasPtr(const string &s = string()):
		ps(new string(s)), i(0) { cout << "call constructor" << endl;}
	HasPtr(const HasPtr&);
	HasPtr(HasPtr &&p) noexcept;
	//HasPtr& operator=(const HasPtr&);
	HasPtr& operator=(HasPtr);
	bool operator<(const HasPtr&);
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
	cout << "call copy constructor" << endl;
}

HasPtr::HasPtr(HasPtr &&p) noexcept
	:ps(p.ps), i(p.i) {
	p.ps = nullptr;
	cout << "call move constructor" << endl;
}

/*
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
*/

inline
HasPtr& HasPtr::operator=(HasPtr rhs) {
	swap(*this, rhs);
	return *this;
}


inline 
bool HasPtr::operator<(const HasPtr& rhs) {
	return *ps < *(rhs.ps);
}

inline
void swap(HasPtr &lhs, HasPtr &rhs) {

	cout << "swaping" << endl;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}

int main() {

	/*
	HasPtr p1("hello?");
	HasPtr p2("yes!");
	
	cout << "p1: " << p1.getString() << endl;
	cout << "p2: " << p2.getString() << endl;

	swap(p1, p2);
	cout << "p1: " << p1.getString() << endl;
	cout << "p2: " << p2.getString() << endl;

	vector<HasPtr> pv;
	pv.push_back(p1);
	pv.push_back(p2);

	for (int i = 10; i > 0; i--) {
		string s = "test" + to_string(i);
		pv.push_back(s);
	}

	sort(pv.begin(), pv.end());

	for (auto i = pv.begin(); i != pv.end(); i++) {
		cout << i->getString() << endl;
	}
	*/

	HasPtr hp1("hello"), hp2("world"), *pH = new HasPtr("Wrokd");
	hp1 = hp2;
	hp1 = std::move(*pH);

	return 0;
}