#include <iostream>
#include "strBlob.h"
#include <string>
#include <fstream> 

using namespace std;

int main() {
	ifstream ifs("test.txt");

	StrBlob blob;
	string temp;

	while (getline(ifs, temp))
		blob.push_back(temp);

	for (StrBlobPtr pbeg(blob.begin()), pend(blob.end()); pbeg != pend; pbeg.incr())
		cout << pbeg.deref() << endl;

	return 0;
}