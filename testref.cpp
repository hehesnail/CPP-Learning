#include <iostream>

using namespace std;

int main(){
	int i = 0, &r1 = i;
	double d = 0, &r2 = d;
	r2 = 3.14; //OK
	r2 = r1; //ok
	i = r2; //ok
	r1 = d; //ok

	cout << i << endl;
	cout << r1 << endl;
	cout << d << endl;
	cout << r2 << endl;

	int *p = nullptr;

	return 0;
}