#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main() {

	size_t n = 10;
	allocator<string> alloc;
	auto const p = alloc.allocate(n);
	string s;
	auto q = p;

	while (cin >> s && q != p + n) {
		alloc.construct(q++, s);
	}

	for (auto i = p; i != q; i++) {
		cout << *i << " ";
	}
	cout << endl;

	const size_t size = q - p;
	alloc.destroy(p);
	alloc.deallocate(p, n);

	return 0;
}