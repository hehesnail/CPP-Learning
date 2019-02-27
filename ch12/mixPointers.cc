#include <iostream>
#include <memory>
#include <string>

using namespace std;

void process(shared_ptr<int> ptr) {
	//pass
	cout << ptr.use_count() << endl;
}

int main() {

	/*
	shared_ptr<int> p(new int(42));
	//process(shared_ptr<int> (p));
	process(p);
	cout << p.use_count() << endl;
	*/

	shared_ptr<int> p(new int(42));
	process(shared_ptr<int>(p.get()));
	cout << p.use_count() << endl;
	cout << "p " << *p << endl;

	auto pp = new int();
	auto sp = make_shared<int> ();
	cout << "pp " << *pp << endl;
	cout << "sp " << *sp << endl;
	//! illegal, can't convert normal pointer to smart pointer
	//process(pp);
	//process(new int());
	process(sp);
	process(shared_ptr<int>(pp));
	cout << "sp " << *sp << endl;
	cout << "pp " << *pp << endl;

	auto sp1 = make_shared<int> (42);
	cout << "sp1 " << *sp1 << endl;
	auto p1 = sp1.get();
	delete p1;
	cout << "sp1 " << *sp1 << endl;
	cout << sp1.use_count() << endl;

	return 0;
}