#include "date.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<Date> test = CreatePoints();
	
	cout << "Before Sorting" << endl;
	for (auto i = test.begin(); i != test.end(); i++)
	{
		(*i).print();
	}

	Sort(test);
	cout << "After Sorting" << endl;
	for (auto i = test.begin(); i != test.end(); i++)
	{
		(*i).print();
	}

	return 0;
}