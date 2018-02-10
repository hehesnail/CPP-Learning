//This program test when derived class inherit
//from a base class and has a compostion part
//which constructor will be called first
//which deconstructor will be called first

/*
	Test Result:
	构造由内向外，base->component->derived clas
	析构由外向内，derived class->component->base
*/

#include <iostream>

using namespace std;

class comp
{
public:
	comp() {cout << "component construct" <<endl;}
	~comp() {cout << "component deconstruct" << endl;}
};

class base
{
public:
	base() {cout << "base construct" <<endl;}
	virtual ~base() 
	{
		cout << "base deconstruct" << endl;
	}
};

class derived: public base
{
public:
	derived(){ cout << "derived construct" << endl;}
	~derived() {cout << "derived deconstruct" << endl;}
private:
	comp c;
};

int main()
{
	derived d;

	return 0;
}