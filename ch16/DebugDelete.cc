#include <iostream>
#include <memory>

using namespace std;

class DebugDelete {
public:
	DebugDelete(ostream& s = cerr): os(s) { }
	template <typename T> void operator() (T *p) const{
		os << "deleting unique_ptr" << endl;
		delete p;
	}
private:
	ostream &os;
};

int main() {
	double *p = new double;
	DebugDelete d;
	d(p);

	int *ip = new int;
	DebugDelete() (ip);

	unique_ptr<string, DebugDelete> sp(new string, DebugDelete());

	return  0;
}