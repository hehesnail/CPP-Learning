#include <iostream>
#include <memory>

using namespace std;

int main() {
	
	// !12.16
	// unique_ptr<int> p1(new int(42));
	// unique_ptr<int> p2 = p1;
	// unique_ptr<int> p2(p1);
	// p1 = nullptr;

	int ix = 1024, *pi = &ix, *pi2 = new int(2048);
	typedef unique_ptr<int> IntP;

	//! error, can't assign int to unique_ptr<int>
	//  IntP p0(ix);
	
	//! Ok, assign int* to unique_ptr<int>
	IntP p1(pi);

	//! Ok, assing int* to unique_ptr<int>
	IntP p2(pi2); 

	//! Ok, unique_ptr<int> p3 points to ix
	//  one unique_ptr<int> points can only point to one object. 
	IntP p3(&ix);

	//! Ok
	IntP p4(new int(2048));

	//! OK
	IntP p5(p2.get());

	return 0;
}