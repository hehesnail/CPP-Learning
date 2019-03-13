#include <iostream>
#include "Blob.h"
#include "BlobPtr.h"

using namespace std;

int main() {
	Blob<int> squares = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	for (size_t i = 0; i != squares.size(); i++) {
		squares[i] = i*i;
		cout << squares[i] << endl;
	}

	return 0;
}