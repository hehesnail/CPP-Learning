#include <iostream>
#include <string>
#include <functional>
#include <algorithm>

using namespace std;

int main() {
	auto data = {2,3,4,5};
	int input;
	cin >> input;
	modulus<int> mod;
	auto predictor = [&](int i) {return 0 == mod(input, i);};
	auto is_divisible = any_of(data.begin(), data.end(), predictor);
	cout << (is_divisible ? "Yes" : "No") << endl;

	return 0;
}