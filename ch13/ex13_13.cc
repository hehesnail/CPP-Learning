#include <iostream>
#include <vector>

using namespace std;

struct X {
	X() { cout << "X()" << endl; }
	X(const X& x) { cout << "X(const X&)" << endl; }
	X& operator=(const X& x) { cout << "operator=" << endl; }
	~X() { cout << "~X()" << endl; }
};

X& foo1(X& x)
{
	return x;
}
X foo2(X x)
{
	return x;
}

int main() {
	X x1;
	X x2 = x1;
	X x3;
	x3 = x2;
	cout << endl;
	vector<X> v1 = {x1, x2, x3};
	cout << endl;
	foo1(x1);
	cout << endl;
	foo2(x2);

	return 0;
}