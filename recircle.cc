#include <iostream>
#include "recircle.h"

using namespace std;

int main()
{
	Shape* s[20] = {nullptr};

	CreateShapes(s);

	for (int i = 0; s[i] != nullptr; i++)
	{
		s[i]->print();
		delete s[i];
	}

	return 0;
}