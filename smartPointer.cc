#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

int main() {

	shared_ptr<int> p3 = make_shared<int> (42);
	shared_ptr<string> p4 = make_shared<string> (10, '9');
    auto p6 = make_shared<vector<string>> ();
    auto p = make_shared<int> (42);
    auto q(p);
    auto r = make_shared<int> (42);
    r =

	return 0;
}