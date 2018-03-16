#include <iostream>
#include "mystring.h"
#include <vector>

using namespace std;

int main() {

	String s1;
	String s2("test");

	s2.print();
	cout << s2.length() << endl;

	s1 = s2;
	s1.print();

	vector<String> svec;
	svec.push_back(s1);
	svec.push_back(s2);
	svec.push_back("god");
	svec.push_back("carmack");

	return 0;
}

