#include <iostream>
#include "complex.h"

using namespace std;

ostream& operator << (ostream& os, const complex& r)
{
	os << '(' << r.real() << ',' << r.imag() << ')';
}

int main()
{
	complex c1(2, 1);
  	complex c2(4, 0);

  	cout << c1 << endl;
  	cout << c2 << endl;
  
 	cout << c1+c2 << endl;
 	/ /cout << c1-c2 << endl;

  
  	cout << (c1 += c2) << endl;
  	cout << (c1 == c2) << endl;
  	//cout << (c1 != c2) << endl;
  	cout << +c2 << endl;
  	cout << -c2 << endl;
  
  	//cout << (c2 - 2) << endl;
  	cout << (5 + c2) << endl;

	return 0;
}