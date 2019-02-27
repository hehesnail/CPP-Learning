#include <iostream>
#include <vector>

using namespace std;

class Component
{
	int value;
public:
	Component(int val = 0): value(val) {}
	virtual void add(Component*) {}
};

class Primitive:public Component
{
public:
	Primitive(int val): Component(val) {}
};

class Composite:public Component
{
	vector<Component*> c;
public:
	Composite(int val): Component(val) {}
	virtual void add(Component* elem)
	{
		c.push_back(elem);
	}
};

int main()
{

	return 0;
}