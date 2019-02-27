#include <iostream>
#include "string.h"

using namespace std;

ostream& operator << (ostream& os, const String& str)
{
	os << str.get_c_str();
	return os;
}

int main()
{
	String s2("hello");
	String s1(s2);
	String s3 = "world";
	s2 = s3;

	cout << s1 << endl;
	cout << s2 << endl;

	return 0;
}