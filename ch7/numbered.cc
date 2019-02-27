// !ex13.14, ex13.15, ex13.16
#include <iostream>

using namespace std;

class Numbered {
public:
	Numbered() {
		mysn = unique++;
	}
	Numbered(const Numbered& n) {
		mysn = unique++;
	}

	static int unique;
	int mysn;
};

int Numbered::unique = 10;

void f(const Numbered& s) {
	cout << s.mysn << endl;
}

// !ex13.14 10,10,10
// !ex13.15 13,14,15
// !ex13.16 10,11,12

int main() {
	
	Numbered a, b = a, c = b;
	f(a);
	f(b);
	f(c);

	return 0;
}