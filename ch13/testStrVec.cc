#include <iostream>
#include <fstream>
#include <string>
#include "StrVec.h"

//#define _GLIBCXX_USE_CXX11_ABI 0

using namespace std;

int main() {

	StrVec v1;
	string s;

	fstream f("test.txt");
	while (f >> s)
		v1.push_back(s);

	cout << v1.size() << endl;

	v1.resize(300, "s");
	cout << v1.size() << endl;

	v1.resize(100);
	cout << v1.size() << endl;

	StrVec v2 = {"1", "2", "3"};
	//StrVec v3 = v2;

	cout << v2.size() << endl;

	return 0;
}