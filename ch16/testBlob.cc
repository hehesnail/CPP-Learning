#include <iostream>
#include "Blob.h"
#include "BlobPtr.h"

using namespace std;

int main() {
	Blob<int> squares = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	for (size_t i = 0; i != squares.size(); i++) {
		squares[i] = i*i;
		cout << squares[i] << " ";
	}
	cout << endl;

	vector<double> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	Blob<double> quad(v.begin(), v.end());
	for (size_t i = 0; i != quad.size(); i++) {
		quad[i] = i*i*i;
		cout << quad[i] << " ";
	}
	cout << endl;

	return 0;
}