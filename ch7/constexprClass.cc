#include <iostream>

using namespace std;

class Debug {
public:
	constexpr Debug (bool b = true):hw(b), io(b), other(b) { }
	constexpr Debug (bool h, bool i, bool o): 
					hw(h), io(i), other(o) { }
	constexpr bool any() { return hw || io || other; }
	void set_hw(bool b) { hw = b; }
	void set_io(bool b) { io = b; }
	void set_other(bool b) { other = b;}
private:
	bool hw;
	bool io;
	bool other;
};

int main() {

	constexpr Debug io_sub (false, true, true);
	if (io_sub.any()) {
		cout << "error" << endl;
	}
	constexpr Debug prod(false);
	if (prod.any()) {
		cout << "error" << endl;
	}
	Debug s;
	s.set_hw(false);

	return 0;
}