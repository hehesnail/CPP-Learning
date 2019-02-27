#include <iostream>
#include <memory>

using namespace std;

int main() {
	unique_ptr<int[]> up(new int[10]);
	// up.release();
	// up.reset();

	for (size_t i = 0; i != 10; i++)
		up[i] = i;

	// !Must provide deletor to shared_ptr to manage dynamic array
	shared_ptr<int> sp(new int[10], [] (int* p) {delete[] p;});

	for (size_t i = 0; i != 10; i++)
		*(sp.get() + i) = i;

	int *pa = new int[10];
	delete[] pa;

	return 0;
}