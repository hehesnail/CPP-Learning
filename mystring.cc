#include <iostream>
#include "mystring.h"

using namespace std;

int main() {

	String s1;
	String s2("test");

	s2.print();
	cout << s2.length() << endl;

	s1 = s2;
	s1.print();

	return 0;
}