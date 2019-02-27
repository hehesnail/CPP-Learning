#include <iostream>
#include <vector>
#include <list>
#include <forward_list>

using namespace std;

int main() {

	/*ex 9.31*/
	list<int> l1 = {0,1,2,3,4,5,6,7,8,9};
	auto iter = l1.begin();

	while (iter != l1.end()) {
		if (*iter % 2) {
			iter = l1.insert(iter, *iter);
			iter++;
			iter++;
		} else {
			iter = l1.erase(iter);
		}
	}

	for (auto iter = l1.begin(); iter != l1.end(); iter++) {
		cout << *iter << " ";
	}

	cout << endl;

	/*ex_9.32*/
	vector<int> v1 = {0,1,2,3,4,5,6,7,8,9};
	auto iter1 = v1.begin();

	while (iter1 != v1.end()) {
		if (*iter1 % 2) {
			iter1 = v1.insert(iter1, *iter1++);
			iter1++;
		} else {
			iter1 = v1.erase(iter1);
		}
	}

	for (auto iter1 = v1.begin(); iter1 != v1.end(); iter1++) {
		cout << *iter1 << " ";
	}

	cout << endl;

	/*ex_9.34*/
	// forever loop for odd number 
	vector<int> v2 = {0,1,2,3,4,5,6,7,8,9};
	auto iter2 = v2.begin();
	while(iter2 != v2.end()) {
		if (*iter2 % 2) {
			iter2 = v2.insert(iter2, *iter2);
		}

		++iter2;
	}

	return 0;
}