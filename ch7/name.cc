#include <iostream>
#include <string>

using namespace std;

class Screen 
{
public:
	typedef string::size_type pos;
	void dummy_func(pos height) 
	{
		cursor = width * height;
	}
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	//typedef string::size_type pos;
};

typedef string Type;
Type initVal();
class Exercise
{
public:
	typedef double Type;
	Type setVal(Type);
	Type initVal();
private:
	int val;
};

Exercise::Type Exercise::initVal()
{
	return 0;
}

Exercise::Type Exercise::setVal(Exercise::Type parm)
{
	val = parm + initVal();
	return val;
}

int main() 
{

	return 0;
}