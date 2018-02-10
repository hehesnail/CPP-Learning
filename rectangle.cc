#include <iostream>
#include "rectangle.h"

using namespace std;

ostream& operator << (ostream& os, const Rectangle& r)
{
	os << "No:" << r.getNo() << endl;
	os << "(Width, Height):" << r.getW() << ',' << r.getH() << endl;
	os << "(x, y):" << r.getPoi()->getX() << ',' << r.getPoi()->getY() << endl;
}

int main()
{
	Rectangle r1(2,3,0,0,1);
	cout << "r1\n" << r1;
	Rectangle r2(r1);
	cout << "r2\n" << r2;
	Rectangle r3(3,4, 100, 100, 2);
	cout << "r3\n" << r3;
	r2 = r3;
	cout << "r2\n" << r3;
	r2 = r2;
	cout << "r2\n" << r2;

	return 0;
}