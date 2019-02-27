#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
class NoDefault {
public:
	//NoDefault() = default;
	NoDefault(const string& s1): s(s1) { }
private:
	string s;
	int a1;
	double b2;
};

struct A {
	NoDefault my_mem;
};

struct B {
	B() { }
	NoDefault b_mem;
};
*/

class NoDefault {
public:
	NoDefault(int a): c(a) { }
private:
	int c;
	//double b;
};

class C {
public:
	C (): c_mem(NoDefault(5)) { }
private:
	NoDefault c_mem;
};


class Test {
public:
	Test() = default;
	Test(int i): a(i) { }
private:
	int a;
	double b;
};

int main() {

	//A a;
	Test T;
	//vector<NoDefault> vec(10);
	vector<C> vec(10);


	return 0;
}