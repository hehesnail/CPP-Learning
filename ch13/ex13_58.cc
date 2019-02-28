#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;
using std::cout;
using std::endl;

class Foo {
public:
	Foo sorted() &&;
	Foo sorted() const &;
private:
	vector<int> data;
};

Foo Foo::sorted() && {
	sort(data.begin(), data.end());

	cout << "&&" << endl;

	return *this;
}

Foo Foo::sorted() const & {
	/*
	Foo ret(*this);
	sort(ret.data.begin(), ret.data.end());
	*/
	
	//Foo ret(*this);
	//ret.sorted();

	cout << "const &" << endl;

	return Foo(*this).sorted();
}

int main() {

	Foo().sorted();

	Foo f;
	f.sorted();

	return 0;
}
