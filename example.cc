#include <iostream>
#include <vector>

using namespace std;

class Example {
public:
	static constexpr double rate = 6.5;
	static const int vecsize = 20;
	static vector<double> vec;
};

constexpr double Example::rate;
vector<double> Example::vec(vecsize);

int main() {

	return 0;
}